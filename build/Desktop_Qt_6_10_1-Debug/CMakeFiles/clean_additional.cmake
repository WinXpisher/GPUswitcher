# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/GPUswitcher_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/GPUswitcher_autogen.dir/ParseCache.txt"
  "GPUswitcher_autogen"
  )
endif()
