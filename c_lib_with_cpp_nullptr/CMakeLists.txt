project(nullptrCLib LANGUAGES CXX C)
cmake_minimum_required(VERSION 3.16)

add_executable(prg main.cpp)
target_link_directories(prg PRIVATE c_lib)
target_link_libraries(prg PRIVATE c_lib)
target_include_directories(prg PRIVATE c_lib)