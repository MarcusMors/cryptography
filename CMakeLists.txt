# =============================================================================
# Preamble
# =============================================================================

cmake_minimum_required(VERSION 3.12)

project(
  abstract_algebra
  VERSION 1.0.0
  DESCRIPTION
    "c++ Abstract Algebra (Cryptography, PRNG, seed-generation and operations algorithms) library"
  HOMEPAGE_URL https://github.com/MarcusMors/jose-enrique-vilca-campana)

#[============================================================================[
# Project wide setup
#]============================================================================]
option(BUILD_DOC "Build Documentation" OFF)

# variables
set(PROJECT_SOURCE_DIR "src")
set(PROJECT_INCLUDE_DIR "include")

#[============================================================================[
# Main targets built by this project
#]============================================================================]

add_subdirectory(${PROJECT_SOURCE_DIR})
add_subdirectory(${PROJECT_INCLUDE_DIR})
# add_subdirectory(bin) # bad practice modifying or creating your own packaging
# FSH directory
add_subdirectory(examples)

if(BUILD_DOC)
  add_subdirectory(docs-building/docs-doxygen)
endif()

# Things only needed if we are the top level project

# if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR) add_subdirectory(tests)
# add_subdirectory(packaging) endif()
