project("cryptography_examples")

add_executable("${PROJECT_NAME}_caesar" caesar.cpp)
add_executable("${PROJECT_NAME}_rsa" rsa.cpp)

target_link_libraries("${PROJECT_NAME}_caesar" PUBLIC C_caesar ${NTL_LIB}
                                                      ${M_LIB} ${GMP_LIB})
target_link_libraries("${PROJECT_NAME}_rsa" PUBLIC C_rsa ${NTL_LIB} ${M_LIB}
                                                   ${GMP_LIB})
