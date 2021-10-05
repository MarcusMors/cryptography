project("cryptography_examples")

add_executable("${PROJECT_NAME}_caesar" caesar.cpp)

target_link_libraries("${PROJECT_NAME}_caesar" PUBLIC C_caesar)
