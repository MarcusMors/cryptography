message(STATUS "Creating libraries")

# add_library(LIB_cryptography cryptography/*.hpp ../src/cryptography/*.cpp)
# add_library(LIB_affine cryptography/affine.hpp ../src/cryptography/affine.cpp)
add_library(C_caesar cryptography/caesar.hpp ../src/cryptography/caesar.cpp)
# add_library(LIB_scytale cryptography/scytale.hpp
# ../src/cryptography/scytale.cpp) add_library(LIB_rail_fence
# cryptography/rail_fence.hpp ../src/cryptography/rail_fence.cpp)

# add_library(LIB_operations INTERFACE) target_sources(LIB_operations INTERFACE
# "${CMAKE_CURRENT_LIST_DIR}/operations/*.hpp")

add_library(O_module INTERFACE)
target_sources(O_module
               INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/module.hpp")

add_library(O_inverse INTERFACE)
target_sources(O_inverse
               INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/inverse.hpp")

add_library(O_primitive_roots INTERFACE)
target_sources(
  O_primitive_roots
  INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/primitive_roots.hpp")

#[============================================================================[
# Adding libraries to #include
#]============================================================================]

# add_library(gcd INTERFACE) target_sources(gcd operations/gcd.hpp)

# target_include_directories(operations PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

# target_include_directories(LIB_affine PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(C_caesar PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
# target_include_directories(LIB_scytale PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
# target_include_directories(LIB_rail_fence PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_module INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_inverse INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_primitive_roots INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
