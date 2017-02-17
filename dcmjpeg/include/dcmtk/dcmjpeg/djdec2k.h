#ifndef DJDEC2K_H
#define DJDEC2K_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djcodecd.h" /* for class DJCodecDecoder */

class DCMTK_DCMJPEG_EXPORT DJDecoder2K : public DJCodecDecoder {
public:
    
    DJDecoder2K() : DJCodecDecoder() {}
    virtual ~DJDecoder2K() {}

    virtual OFBool isJ2K() const { return OFTrue; }
    
    virtual E_TransferSyntax supportedTransferSyntax() const { return EXS_JPEG2000; }

    virtual OFBool canChangeCoding(const E_TransferSyntax oldRepType,
                                   const E_TransferSyntax newRepType) const;
    
    virtual OFCondition encode(const E_TransferSyntax fromRepType,
                               const DcmRepresentationParameter * fromRepParam,
                               DcmPixelSequence * fromPixSeq,
                               const DcmRepresentationParameter * toRepParam,
                               DcmPixelSequence * & toPixSeq,
                               const DcmCodecParameter * cp,
                               DcmStack & objStack) const;

private:
    
    virtual DJDecoder *createDecoderInstance(const DcmRepresentationParameter * toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample,
                                             OFBool isYBR) const;
};

class DCMTK_DCMJPEG_EXPORT DJDecoder2KLossless : public DJCodecDecoder {
public:
    
    DJDecoder2KLossless() : DJCodecDecoder() {}
    virtual ~DJDecoder2KLossless() {}
  
    virtual OFBool isJ2K() const { return OFTrue; }
    
    virtual E_TransferSyntax supportedTransferSyntax() const { return EXS_JPEG2000LosslessOnly; }
    
    virtual OFBool canChangeCoding(const E_TransferSyntax oldRepType,
                                   const E_TransferSyntax newRepType) const;
  
    virtual OFCondition encode(const E_TransferSyntax fromRepType,
                               const DcmRepresentationParameter * fromRepParam,
                               DcmPixelSequence *fromPixSeq,
                               const DcmRepresentationParameter *toRepParam,
                               DcmPixelSequence * & toPixSeq,
                               const DcmCodecParameter * cp,
                               DcmStack & objStack) const;
	
private:
    
    virtual DJDecoder *createDecoderInstance(const DcmRepresentationParameter * toRepParam,
                                             const DJCodecParameter *cp,
                                             Uint8 bitsPerSample,
                                             OFBool isYBR) const;
};

#endif
