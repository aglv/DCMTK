#ifndef DCMTKINT_H
#define DCMTKINT_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/dje2k.h"

#ifdef DCMTK_INTEGRATION_CLASS

class DCMTK_INTEGRATION_CLASS {
public:
    
    static OFCondition decodeJ2K(void *j2kData, Uint32 j2kDataSize,
                                 void *&rawData, Uint32 &rawDataSize,
                                 OFBool expectingSignedRawData, EP_Interpretation &outColorModel);
    
    static OFCondition encodeJ2K(Uint16 columns, Uint16 rows,
                                 EP_Interpretation inter, Uint8 bitsPerSample, Uint16 samplesPerPixel,
                                 void *rawData,
                                 void *&j2kData, Uint32 &j2kDataSize,
                                 DJ2KQuality quality);
    
protected:
    DCMTK_INTEGRATION_CLASS() {}
};

#else 

#define DCMTK_INTEGRATION_CLASS DefaultDcmIntegration

#endif

class DefaultDcmIntegration {
public:
    
    static OFCondition decodeJ2K(void *j2kData, Uint32 j2kDataSize,
                                 void *&rawData, Uint32 &rawDataSize,
                                 OFBool expectingSignedRawData, EP_Interpretation &outColorModel);
    
    static OFCondition encodeJ2K(Uint16 columns, Uint16 rows,
                                 EP_Interpretation inter, Uint8 bitsPerSample, Uint16 samplesPerPixel,
                                 void *rawData,
                                 void *&j2kData, Uint32 &j2kDataSize,
                                 DJ2KQuality quality);
    
protected:
    DefaultDcmIntegration() {}
};

#endif // DCMTKINT_H
