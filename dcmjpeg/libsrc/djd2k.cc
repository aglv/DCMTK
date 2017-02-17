#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmjpeg/djd2k.h"
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

OFCondition DJDecompress2K::decode(Uint8 *j2kData,
                                   Uint32 j2kDataSize,
                                   Uint8 *rawData,
                                   Uint32 rawDataSize,
                                   OFBool expectSignedRawData)
{
    return DCMTK_INTEGRATION_CLASS::decodeJ2K((void *)j2kData, j2kDataSize, (void *&)rawData, rawDataSize, expectSignedRawData, _inter);
}
