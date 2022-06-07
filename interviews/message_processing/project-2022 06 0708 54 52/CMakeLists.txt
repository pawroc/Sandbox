project(message_handler LANGUAGES CXX)
cmake_minimum_required(VERSION 3.23)

# Application
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

# Tests
enable_testing()
set(test_exe_name ${CMAKE_PROJECT_NAME}_test)
add_executable(${test_exe_name} test/test.cpp)
target_link_libraries(${test_exe_name} PRIVATE gtest_maind gtestd pthread)

include(GoogleTest)
gtest_discover_tests(${test_exe_name} TEST_PREFIX)