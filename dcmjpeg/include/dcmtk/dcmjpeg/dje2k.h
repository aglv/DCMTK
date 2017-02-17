#ifndef DJE2K_H
#define DJE2K_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/ofstd/oflist.h"
#include "dcmtk/dcmjpeg/djencabs.h"

class DJCodecParameter;

enum DJ2KQuality {
    DJ2KQualityLossless,
    DJ2KQualityHigh,
    DJ2KQualityMedium,
    DJ2KQualityLow
};

class DJCompress2K : public DJEncoder {
    const DJCodecParameter *_param;
    EJ_Mode _mode; // enum for mode of operation (baseline, sequential, progressive, ...)
    DJ2KQuality _quality; // for lossy compression
    Uint8 _bitsPerSample;
    
public:

    DJCompress2K(const DJCodecParameter& param, EJ_Mode mode, Uint8 bitsPerSample) : DJCompress2K(param, mode, DJ2KQualityLossless, bitsPerSample) {}
    DJCompress2K(const DJCodecParameter& param, EJ_Mode mode, DJ2KQuality quality, Uint8 bitsPerSample) : DJEncoder(), _param(&param), _mode(mode), _quality(quality), _bitsPerSample(bitsPerSample) {}
    virtual ~DJCompress2K() {}
    
    virtual OFCondition encode(Uint16 columns,
                               Uint16 rows,
                               EP_Interpretation interpr,
                               Uint16 samplesPerPixel,
                               Uint8 *image_buffer,
                               Uint8 *&to,
                               Uint32 &length/*,
                               Uint8 pixelRepresentation,
                               double minUsed, double maxUsed*/);
    
    virtual OFCondition encode(Uint16 columns,
                               Uint16 rows,
                               EP_Interpretation interpr,
                               Uint16 samplesPerPixel,
                               Uint16 *image_buffer,
                               Uint8 *&to,
                               Uint32 &length/*,
                               Uint8 pixelRepresentation,
                               double minUsed, double maxUsed*/);
    
    virtual Uint16 bitsPerSample() const { return _bitsPerSample; }
    virtual Uint16 bytesPerSample() const { return (_bitsPerSample <= 8)? 1 : 2; }
    
private:

    virtual OFCondition encode(Uint16 columns, Uint16 rows,
                               EP_Interpretation inter, Uint8 bitsPerSample, Uint16 samplesPerPixel,
                               void *image_buffer,
                               Uint8 *&to, Uint32 &length/*, Uint8 pixelRepresentation, double minUsed, double maxUsed*/);

    DJCompress2K(const DJCompress2K&); // copy constructor unavailable
    DJCompress2K& operator=(const DJCompress2K&); // unavailable copy assignment operator
    
//    void findMinMax(char *bytes, long length, OFBool isSigned, int rows, int columns, int bitsAllocated, double &min, double &max);
};

#endif
