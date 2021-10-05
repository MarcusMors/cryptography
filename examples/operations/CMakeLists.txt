project("operations_examples")

add_executable("${PROJECT_NAME}_inverse" inverse.cpp)

target_link_libraries("${PROJECT_NAME}_inverse" PUBLIC O_inverse)
