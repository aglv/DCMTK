#ifndef DJENC2K_H
#define DJENC2K_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djcodece.h" /* for class DJCodecEncoder */

class DJEncoder2K : public DJCodecEncoder {
public: 

    DJEncoder2K() : DJCodecEncoder() {}
    virtual ~DJEncoder2K() {}

    virtual E_TransferSyntax supportedTransferSyntax() const { return EXS_JPEG2000; }

private:

    virtual OFBool isLosslessProcess() const { return OFFalse; }

    virtual void createDerivationDescription(const DcmRepresentationParameter *toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample,
                                             double ratio,
                                             OFString& derivationDescription) const;

    virtual DJEncoder *createEncoderInstance(const DcmRepresentationParameter *toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample) const;
};

class DJEncoder2KLossless : public DJCodecEncoder {
public: 

    DJEncoder2KLossless() : DJCodecEncoder() {}
    virtual ~DJEncoder2KLossless() {}
    
    virtual E_TransferSyntax supportedTransferSyntax() const { return EXS_JPEG2000LosslessOnly; }

private:

    virtual OFBool isLosslessProcess() const { return OFTrue; }

    virtual void createDerivationDescription(const DcmRepresentationParameter * toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample,
                                             double ratio,
                                             OFString& derivationDescription) const;
    
    virtual DJEncoder *createEncoderInstance(const DcmRepresentationParameter * toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample) const;
};

#endif
