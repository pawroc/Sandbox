project(library LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_library(${PROJECT_NAME} lib.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)