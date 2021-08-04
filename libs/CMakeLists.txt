cmake_minimum_required (VERSION 3.0)

project(abstract_algebra)

# Add sub directories
add_subdirectory(include) # public interfaces
add_subdirectory(src) # private interfaces and .m
# add_subdirectory(libs) # third party libraries and own libraries
