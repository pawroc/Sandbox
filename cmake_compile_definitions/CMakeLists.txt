project(compile_def_test LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(main main.cpp)

if (TEST_EN)
	# set(TEST_EN ON)
	target_compile_definitions(main PRIVATE TEST_EN)
endif()
