project("operations_examples")

add_executable("${PROJECT_NAME}_inverse" inverse.cpp)
add_executable("${PROJECT_NAME}_primitive_roots" primitive_roots.cpp)

target_link_libraries("${PROJECT_NAME}_inverse" PUBLIC O_inverse)
target_link_libraries("${PROJECT_NAME}_primitive_roots"
                      PUBLIC O_primitive_roots)
