project(pmr_playground LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(pmr)
target_sources(pmr PRIVATE main.cpp MoreRealisticExample.cpp)
target_link_libraries(pmr PRIVATE fmt::fmt)
target_compile_features(pmr PRIVATE cxx_std_17)

add_subdirectory(fmt)