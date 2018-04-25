cmake_minimum_required(VERSION 3.8)
project(iben VERSION 1.2 LANGUAGES CXX)

# https://cmake.org/cmake/help/v3.10/module/FindFLEX.html
find_package(FLEX REQUIRED)
flex_target(input input.ll "${CMAKE_CURRENT_BINARY_DIR}/input.cc")

# https://cmake.org/cmake/help/v3.10/module/FindBISON.html
find_package(BISON REQUIRED)
bison_target(grammar grammar.yy "${CMAKE_CURRENT_BINARY_DIR}/grammar.cc"
  DEFINES_FILE "${CMAKE_CURRENT_BINARY_DIR}/grammar.h")

if(CMAKE_BUILD_STATIC)
  # project() overwrites CMAKE_FIND_LIBRARY_SUFFIXES,
  # therefore the command line is lost and must be set here instead:
  set(CMAKE_FIND_LIBRARY_SUFFIXES .a .dll)
  set(BUILD_SHARED_LIBRARIES OFF)
  set(CMAKE_EXE_LINKER_FLAGS "-static -s")
endif()

find_library(readline_LIBRARY readline)
find_library(termcap_LIBRARY termcap)
find_library(bdd_LIBRARY bdd)

add_executable(iben main.cc shell.cc
  "${CMAKE_CURRENT_BINARY_DIR}/grammar.cc"
  "${CMAKE_CURRENT_BINARY_DIR}/input.cc")

include_directories(iben
  "${CMAKE_SOURCE_DIR}"         # iben.h
  "${CMAKE_CURRENT_BINARY_DIR}" # grammar.h
  )

# https://cmake.org/cmake/help/latest/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
target_compile_features(iben PRIVATE cxx_auto_type)

target_link_libraries(iben
  ${bdd_LIBRARY}
  ${readline_LIBRARY}
  ${termcap_LIBRARY}        # for static linking with readline
  )
