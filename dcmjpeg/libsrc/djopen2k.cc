#ifdef DCMTK_DEFAULT_INTEGRATION_CLASS

#include "dcmtk/config/integration.h"

// most stuff here comes from OPJSupport.cpp in the Horos project
//  Created by Aaron Boxer on 21 Jan 2014
//  Updated by Alex Bettarini on 17 Feb 2015
// but possibly it's based on the original OsiriX OpenJPEG encoder/decoder: https://github.com/aglv/OsiriX/commit/eab564773535f52c7811c9edbef789360351ae8c

// opj_stream additions by https://github.com/nikkoara, see https://github.com/uclouvain/openjpeg/pull/583/files

//#define WITH_OPJ_BUFFER_STREAM
#define WITH_OPJ_FILE_STREAM

#include "openjp2/openjpeg.h"

#include "dcmtk/dcmdata/dcerror.h"

#include <Accelerate/Accelerate.h>

// from OpenJPEG/src/bin/jp2/opj_decompress.c
#define JP2_RFC3745_MAGIC "\x00\x00\x00\x0c\x6a\x50\x20\x20\x0d\x0a\x87\x0a"
#define JP2_MAGIC "\x0d\x0a\x87\x0a"
/* position 45: "\xff\x52" */
#define J2K_CODESTREAM_MAGIC "\xff\x4f\xff\x51"

//extern void OPJ_CALLCONV opj_destroy_cstr_index(opj_codestream_index_t **p_cstr_index);

namespace djopen2k {

    OPJ_API opj_stream_t * OPJ_CALLCONV opj_stream_create_buffer_stream(OPJ_BYTE *data, OPJ_SIZE_T len, OPJ_BOOL input);
    
    class opj_decode_info {
    public:
        opj_codec_t *codec = NULL;
        opj_stream_t *stream = NULL;
        opj_image_t *image = NULL;
        opj_codestream_info_v2_t* cstr_info = NULL;
        opj_codestream_index_t* cstr_index = NULL;
        OPJ_BOOL deleteImage = OPJ_FALSE;
        
        opj_decode_info() {}
        virtual ~opj_decode_info() {
            if (codec)
                opj_destroy_codec(codec);
            if (stream)
                opj_stream_destroy(stream);
            if (image)
                opj_image_destroy(image);
            if (cstr_index)
                opj_destroy_cstr_index(&cstr_index);
        }
    };
    
    static void error_callback(const char *msg, const char **client_data) {
        *client_data = msg;
    }
    
    static const char *clr_space(OPJ_COLOR_SPACE i)
    {
        if(i == OPJ_CLRSPC_SRGB) return "OPJ_CLRSPC_SRGB";
        if(i == OPJ_CLRSPC_GRAY) return "OPJ_CLRSPC_GRAY";
        if(i == OPJ_CLRSPC_SYCC) return "OPJ_CLRSPC_SYCC";
        if(i == OPJ_CLRSPC_UNKNOWN) return "OPJ_CLRSPC_UNKNOWN";
        return "CLRSPC_UNDEFINED";
    }
    
    static void findMinMax(char *bytes, long length, OFBool isSigned, int rows, int columns, int bitsPerSample, double &min, double &max);
    template<typename T> void rawtoimage_fill(T *inputbuffer, int w, int h, int numcomps, opj_image_t *image, int pc);
    static opj_image_t* rawtoimage(char *inputbuffer, opj_cparameters_t *parameters,
                            int fragment_size, int image_width, int image_height, int sample_pixel,
                                   int bitsallocated, int bitsstored, int sign, /*int quality,*/ int pc);

    
}

