project(scope_test LANGUAGES CXX C)
cmake_minimum_required(VERSION 3.16)

add_executable(${PROJECT_NAME} main.cpp customType.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../c_code)

target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../c_code)
target_link_libraries(${PROJECT_NAME} PRIVATE mylib)