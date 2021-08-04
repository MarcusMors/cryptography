cmake_minimum_required (VERSION 3.0)

project(abstract_algebra)

add_library(
	affine
	include/cryptography/affine.hpp
	src/cryptography/affine.cpp
)
add_library(
	cesar
	include/cryptography/cesar.hpp
	src/cryptography/cesar.cpp
)
add_library(
	scytale
	include/cryptography/scytale.hpp
	src/cryptography/scytale.cpp
)

add_library(
	rail_fence
	include/cryptography/rail_fence.hpp
	src/cryptography/rail_fence.cpp
)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -Wpedantic)
endif(MSVC)

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(affine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} PRIVATE affine cesar scytale rail_fence)

# # Add sub directories
# add_subdirectory(include) # public interfaces
# add_subdirectory(src) # private interfaces and .m
# # add_subdirectory(libs) # third party libraries and own libraries
