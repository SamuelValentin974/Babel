# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "Babel_autogen"
  "CMakeFiles\\Babel_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Babel_autogen.dir\\ParseCache.txt"
  )
endif()