OFCondition DcmIntegrationDefault::decodeJ2K(void *j2kData, Uint32 j2kDataSize,
                                             void *&rawData, Uint32 &rawDataSize,
                                             OFBool expectSignedRawData, EP_Interpretation &inter)
{
    //decoderMutex.lock();
    
    int i;
    int width, height;
    OPJ_BOOL hasAlpha, fails = OPJ_FALSE;
    unsigned char rc, gc, bc, ac;
    
    if (j2kDataSize<12) {
        //decoderMutex.unlock();
        return EC_IllegalCall;
    }
    
    /*-----------------------------------------------*/
    
    djopen2k::opj_decode_info decodeInfo;
    
    opj_dparameters_t parameters;
    opj_set_default_decoder_parameters(&parameters);
    
    // from infile_format() in OpenJPEG/src/bin/jp2/opj_decompress.c
    if (memcmp(j2kData, JP2_RFC3745_MAGIC, 12) == 0 || memcmp(j2kData, JP2_MAGIC, 4) == 0)
        parameters.decod_format = 1; // JP2
    else if (memcmp(j2kData, J2K_CODESTREAM_MAGIC, 4) == 0)
        parameters.decod_format = 0; // J2K
    else return EC_InvalidStream;
    
    decodeInfo.stream = djopen2k::opj_stream_create_buffer_stream((OPJ_BYTE *)j2kData, (OPJ_SIZE_T)j2kDataSize, OPJ_STREAM_READ);
    if (!decodeInfo.stream)
        return EC_InvalidStream;
    
    /*-----------------------------------------------*/
    
    OPJ_CODEC_FORMAT codec_format;
    switch (parameters.decod_format) {
        case 0: // JPEG-2000 codestream
            codec_format = OPJ_CODEC_J2K;
            break;
        case 1: // JP2 file format
            codec_format = OPJ_CODEC_JP2;
            break;
//        case 2: // JPT-stream (JPEG 2000, JPIP) is only identified in infile_format() by the 'jpt' file extension, but we don't have any file names anywhere
//            codec_format = OPJ_CODEC_JPT;
//            break;
        default:
            return EC_InvalidStream;
    }
    
    /*-----------------------------------------------*/
    
    while (1) {
        int user_changed_tile=0, user_changed_reduction=0;
        int max_tiles=0, max_reduction=0;
        fails = OPJ_TRUE;
        
        decodeInfo.codec = opj_create_decompress(codec_format);
        if (decodeInfo.codec == NULL)
        {
            fprintf(stderr,"%s:%d:\n\tNO codec\n",__FILE__,__LINE__);
            break;
        }
        
        char *decodeInfoCodecError = NULL;
        opj_set_error_handler(decodeInfo.codec, (opj_msg_callback)djopen2k::error_callback, &decodeInfoCodecError);
//#ifdef OPJ_VERBOSE
//        opj_set_info_handler(decodeInfo.codec, info_callback, this);
//        opj_set_warning_handler(decodeInfo.codec, warning_callback, this);
//#endif
        
        // Setup the decoder decoding parameters
        if (!opj_setup_decoder(decodeInfo.codec, &parameters))
        {
            fprintf(stderr,"%s:%d:\n\topj_setup_decoder failed\n",__FILE__,__LINE__);
            break;
        }
        
        if (user_changed_tile && user_changed_reduction)
        {
            int reduction=0;
            opj_set_decoded_resolution_factor(decodeInfo.codec, reduction);
        }
        
        /* Read the main header of the codestream and if necessary the JP2 boxes
         * see openjpeg.c
         * For OPJ_CODEC_JP2 it will call 'opj_jp2_read_header()' in jp2.c:2276
         * then call 'opj_j2k_read_header()'
         */
        if( !opj_read_header(decodeInfo.stream, decodeInfo.codec, &(decodeInfo.image)))
        {
            fprintf(stderr,"%s:%d:\n\topj_read_header failed\n",__FILE__,__LINE__);
            break;
        }
        
        if ( !(user_changed_tile && user_changed_reduction)
            || (max_tiles <= 0) || (max_reduction <= 0) )
        {
            decodeInfo.cstr_info = opj_get_cstr_info(decodeInfo.codec);
            
            max_reduction = decodeInfo.cstr_info->m_default_tile_info.tccp_info->numresolutions;
            max_tiles = decodeInfo.cstr_info->tw * decodeInfo.cstr_info->th;
            
            decodeInfo.cstr_index = opj_get_cstr_index(decodeInfo.codec);
        }
        
        if (!parameters.nb_tile_to_decode)
        {
            int user_changed_area=0;
            
            if(user_changed_area)
            {
                
            }
            
            /* Optional if you want decode the entire image */
            if (!opj_set_decode_area(decodeInfo.codec, decodeInfo.image,
                                     (OPJ_INT32)parameters.DA_x0,
                                     (OPJ_INT32)parameters.DA_y0,
                                     (OPJ_INT32)parameters.DA_x1,
                                     (OPJ_INT32)parameters.DA_y1)) {
                fprintf(stderr,"%s:%d:\n\topj_set_decode_area failed\n",__FILE__,__LINE__);
                break;
            }
            
            /* Get the decoded image */
            if (!opj_decode(decodeInfo.codec, decodeInfo.stream, decodeInfo.image)) {
                fprintf(stderr,"%s:%d:\n\topj_decode failed\n",__FILE__,__LINE__);
                
                //decoderMutex.unlock();
                
                break;
            }
            
            if (!opj_end_decompress(decodeInfo.codec, decodeInfo.stream)) {
                fprintf(stderr,"%s:%d:\n\topj_end_decompress failed\n",__FILE__,__LINE__);
                break;
            }
            
        }
        else
        {
            if (!opj_get_decoded_tile(decodeInfo.codec, decodeInfo.stream, decodeInfo.image, parameters.tile_index))
            {
                fprintf(stderr,"%s:%d:\n\topj_get_decoded_tile failed\n",__FILE__,__LINE__);
                break;
            }
        }
        
        fails = OPJ_FALSE;
        break;
    } // while
    
    decodeInfo.deleteImage = fails;
    
    if (fails) {
        //decoderMutex.unlock();
        return EC_InvalidStream;
    }
    
    decodeInfo.deleteImage = OPJ_TRUE;
    
    if (decodeInfo.image->color_space == OPJ_CLRSPC_SYCC) {
        //disable for now
        //color_sycc_to_rgb(decodeInfo.image);
    }
    
    if (decodeInfo.image->color_space != OPJ_CLRSPC_SYCC
        && decodeInfo.image->numcomps == 3
        && decodeInfo.image->comps[0].dx == decodeInfo.image->comps[0].dy
        && decodeInfo.image->comps[1].dx != 1)
    {
        decodeInfo.image->color_space = OPJ_CLRSPC_SYCC;
    }
    else if (decodeInfo.image->numcomps <= 2)
    {
        decodeInfo.image->color_space = OPJ_CLRSPC_GRAY;
    }
    
    if (decodeInfo.image->icc_profile_buf)
    {
#if defined(HAVE_LIBLCMS1) || defined(HAVE_LIBLCMS2)
        color_apply_icc_profile(decodeInfo.image);
#endif
        free(decodeInfo.image->icc_profile_buf);
        decodeInfo.image->icc_profile_buf = NULL;
        decodeInfo.image->icc_profile_len = 0;
    }
    
    //---
    
    width = decodeInfo.image->comps[0].w;
    height = decodeInfo.image->comps[0].h;
    
    long depth = (decodeInfo.image->comps[0].prec + 7)/8;
    long decompressSize = width * height * decodeInfo.image->numcomps * depth;

    if (rawData && rawDataSize < decompressSize)
        return EC_EndOfStream;
    
    rawDataSize = decompressSize;
    if (!rawData)
        rawData = malloc(decompressSize);
    
    inter = EPI_Unknown;
    
    if ((decodeInfo.image->numcomps >= 3
         && decodeInfo.image->comps[0].dx == decodeInfo.image->comps[1].dx
         && decodeInfo.image->comps[1].dx == decodeInfo.image->comps[2].dx
         && decodeInfo.image->comps[0].dy == decodeInfo.image->comps[1].dy
         && decodeInfo.image->comps[1].dy == decodeInfo.image->comps[2].dy
         && decodeInfo.image->comps[0].prec == decodeInfo.image->comps[1].prec
         && decodeInfo.image->comps[1].prec == decodeInfo.image->comps[2].prec
         )/* RGB[A] */
        ||
        (decodeInfo.image->numcomps == 2
         && decodeInfo.image->comps[0].dx == decodeInfo.image->comps[1].dx
         && decodeInfo.image->comps[0].dy == decodeInfo.image->comps[1].dy
         && decodeInfo.image->comps[0].prec == decodeInfo.image->comps[1].prec
         )
        ) /* GA */
    {
        int  has_alpha4, has_alpha2, has_rgb;
        int *red, *green, *blue, *alpha;
        
        inter = EPI_RGB;
        
        alpha = NULL;
        
        has_rgb = (decodeInfo.image->numcomps == 3);
        has_alpha4 = (decodeInfo.image->numcomps == 4);
        has_alpha2 = (decodeInfo.image->numcomps == 2);
        hasAlpha = (has_alpha4 || has_alpha2);
        
        if(has_rgb)
        {
            red = decodeInfo.image->comps[0].data;
            green = decodeInfo.image->comps[1].data;
            blue = decodeInfo.image->comps[2].data;
            
            if(has_alpha4)
            {
                alpha = decodeInfo.image->comps[3].data;
            }
            
        }	/* if(has_rgb) */
        else
        {
            red = green = blue = decodeInfo.image->comps[0].data;
            if(has_alpha2)
            {
                alpha = decodeInfo.image->comps[1].data;
            }
        }	/* if(has_rgb) */
        
        ac = 255;/* 255: FULLY_OPAQUE; 0: FULLY_TRANSPARENT */
        
        unsigned char* ptrIBody = (unsigned char*)rawData;
        for(i = 0; i < width*height; i++)
        {
            rc = (unsigned char)*red++;
            gc = (unsigned char)*green++;
            bc = (unsigned char)*blue++;
            if(hasAlpha)
            {
                ac = (unsigned char)*alpha++;;
            }
            
            /*                         A        R          G       B
             */
            //*ptrIBody++ = (int)((ac<<24) | (rc<<16) | (gc<<8) | bc);
            *ptrIBody = rc;
            ptrIBody++;
            *ptrIBody = gc;
            ptrIBody++;
            *ptrIBody = bc;
            ptrIBody++;
            if (hasAlpha)
            {
                *ptrIBody = ac;
                ptrIBody++;
            }
        }	/* for(i) */
    }/* if (decodeInfo.image->numcomps >= 3  */
    else if(decodeInfo.image->numcomps == 1) /* Grey */
    {
        /* 1 component 8 or 16 bpp decodeInfo.image
         */
        int *grey = decodeInfo.image->comps[0].data;
        if(decodeInfo.image->comps[0].prec <= 8)
        {
            char* ptrBBody = (char*)rawData;
            for(i=0; i<width*height; i++)
            {
                *ptrBBody++ = *grey++;
            }
            /* Replace image8 buffer:
             */
        }
        else /* prec[9:16] */
        {
            int *grey = decodeInfo.image->comps[0].data;
            //int ushift = 0, dshift = 0, force16 = 0;
            
            short* ptrSBody = (short*)rawData;
            
            for(i=0; i<width*height; i++)
            {
                //disable shift up for signed data: don't know why we are doing this
                *ptrSBody++ = *grey++;
            }
            /* Replace image16 buffer:
             */
        }
    }
    else
    {
        int *grey;
        
        fprintf(stderr,"%s:%d:Can show only first component of decodeInfo.image\n"
                "  components(%d) prec(%d) color_space[%d](%s)\n"
                "  RECT(%d,%d,%d,%d)\n",__FILE__,__LINE__,decodeInfo.image->numcomps,
                decodeInfo.image->comps[0].prec,
                decodeInfo.image->color_space,djopen2k::clr_space(decodeInfo.image->color_space),
                decodeInfo.image->x0,decodeInfo.image->y0,decodeInfo.image->x1,decodeInfo.image->y1 );
        
        for(i = 0; i < decodeInfo.image->numcomps; ++i)
        {
            fprintf(stderr,"[%d]dx(%d) dy(%d) w(%d) h(%d) signed(%u)\n",i,
                    decodeInfo.image->comps[i].dx ,decodeInfo.image->comps[i].dy,
                    decodeInfo.image->comps[i].w,decodeInfo.image->comps[i].h,
                    decodeInfo.image->comps[i].sgnd);
        }
        
        /* 1 component 8 or 16 bpp decodeInfo.image
         */
        grey = decodeInfo.image->comps[0].data;
        if(decodeInfo.image->comps[0].prec <= 8)
        {
            char* ptrBBody = (char*)rawData;
            for(i=0; i<width*height; i++)
            {
                *ptrBBody++ = *grey++;
            }
            /* Replace image8 buffer:
             */
        }
        else /* prec[9:16] */
        {
            int *grey;
            //int ushift = 0, dshift = 0, force16 = 0;
            
            grey = decodeInfo.image->comps[0].data;
            
            short* ptrSBody = (short*)rawData;
            
            for(i=0; i<width*height; i++)
            {
                *ptrSBody++ = *grey++;
            }
            /* Replace image16 buffer:
             */
        }
    }
    
    //decoderMutex.unlock();
    return EC_Normal;
}

