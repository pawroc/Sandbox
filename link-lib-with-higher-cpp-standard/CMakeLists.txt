project(prg LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

target_link_libraries(${PROJECT_NAME} PRIVATE library)

add_subdirectory(lib)