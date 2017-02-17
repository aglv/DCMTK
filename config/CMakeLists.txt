# declare project
PROJECT(config)

# declare include directories which hold for all subdirectories
INCLUDE_DIRECTORIES(${config_SOURCE_DIR}/include)

# recurse into subdirectories
FOREACH(SUBDIR include docs)
  ADD_SUBDIRECTORY(${SUBDIR})
ENDFOREACH(SUBDIR)