OFCondition DcmIntegrationDefault::encodeJ2K(Uint16 columns, Uint16 rows,
                                             EP_Interpretation inter, Uint8 bitsPerSample, Uint16 samplesPerPixel,
                                             void *rawData,
                                             void *&j2kData, Uint32 &j2kDataSize,
                                             DJ2KQuality quality)
{
    
    Uint8 encodeBitsPerSample = bitsPerSample;
    if (samplesPerPixel > 1)
        encodeBitsPerSample = bitsPerSample = 8;
    
    OFBool encodeSigned = OFFalse;
    
    if (bitsPerSample >= 16) {
        double min = 0, max = 0;
        djopen2k::findMinMax((char *)rawData, columns*rows*samplesPerPixel*bitsPerSample/8, encodeSigned, rows, columns, bitsPerSample, min, max);
        
        int amplitude = max;
        if (min < 0)
            amplitude -= min;
        
        unsigned int bits = 1, value = 2;
        while (value < amplitude && bits <= 16) {
            value *= 2;
            bits++;
        }
        
        if (min < 0) // K A10009536850 22.06.12
            bits++;
        if (bits < 9)
            bits = 9;
        
        // avoid the artifacts... switch to lossless
        if ((max >= 32000 && min <= -32000) || max >= 65000 || bits > 16)
            quality = DJ2KQualityLossless;
        
        if (bits > 16)
            bits = 16;
        
        encodeBitsPerSample = bits;
    }
    
    if (inter != EPI_Monochrome1 && inter != EPI_Monochrome2 && samplesPerPixel != 3)
        printf("¿¿¿ RGB Photometric with SamplesPerPixel != 3 ???");

    //enconderMutex.lock();
    
    opj_stream_t *l_stream = NULL;
    opj_codec_t* l_codec = NULL;
    
    OPJ_BOOL bSuccess;
    OPJ_BOOL bUseTiles = OPJ_FALSE; /* OPJ_TRUE */
    OPJ_UINT32 l_nb_tiles = 4;
    
    OPJ_BOOL fails = OPJ_FALSE;
    OPJ_CODEC_FORMAT codec_format;
    
    opj_cparameters_t parameters;
    memset(&parameters, 0, sizeof(parameters));
    opj_set_default_encoder_parameters(&parameters);

    parameters.outfile[0] = '\0';
    parameters.tcp_numlayers = 1;
    parameters.cp_disto_alloc = 1;
    parameters.cod_format = 1; // JP2_CFMT
    OPJ_BOOL forceJ2K = (parameters.cod_format == 0)? OPJ_FALSE : OPJ_TRUE;
    
    switch (quality) {
        case DJ2KQualityLossless:
            parameters.tcp_rates[0] = 16; break;
        case DJ2KQualityHigh:
            parameters.tcp_rates[0] = 8; break;
        case DJ2KQualityMedium:
            parameters.tcp_rates[0] = 5; break;
        case DJ2KQualityLow:
            parameters.tcp_rates[0] = 0; break;
    }
    
#ifdef WITH_OPJ_FILE_STREAM
    strcpy(parameters.outfile, "/tmp/opjXXXXXX");
    mkstemp(parameters.outfile);
#endif
    
    Uint8 bytesPerSample = 1;
    if (bitsPerSample > 8) bytesPerSample = 2;
    
    opj_image_t *image = djopen2k::rawtoimage((char *)rawData,
                       &parameters,
                       static_cast<int>( columns*rows*samplesPerPixel*bytesPerSample), // [data length], fragment_size
                       columns, rows,
                       samplesPerPixel,
                       bitsPerSample,
                       encodeBitsPerSample,
                       encodeSigned,
                       /*quality,*/ 0);
    
    if (image == NULL)
    {
        /* close and free the byte stream */
        if (l_stream) opj_stream_destroy(l_stream);
        
        /* free remaining compression structures */
        if (l_codec) opj_destroy_codec(l_codec);
        
        /* free image data */
        if (image) opj_image_destroy(image);
        
        //enconderMutex.unlock();
        
        return EC_InvalidStream;
    }
    
    /*-----------------------------------------------*/
    
    switch (parameters.cod_format)
    {
        case 0:                      /* J2K_CFMT: JPEG-2000 codestream */
            codec_format = OPJ_CODEC_J2K;
            break;
            
        case 1:                      /* JP2_CFMT: JPEG 2000 compressed image data */
            codec_format = OPJ_CODEC_JP2;
            break;
            
        case 2:                      /* JPT_CFMT: JPEG 2000, JPIP */
            codec_format = OPJ_CODEC_JPT;
            break;
            
        default:
            fprintf(stderr,"%s:%d: encode format missing\n",__FILE__,__LINE__);
            
            /* close and free the byte stream */
            if (l_stream) opj_stream_destroy(l_stream);
            
            /* free remaining compression structures */
            if (l_codec) opj_destroy_codec(l_codec);
            
            /* free image data */
            if (image) opj_image_destroy(image);
            
            //enconderMutex.unlock();
            
            return EC_InvalidStream;
    }
    
    /* see test_tile_encoder.c:232 and opj_compress.c:1746 */
    l_codec = opj_create_compress(codec_format);
    if (!l_codec)
    {
        fprintf(stderr,"%s:%d:\n\tNO codec\n",__FILE__,__LINE__);
        
        /* close and free the byte stream */
        if (l_stream) opj_stream_destroy(l_stream);
        
        /* free remaining compression structures */
        if (l_codec) opj_destroy_codec(l_codec);
        
        /* free image data */
        if (image) opj_image_destroy(image);
        
        //enconderMutex.unlock();
        
        return EC_InvalidStream;
    }
    
    
    char *lcodecError = NULL;
    opj_set_error_handler(l_codec, (opj_msg_callback)djopen2k::error_callback, &lcodecError);
#ifdef OPJ_VERBOSE
    opj_set_info_handler(l_codec, info_callback, this);
    opj_set_warning_handler(l_codec, warning_callback, this);
#endif
    
    if ( !opj_setup_encoder(l_codec, &parameters, image))
    {
        fprintf(stderr,"%s:%d:\n\topj_setup_encoder failed\n",__FILE__,__LINE__);
        
        /* close and free the byte stream */
        if (l_stream) opj_stream_destroy(l_stream);
        
        /* free remaining compression structures */
        if (l_codec) opj_destroy_codec(l_codec);
        
        /* free image data */
        if (image) opj_image_destroy(image);
        
        //enconderMutex.unlock();
        
        return EC_InvalidStream;
    }
    
    
    // Create the stream
#ifdef WITH_OPJ_BUFFER_STREAM
    opj_buffer_info_t bufferInfo;
    bufferInfo.cur = bufferInfo.buf = (OPJ_BYTE *)data;
    bufferInfo.len = (OPJ_SIZE_T) rows * columns;
    l_stream = opj_stream_create_buffer_stream(&bufferInfo, OPJ_STREAM_WRITE);
    
    //printf("%p\n",bufferInfo.buf);
    //printf("%lu\n",bufferInfo.len);
#endif
    
#ifdef WITH_OPJ_FILE_STREAM
    l_stream = opj_stream_create_default_file_stream(parameters.outfile, OPJ_STREAM_WRITE);
#endif
    
    
    if (!l_stream)
    {
        fprintf(stderr,"%s:%d:\n\tstream creation failed\n",__FILE__,__LINE__);
        
        /* close and free the byte stream */
        if (l_stream) opj_stream_destroy(l_stream);
        
        /* free remaining compression structures */
        if (l_codec) opj_destroy_codec(l_codec);
        
        /* free image data */
        if (image) opj_image_destroy(image);
        
        //enconderMutex.unlock();
        
        return EC_InvalidStream;
    }
    
    
    while(1)
    {
        //        int tile_index=-1, user_changed_tile=0, user_changed_reduction=0;
        //        int max_tiles=0, max_reduction=0;
        fails = OPJ_TRUE;
        
        /* encode the image */
        bSuccess = opj_start_compress(l_codec, image, l_stream);
        
        if (!bSuccess)
        {
            fprintf(stderr,"%s:%d:\n\topj_start_compress failed\n",__FILE__,__LINE__);
            break;
        }
        
        if ( bSuccess && bUseTiles )
        {
            OPJ_BYTE *l_data = NULL;
            OPJ_UINT32 l_data_size = 512*512*3; //FIXME
            l_data = (OPJ_BYTE*) malloc(l_data_size * sizeof(OPJ_BYTE));
            memset(l_data, 0, l_data_size * sizeof(OPJ_BYTE));
            
            //assert( l_data );
            if (!l_data)
            {
                /* close and free the byte stream */
                if (l_stream) opj_stream_destroy(l_stream);
                
                /* free remaining compression structures */
                if (l_codec) opj_destroy_codec(l_codec);
                
                /* free image data */
                if (image) opj_image_destroy(image);
                
                //enconderMutex.unlock();
                
                return EC_InvalidStream;
            }
            
            for (int i=0;i<l_nb_tiles;++i)
            {
                if (! opj_write_tile(l_codec,i,l_data,l_data_size,l_stream))
                {
                    fprintf(stderr, "\nERROR -> test_tile_encoder: failed to write the tile %d!\n",i);
                    /* close and free the byte stream */
                    if (l_stream) opj_stream_destroy(l_stream);
                    
                    /* free remaining compression structures */
                    if (l_codec) opj_destroy_codec(l_codec);
                    
                    /* free image data */
                    if (image) opj_image_destroy(image);
                    
                    free(l_data);
                    
                    //enconderMutex.unlock();
                    
                    return EC_InvalidStream;
                }
            }
            
            free(l_data);
        }
        else
        {
            if (!opj_encode(l_codec, l_stream))
            {
                fprintf(stderr,"%s:%d:\n\topj_encode failed\n",__FILE__,__LINE__);
                break;
            }
        }
        
        if (!opj_end_compress(l_codec, l_stream))
        {
            fprintf(stderr,"%s:%d:\n\topj_end_compress failed\n",__FILE__,__LINE__);
            break;
        }
        
        fails = OPJ_FALSE;
        break;
        
    } // while
    
    j2kDataSize = 0;
    
    /* close and free the byte stream */
    if (l_stream) opj_stream_destroy(l_stream);
    
    /* free remaining compression structures */
    if (l_codec) opj_destroy_codec(l_codec);
    
    /* free image data */
    if (image) opj_image_destroy(image);
    
    if (fails)
    {
#ifdef WITH_OPJ_FILE_STREAM
        if (parameters.outfile[0] != '\0')
            remove(parameters.outfile);
#endif
    }
    else
    {
#ifdef WITH_OPJ_BUFFER_STREAM
        //printf("%p\n",bufferInfo.buf);
        //printf("%lu\n",bufferInfo.len);
        //to=(unsigned char *) malloc(bufferInfo.len);
        //memcpy(to,l_stream,bufferInfo.len);
#endif
        
#ifdef WITH_OPJ_FILE_STREAM
        // Open the temp file and get the encoded data into 'to'
        // and the length into 'length'
        FILE *f = NULL;
        if (parameters.outfile[0] != '\0')
        {
            f = fopen(parameters.outfile, "rb");
        }
        
        long length = 0;
        
        if (f != NULL)
        {
            fseek(f, 0, SEEK_END);
            length = ftell(f);
            fseek(f, 0, SEEK_SET);
            if (forceJ2K)
            {
                length -= 85;
                fseek(f, 85, SEEK_SET);
            }
            
            if (length % 2)
            {
                length++; // ensure even length
                //fprintf(stdout,"Padded to %li\n", length);
            }
            
            
            j2kData = (unsigned char *)malloc(length);
            
            fread(j2kData, length, 1, f);
            
            //printf("%s %lu\n",parameters.outfile,length);;
            
            fclose(f);
        }
        
        j2kDataSize = length;
        
        if (parameters.outfile[0] != '\0')
        {
            remove(parameters.outfile);
        }
#endif
    }
    
    //enconderMutex.unlock();
    
    return EC_Normal;
}

