#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/dje2k.h"

#include "dcmtk/config/integration.h"
//#include "dcmtk/dcmjpeg/djcparam.h"
//#include "dcmtk/ofstd/ofconsol.h"

//#include <sys/types.h>
//#include <sys/sysctl.h>

//#define INCLUDE_CSTDIO
//#define INCLUDE_CSETJMP
//#include "dcmtk/ofstd/ofstdinc.h"

//// KDU support
//#include <CoreServices/CoreServices.h>
//#include "kdu_OsiriXSupport.h"
//extern short Use_kdu_IfAvailable;

//#include "OPJSupport.h"
//#include "../Binaries/openjpeg/openjpeg.h"

//#include "DCM.h" // for DCMLosslessQuality

//void DJCompress2K::findMinMax(char *bytes, long length, OFBool isSigned, int rows, int columns, int bitsAllocated, double &min, double &max)
//{
//    float lmax = max = 0, lmin = min = 0;
//    
//    if (bitsAllocated <= 8)
//        length = length;
//    else if (bitsAllocated <= 16)
//        length = length/2;
//    else
//        length = length/4;
//    
//    vImage_Buffer src, dstf;
//    src.data = (void *)bytes;
//    float fBuffer[length];
//    dstf.height = src.height = rows;
//    dstf.width = src.width = columns;
//    dstf.rowBytes = columns*sizeof(float);
//    dstf.data = fBuffer;
//    
//    if (bitsAllocated <= 8) {
//        src.rowBytes = columns;
//        vImageConvert_Planar8toPlanarF(&src, &dstf, 0, 256, 0);
//    }
//    else if (bitsAllocated <= 16) {
//        src.rowBytes = columns * 2;
//        if (isSigned)
//            vImageConvert_16SToF(&src, &dstf, 0, 1, 0);
//        else vImageConvert_16UToF(&src, &dstf, 0, 1, 0);
//    }
//    
//    vDSP_minv(fBuffer, 1, &lmin, length);
//    vDSP_maxv(fBuffer, 1, &lmax, length);
//    
//    min = lmin;
//    max = lmax;
//}

OFCondition DJCompress2K::encode(Uint16 columns,
                                 Uint16 rows,
                                 EP_Interpretation inter,
                                 Uint16 samplesPerPixel,
                                 Uint8 * image_buffer,
                                 Uint8 * & to,
                                 Uint32 & length/*,
                                 Uint8 pixelRepresentation,
                                 double minUsed, double maxUsed*/)
{
    return encode(columns, rows,
                  inter, 8, samplesPerPixel,
                  image_buffer,
                  to, length/*, pixelRepresentation, minUsed, maxUsed*/);
}

OFCondition DJCompress2K::encode(Uint16  columns ,
                                 Uint16  rows ,
                                 EP_Interpretation inter,
                                 Uint16  samplesPerPixel ,
                                 Uint16 *  image_buffer ,
                                 Uint8 *&  to ,
                                 Uint32 &  length/*,
                                 Uint8 pixelRepresentation,
                                 double minUsed, double maxUsed*/)
{
    return encode(columns, rows,
                  inter, 16, samplesPerPixel,
                  image_buffer,
                  to, length/*, pixelRepresentation, minUsed, maxUsed*/);
}

OFCondition DJCompress2K::encode(Uint16 columns, Uint16 rows,
                                 EP_Interpretation inter, Uint8 bitsPerSample, Uint16 samplesPerPixel,
                                 void *image_buffer,
                                 Uint8 *&to, Uint32 &length/*, Uint8 pixelRepresentation, double minUsed, double maxUsed*/)
{
    /*Uint8 bitsStored = bitsPerSample;
    if (samplesPerPixel > 1)
        bitsPerSample = bitsPerSample = 8;
    
    OFBool isSigned = 0;
    
    if (bitsAllocated >= 16) {
        if (minUsed == 0 && maxUsed == 0)
            findMinMax((char *)image_buffer, columns*rows*samplesPerPixel*bitsAllocated/8, isSigned, rows, columns, bitsAllocated, minUsed, maxUsed);
        
        int amplitude = maxUsed;
        
        if (minUsed < 0)
            amplitude -= minUsed;
        
        int bits = 1, value = 2;
        while (value < amplitude && bits <= 16) {
            value *= 2;
            bits++;
        }
        
        if (minUsed < 0) // K A10009536850 22.06.12
            bits++;
        if (bits < 9)
            bits = 9;
        
        // avoid the artifacts... switch to lossless
        if ((maxUsed >= 32000 && minUsed <= -32000) || maxUsed >= 65000 || bits > 16)
            _quality = DJCompress2KLosslessQuality;
        
        if (bits > 16)
            bits = 16;
        
        bitsStored = bits;
    }
    
//    int rate = 0;
//	  if( Use_kdu_IfAvailable && (kdu_available != NULL) && kdu_available())
//	  {
////	    printf( "JP2K KDU-DCMTK-Encode ");
//
////		int precision = bitsstored;
//
//		  switch( quality)
//		  {
//            case DCMLosslessQuality:
//                rate = 0;
//                break;
//
//            case DCMHighQuality:
//                rate = 5;
//			      break;
//
//			  case DCMMediumQuality:
//				  if( columns <= 600 || rows <= 600) rate = 6;
//				  else rate = 8;
//				  break;
//
//			  case DCMLowQuality:
//				  rate = 16;
//				  break;
//
//			  default:
//				  printf( "****** warning unknown compression rate -> lossless : %d", quality);
//				  rate = 0;
//				  break;
//		  }
//
//		  long compressedLength = 0;
//
//		  int processors = 0;
//
//		  if (rows*columns > 256*1024) // 512 * 512
//        {
//            int mib[2] = {CTL_HW, HW_NCPU};
//            size_t dataLen = sizeof(int); // 'num' is an 'int'
//            int result = sysctl(mib, 2, &processors, &dataLen, NULL, 0);
//            if (result == -1)
//                processors = 1;
//            if (processors > 8)
//                processors = 8;
//        }
//
//		  void *outBuffer = kdu_compressJPEG2K( (void*) image_buffer, samplesPerPixel, rows, columns, bitsstored, false, rate, &compressedLength, processors);
//		
//		  if (outBuffer)
//		  {
//			  to = new Uint8[ compressedLength];
//			  memcpy( to, outBuffer, compressedLength);
//			  length = compressedLength;
//		
//			  free(outBuffer);
//		  }
//	  }
//	  else
//    {
//    switch (_quality) {
//        case DJCompress2KLosslessQuality:
//            rate = 0;
//            break;
//        case DJCompress2KHighQuality:
//            rate = 4;
//            break;
//        case DJCompress2KQualityMedium:
//            if (columns <= 600 || rows <= 600)
//                rate = 6;
//            else rate = 8;
//            break;
//        case DJCompress2KQualityLow:
//            rate = 16;
//            break;
//    }
    
    int sample_pixel = samplesPerPixel;
    
    if (colorSpace != EPI_Monochrome1 && colorSpace != EPI_Monochrome2 && sample_pixel != 3)
        printf( "¿¿¿ RGB Photometric with SamplesPerPixel != 3 ???");
    
    unsigned long compressedLength = 0;*/
    
    return DCMTK_INTEGRATION_CLASS::encodeJ2K(columns, rows,
                                              inter, bitsPerSample, samplesPerPixel,
                                              image_buffer,
                                              (void *&)to, length,
                                              _quality);
}
