# declare project
PROJECT(dcmjpeg)

# recurse into subdirectories
FOREACH(SUBDIR libsrc libijg8 libijg12 libijg16 apps include)
  ADD_SUBDIRECTORY(${SUBDIR})
ENDFOREACH(SUBDIR)

IF(DCMTK_WITH_OPENJPEG)
  ADD_SUBDIRECTORY(OpenJPEG)
ENDIF(DCMTK_WITH_OPENJPEG)