namespace djopen2k {
    
    static void findMinMax(char *bytes, long length, OFBool isSigned, int rows, int columns, int bitsPerSample, double &min, double &max)
    {
        float lmax = max = 0, lmin = min = 0;
    
        if (bitsPerSample <= 8)
            ;
        else if (bitsPerSample <= 16)
            length = length/2;
        else
            length = length/4;
    
        vImage_Buffer src, dstf;
        src.data = (void *)bytes;
        float fBuffer[length];
        dstf.height = src.height = rows;
        dstf.width = src.width = columns;
        dstf.rowBytes = columns*sizeof(float);
        dstf.data = fBuffer;
    
        if (bitsPerSample <= 8) {
            src.rowBytes = columns;
            vImageConvert_Planar8toPlanarF(&src, &dstf, 0, 256, 0);
        }
        else if (bitsPerSample <= 16) {
            src.rowBytes = columns * 2;
            if (isSigned)
                vImageConvert_16SToF(&src, &dstf, 0, 1, 0);
            else vImageConvert_16UToF(&src, &dstf, 0, 1, 0);
        }
    
        vDSP_minv(fBuffer, 1, &lmin, length);
        vDSP_maxv(fBuffer, 1, &lmax, length);
        
        min = lmin;
        max = lmax;
    }
    
