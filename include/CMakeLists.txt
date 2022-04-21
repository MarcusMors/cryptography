message(STATUS "Creating libraries...")

# add_library(LIB_cryptography cryptography/*.hpp ../src/cryptography/*.cpp)
# add_library(LIB_affine cryptography/affine.hpp ../src/cryptography/affine.cpp)
add_library(HRNG_unix HRNG/unix.hpp ../src/HRNG/unix.cpp)
set_property(TARGET HRNG_unix PROPERTY CXX_STANDARD 20)

add_library(C_caesar cryptography/caesar.hpp ../src/cryptography/caesar.cpp)
set_property(TARGET C_caesar PROPERTY CXX_STANDARD 20)

add_library(C_rsa cryptography/rsa.hpp ../src/cryptography/rsa.cpp)
target_sources(C_rsa INTERFACE "${CMAKE_CURRENT_LIST_DIR}/cryptography/rsa.hpp")
set_property(TARGET C_rsa PROPERTY CXX_STANDARD 20)

# add_library(LIB_scytale cryptography/scytale.hpp
# ../src/cryptography/scytale.cpp) add_library(LIB_rail_fence
# cryptography/rail_fence.hpp ../src/cryptography/rail_fence.cpp)

# add_library(LIB_operations INTERFACE) target_sources(LIB_operations INTERFACE
# "${CMAKE_CURRENT_LIST_DIR}/operations/*.hpp")

add_library(O_module INTERFACE)
target_sources(O_module
               INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/module.hpp")
set_property(TARGET O_module PROPERTY CXX_STANDARD 20)

add_library(O_inverse INTERFACE)
target_sources(O_inverse
               INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/inverse.hpp")
set_property(TARGET O_inverse PROPERTY CXX_STANDARD 20)

add_library(O_primitive_roots INTERFACE)
target_sources(
  O_primitive_roots
  INTERFACE "${CMAKE_CURRENT_LIST_DIR}/operations/primitive_roots.hpp")
set_property(TARGET O_primitive_roots PROPERTY CXX_STANDARD 20)

#[============================================================================[
# Adding libraries to #include
#]============================================================================]

# add_library(gcd INTERFACE) target_sources(gcd operations/gcd.hpp)

# target_include_directories(operations PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

# target_include_directories(LIB_affine PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(HRNG_unix PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(C_caesar PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(C_rsa INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
# target_include_directories(LIB_scytale PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
# target_include_directories(LIB_rail_fence PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_module INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_inverse INTERFACE "${CMAKE_CURRENT_LIST_DIR}")
target_include_directories(O_primitive_roots
                           INTERFACE "${CMAKE_CURRENT_LIST_DIR}")

message(STATUS "Libraries created \t..................... ✔")
