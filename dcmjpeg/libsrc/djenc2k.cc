#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djenc2k.h"

#include "dcmtk/dcmjpeg/djcparam.h"
#include "dcmtk/dcmjpeg/djrploss.h"
#include "dcmtk/dcmjpeg/djutils.h"
#include "dcmtk/dcmjpeg/dje2k.h"

// lossy

void DJEncoder2K::createDerivationDescription(const DcmRepresentationParameter *toRepParam,
                                              const DJCodecParameter *cp,
                                              Uint8 bitsPerSample,
                                              double ratio,
                                              OFString& derivationDescription) const
{
    DJ_RPLossy defaultRP;
    const DJ_RPLossy *rp = toRepParam ? (const DJ_RPLossy *)toRepParam : &defaultRP ;
    char buf[64];
    
    derivationDescription = "Lossy compression with J2K";
    
    derivationDescription += ", quality factor ";
    sprintf(buf, "%u", rp->getQuality());
    derivationDescription += buf;
    
    derivationDescription += ", compression ratio ";
    appendCompressionRatio(derivationDescription, ratio);
}


DJEncoder *DJEncoder2K::createEncoderInstance(const DcmRepresentationParameter *toRepParam,
                                              const DJCodecParameter *cp,
                                              Uint8 bitsPerSample) const
{
    DJ2KQuality q = DJ2KQualityHigh;
    if (toRepParam) {
        const DJ_RPLossy *rp = (const DJ_RPLossy *)toRepParam;
        if (rp->getQuality() >= 100)
            q = DJ2KQualityLossless;
        else if (rp->getQuality() >= 70)
            q = DJ2KQualityHigh;
        else if (rp->getQuality() >= 30)
            q = DJ2KQualityMedium;
        else
            q = DJ2KQualityLow;
    }
    
    return new DJCompress2K(*cp, EJM_2k_lossy, q, bitsPerSample);
}

// lossless

void DJEncoder2KLossless::createDerivationDescription(const DcmRepresentationParameter *toRepParam,
                                                      const DJCodecParameter *cp,
                                                      Uint8 /* bitsPerSample */ ,
                                                      double ratio,
                                                      OFString& derivationDescription) const
{
    derivationDescription = "Lossless compression with J2K";
    
    derivationDescription += ", compression ratio ";
    appendCompressionRatio(derivationDescription, ratio);
}


DJEncoder *DJEncoder2KLossless::createEncoderInstance(const DcmRepresentationParameter *toRepParam,
                                                      const DJCodecParameter *cp,
                                                      Uint8 bitsPerSample) const
{
    return new DJCompress2K(*cp, EJM_2k_lossless, bitsPerSample);
}