    template<typename T> void rawtoimage_fill(T *inputbuffer, int w, int h, int numcomps, opj_image_t *image, int pc)
    {
        T *p = inputbuffer;
        if( pc )
        {
            for(int compno = 0; compno < numcomps; compno++)
            {
                for (int i = 0; i < w * h; i++)
                {
                    /* compno : 0 = GREY, (0, 1, 2) = (R, G, B) */
                    image->comps[compno].data[i] = *p;
                    ++p;
                }
            }
        }
        else
        {
            for (int i = 0; i < w * h; i++)
            {
                for(int compno = 0; compno < numcomps; compno++)
                {
                    /* compno : 0 = GREY, (0, 1, 2) = (R, G, B) */
                    image->comps[compno].data[i] = *p;
                    ++p;
                }
            }
        }
    }
    
    static opj_image_t* rawtoimage(char *inputbuffer, opj_cparameters_t *parameters,
                            int fragment_size, int image_width, int image_height, int sample_pixel,
                            int bitsallocated, int bitsstored, int sign, /*int quality,*/ int pc)
    {
        //(void)quality;
        int w, h;
        int numcomps;
        OPJ_COLOR_SPACE color_space;
        opj_image_cmptparm_t cmptparm[3]; /* maximum of 3 components */
        opj_image_t * image = NULL;
        
        assert( sample_pixel == 1 || sample_pixel == 3 );
        if( sample_pixel == 1 )
        {
            numcomps = 1;
            color_space = OPJ_CLRSPC_GRAY;
        }
        else // sample_pixel == 3
        {
            numcomps = 3;
            color_space = OPJ_CLRSPC_SRGB;
            /* Does OpenJPEG support: OPJ_CLRSPC_SYCC ?? */
        }
        if( bitsallocated % 8 != 0 )
        {
            return 0;
        }
        assert( bitsallocated % 8 == 0 );
        // eg. fragment_size == 63532 and 181 * 117 * 3 * 8 == 63531 ...
        assert( ((fragment_size + 1)/2 ) * 2 == ((image_height * image_width * numcomps * (bitsallocated/8) + 1)/ 2 )* 2 );
        int subsampling_dx = parameters->subsampling_dx;
        int subsampling_dy = parameters->subsampling_dy;
        
        // FIXME
        w = image_width;
        h = image_height;
        
        /* initialize image components */
        memset(&cmptparm[0], 0, 3 * sizeof(opj_image_cmptparm_t));
        //assert( bitsallocated == 8 );
        
        for(int i = 0; i < numcomps; i++)
        {
            cmptparm[i].prec = bitsstored;
            cmptparm[i].bpp = bitsallocated;
            cmptparm[i].sgnd = sign;
            cmptparm[i].dx = subsampling_dx;
            cmptparm[i].dy = subsampling_dy;
            cmptparm[i].w = w;
            cmptparm[i].h = h;
        }
        
        /* create the image */
        image = opj_image_create(numcomps, &cmptparm[0], color_space);
        if (!image)
        {
            return NULL;
        }
        
        /* set image offset and reference grid */
        image->x0 = parameters->image_offset_x0;
        image->y0 = parameters->image_offset_y0;
        image->x1 = parameters->image_offset_x0 + (w - 1) * subsampling_dx + 1;
        image->y1 = parameters->image_offset_y0 + (h - 1) * subsampling_dy + 1;
        
        /* set image data */
        
        //assert( fragment_size == numcomps*w*h*(bitsallocated/8) );
        if (bitsallocated <= 8)
        {
            if( sign )
            {
                rawtoimage_fill<int8_t>((int8_t*)inputbuffer,w,h,numcomps,image,pc);
            }
            else
            {
                rawtoimage_fill<uint8_t>((uint8_t*)inputbuffer,w,h,numcomps,image,pc);
            }
        }
        else if (bitsallocated <= 16)
        {
            if( sign )
            {
                rawtoimage_fill<int16_t>((int16_t*)inputbuffer,w,h,numcomps,image,pc);
            }
            else
            {
                rawtoimage_fill<uint16_t>((uint16_t*)inputbuffer,w,h,numcomps,image,pc);
            }
        }
        else if (bitsallocated <= 32)
        {
            if( sign )
            {
                rawtoimage_fill<int32_t>((int32_t*)inputbuffer,w,h,numcomps,image,pc);
            }
            else
            {
                rawtoimage_fill<uint32_t>((uint32_t*)inputbuffer,w,h,numcomps,image,pc);
            }
        }
        else
        {
            return NULL;
        }
        
        return image;
    }
    
