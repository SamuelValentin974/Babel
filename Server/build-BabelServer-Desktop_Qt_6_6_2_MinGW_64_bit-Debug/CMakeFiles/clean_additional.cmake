# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "BabelServer_autogen"
  "CMakeFiles\\BabelServer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\BabelServer_autogen.dir\\ParseCache.txt"
  )
endif()
