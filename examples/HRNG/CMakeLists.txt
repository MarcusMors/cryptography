project("hrng_examples")

add_executable("${PROJECT_NAME}_unix" unix.cpp)

target_link_libraries("${PROJECT_NAME}_unix" PUBLIC HRNG_unix)