    typedef struct opj_buffer_info {
        OPJ_BYTE *buf;
        OPJ_BYTE *cur;
        OPJ_SIZE_T len;
    } opj_buffer_info_t;
    
    static OPJ_SIZE_T opj_read_from_buffer(void* pdst, OPJ_SIZE_T len, opj_buffer_info_t* psrc) {
        OPJ_SIZE_T n = psrc->buf + psrc->len - psrc->cur;
        
        if (n) {
            if (n > len)
                n = len;
            
            memcpy (pdst, psrc->cur, n);
            psrc->cur += n;
        }
        else
            n = (OPJ_SIZE_T)-1;
        
        return n;
    }
    
    static OPJ_SIZE_T opj_write_to_buffer(void* p_buffer, OPJ_SIZE_T p_nb_bytes, opj_buffer_info_t* p_source_buffer) {
        OPJ_BYTE* pbuf = p_source_buffer->buf;
        OPJ_BYTE* pcur = p_source_buffer->cur;
        
        OPJ_SIZE_T len = p_source_buffer->len;
        
        if (0 == len)
            len = 1;
        
        OPJ_SIZE_T dist = pcur - pbuf, n = len - dist;
        assert (dist <= len);
        
        while (n < p_nb_bytes) {
            len *= 2;
            n = len - dist;
        }
        
        if (len != p_source_buffer->len) {
            pbuf = (OPJ_BYTE*)malloc(len);
            
            if (0 == pbuf)
                return (OPJ_SIZE_T)-1;
            
            if (p_source_buffer->buf) {
                memcpy (pbuf, p_source_buffer->buf, dist);
                free(p_source_buffer->buf);
            }
            
            p_source_buffer->buf = pbuf;
            p_source_buffer->cur = pbuf + dist;
            p_source_buffer->len = len;
        }
        
        memcpy (p_source_buffer->cur, p_buffer, p_nb_bytes);
        p_source_buffer->cur += p_nb_bytes;
        
        return p_nb_bytes;
    }
    
