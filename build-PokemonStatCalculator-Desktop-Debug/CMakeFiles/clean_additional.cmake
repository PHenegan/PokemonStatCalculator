# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/PokemonStatCalculator_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/PokemonStatCalculator_autogen.dir/ParseCache.txt"
  "PokemonStatCalculator_autogen"
  )
endif()
