#ifndef DJD2K_H
#define DJD2K_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djdecabs.h"

class DJCodecParameter;

/** this class encapsulates the decompression routines of the
 *  IJG JPEG library configured for 16 bits/sample.
 */
class DJDecompress2K : public DJDecoder {
    const DJCodecParameter *_param;
    OFBool _isYCbCr;
    
    int _suspension; // position of last suspend
    void *_jsampBuffer; // temporary storage for row buffer during suspension
    EP_Interpretation _inter; // color model after decompression
    
public:

    DJDecompress2K(const DJCodecParameter &param, OFBool isYCbCr) : DJDecoder(), _param(&param), _isYCbCr(isYCbCr), _suspension(0), _jsampBuffer(NULL), _inter(EPI_Unknown) {}
    virtual ~DJDecompress2K() {}
    
    virtual OFCondition init() { return EC_Normal; };
    
    virtual OFCondition decode(Uint8 *compressedFrameBuffer,
                               Uint32 compressedFrameBufferSize,
                               Uint8 *uncompressedFrameBuffer,
                               Uint32 uncompressedFrameBufferSize,
                               OFBool isSigned);
    
    virtual Uint16 bytesPerSample() const { return sizeof(Uint16); }
    
    virtual EP_Interpretation getDecompressedColorModel() const { return _inter; }
    
private:
    
    DJDecompress2K(const DJDecompress2K&) {} // unavailable copy constructor
    DJDecompress2K& operator=(const DJDecompress2K&) { return *this; } // unavailable copy operator
    
};

#endif