    static OPJ_SIZE_T opj_skip_from_buffer(OPJ_SIZE_T len, opj_buffer_info_t* psrc) {
        OPJ_SIZE_T n = psrc->buf + psrc->len - psrc->cur;
        
        if (n) {
            if (n > len)
                n = len;
            
            psrc->cur += len;
        }
        else
            n = (OPJ_SIZE_T)-1;
        
        return n;
    }
    
    static OPJ_BOOL opj_seek_from_buffer(OPJ_OFF_T len, opj_buffer_info_t* psrc) {
        OPJ_SIZE_T n = psrc->len;
        
        if (n > len)
            n = len;
        
        psrc->cur = psrc->buf + n;
        
        return OPJ_TRUE;
    }
    
    static void opj_free_buffer(opj_buffer_info_t* psrc) {
        delete psrc;
    }
    
    opj_stream_t * OPJ_CALLCONV opj_stream_create_buffer_stream(OPJ_BYTE *data, OPJ_SIZE_T len, OPJ_BOOL input) {
        if (!data)
            return NULL;
        
        opj_stream_t* ps = opj_stream_default_create(input);
        if (!ps)
            return NULL;
        
        opj_buffer_info_t* psrc = new opj_buffer_info_t;
        if (!psrc)
            return NULL;
        
        psrc->buf = psrc->cur = data;
        psrc->len = len;
        
        opj_stream_set_user_data(ps, psrc, (opj_stream_free_user_data_fn)opj_free_buffer);
        opj_stream_set_user_data_length(ps, psrc->len);
        
        if (input)
            opj_stream_set_read_function (ps, (opj_stream_read_fn)opj_read_from_buffer);
        else opj_stream_set_write_function(ps,(opj_stream_write_fn) opj_write_to_buffer);
        
        opj_stream_set_skip_function(ps, (opj_stream_skip_fn)opj_skip_from_buffer);
        opj_stream_set_seek_function(ps, (opj_stream_seek_fn)opj_seek_from_buffer);
        
        return ps;
    }
    
}

#endif
