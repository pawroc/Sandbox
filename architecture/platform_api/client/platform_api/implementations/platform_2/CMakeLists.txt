project(Platform2_API_Impl LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.16)

set(LIB_NAME Platform2_API_Impl)

add_library(${LIB_NAME} STATIC api_impl.cpp)
add_library(platform_api_impl::platform_2 ALIAS ${LIB_NAME})
