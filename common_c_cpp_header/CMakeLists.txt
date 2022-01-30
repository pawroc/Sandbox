project(main LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(c_client c_client/c_client.c common_lib.c)
target_include_directories(c_client PRIVATE c_client ${CMAKE_CURRENT_LIST_DIR})

add_executable(cpp_client cpp_client/cpp_client.cpp common_lib.cpp)
target_include_directories(cpp_client PRIVATE cpp_client ${CMAKE_CURRENT_LIST_DIR})