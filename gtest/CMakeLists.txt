project(Test LANGUAGES CXX C)
cmake_minimum_required(VERSION 3.16)

option(DOWNLOAD_GTEST "" OFF)

add_library(foo STATIC foo.cpp)

add_executable(my_prog main.cpp)
target_link_libraries(my_prog PUBLIC foo)

if (BUILD_TESTING)
    if (DOWNLOAD_GTEST)
        include(FetchContent)
        FetchContent_Declare(
            googletest
            URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    else()
        add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/googletest-release-1.11.0)
    endif()

    enable_testing()
    add_executable(testFoo testFoo.cpp)
    target_link_libraries(testFoo PRIVATE gtest_main)
    include(GoogleTest)
    gtest_discover_tests(testFoo
        TEST_PREFIX "moj_prefix"
        TEST_SUFFIX "moj_suffix")
endif()
