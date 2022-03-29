# This basically could be (or even should be) delivered as a separate project
# and installed somewhere in the filesystem (system or client project filesystem).

project(Platform1_API_Impl LANGUAGES C CXX)
cmake_minimum_required(VERSION 3.16)

set(LIB_NAME Platform1_API_Impl)

add_library(${LIB_NAME} STATIC api_impl.cpp)
add_library(platform_api_impl::platform_1 ALIAS ${LIB_NAME})
