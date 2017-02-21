# declare additional include directories
INCLUDE_DIRECTORIES(${dcmjpeg_SOURCE_DIR}/include ${ofstd_SOURCE_DIR}/include ${oflog_SOURCE_DIR}/include ${dcmdata_SOURCE_DIR}/include ${dcmimgle_SOURCE_DIR}/include ${dcmimage_SOURCE_DIR}/include ${dcmjpeg_SOURCE_DIR}/libijg8 ${dcmjpeg_SOURCE_DIR}/libijg12 ${dcmjpeg_SOURCE_DIR}/libijg16 ${ZLIB_INCDIR})

# create library from source files
DCMTK_ADD_LIBRARY(dcmjpeg ddpiimpl dipijpeg djcodecd djcodece djcparam djdecbas djdecext djdeclol djdecode djdecpro djdecsps djdecsv1 djdijg12 djdijg8 djdijg16 djeijg12 djeijg8 djeijg16 djencbas djencext djenclol djencode djencpro djencsps djencsv1 djrplol djrploss djutils djdec2k djd2k djenc2k dje2k djopen2k)

DCMTK_TARGET_LINK_MODULES(dcmjpeg ofstd oflog dcmdata dcmimgle dcmimage ijg8 ijg12 ijg16)

IF(DCMTK_WITH_OPENJPEG)
  ADD_DEPENDENCIES(dcmjpeg openjp2)
  INCLUDE_DIRECTORIES(${dcmjpeg_SOURCE_DIR}/OpenJPEG/src/lib ${dcmjpeg_BINARY_DIR}/OpenJPEG/src/lib/openjp2)
ENDIF(DCMTK_WITH_OPENJPEG)
