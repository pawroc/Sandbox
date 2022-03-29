project(Platform_API LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.16)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE platform_api)

# Here we decide which implementation to use
if (NOT BUILD_TESTING)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE platform_api_impl::platform_1)
add_subdirectory(platform_api/implementations/platform_1)
# Below we can add mock implementation for a whole Platform API
# else()
endif()