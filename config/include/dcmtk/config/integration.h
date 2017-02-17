#ifndef DCMTKINT_H
#define DCMTKINT_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/dje2k.h"

class DCMTK_INTEGRATION_CLASS {
public:
    
//    static const DCMTK_INTEGRATION_CLASS& instance() {
//        static DCMTK_INTEGRATION_CLASS instance;
//        return instance;
//    }
    
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

#endif // DCMTKINT_H
