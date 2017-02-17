#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djdec2k.h"
#include "dcmtk/dcmjpeg/djcparam.h"
#include "dcmtk/dcmjpeg/djrplol.h"
#include "dcmtk/dcmjpeg/djd2k.h"
#include "dcmtk/dcmdata/dcpixseq.h"

// lossy

OFBool DJDecoder2K::canChangeCoding(const E_TransferSyntax oldRepType,
                                    const E_TransferSyntax newRepType) const
{
    E_TransferSyntax myXfer = supportedTransferSyntax();
    DcmXfer newRep(newRepType);
    if (newRep.isNotEncapsulated() && (oldRepType == myXfer))
        return OFTrue; // decompress requested
    
    if (newRep.getXfer() == EXS_JPEG2000LosslessOnly && (oldRepType == myXfer))
        return OFTrue;
    
    return OFFalse;
}

OFCondition DJDecoder2K::encode(const E_TransferSyntax fromRepType,
                                const DcmRepresentationParameter * fromRepParam,
                                DcmPixelSequence *fromPixSeq,
                                const DcmRepresentationParameter *toRepParam,
                                DcmPixelSequence * & toPixSeq,
                                const DcmCodecParameter * cp,
                                DcmStack & objStack) const
{
    if (fromRepType == EXS_JPEG2000) {
        toPixSeq = new DcmPixelSequence(*fromPixSeq);
        toPixSeq->changeXfer(EXS_JPEG2000LosslessOnly);
        return EC_Normal;
    }
    
    // we don't support re-coding for now.
    return EC_IllegalCall;
}

DJDecoder *DJDecoder2K::createDecoderInstance(const DcmRepresentationParameter * /* toRepParam */,
                                              const DJCodecParameter *cp,
                                              Uint8 bitsPerSample,
                                              OFBool isYBR) const
{
    return new DJDecompress2K(*cp, isYBR);
}

// lossless

OFBool DJDecoder2KLossless::canChangeCoding(const E_TransferSyntax oldRepType,
                                            const E_TransferSyntax newRepType) const
{
    E_TransferSyntax myXfer = supportedTransferSyntax();
    DcmXfer newRep(newRepType);
    if (newRep.isNotEncapsulated() && (oldRepType == myXfer))
        return OFTrue; // decompress requested
    
    if (newRep.getXfer() == EXS_JPEG2000 && (oldRepType == myXfer))
        return OFTrue;
    
    return OFFalse;
}

OFCondition DJDecoder2KLossless::encode(const E_TransferSyntax fromRepType,
                                        const DcmRepresentationParameter * fromRepParam,
                                        DcmPixelSequence *fromPixSeq,
                                        const DcmRepresentationParameter *toRepParam,
                                        DcmPixelSequence * & toPixSeq,
                                        const DcmCodecParameter * cp,
                                        DcmStack & objStack) const
{
    if (fromRepType == EXS_JPEG2000LosslessOnly) {
        toPixSeq = new DcmPixelSequence(*fromPixSeq);
        toPixSeq->changeXfer(EXS_JPEG2000);
        return EC_Normal;
    }
    
    // we don't support re-coding for now.
    return EC_IllegalCall;
}

DJDecoder *DJDecoder2KLossless::createDecoderInstance(const DcmRepresentationParameter * /* toRepParam */,
                                                      const DJCodecParameter *cp,
                                                      Uint8 bitsPerSample,
                                                      OFBool isYBR) const
{
    return new DJDecompress2K(*cp, isYBR);
}
