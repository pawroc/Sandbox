project(App LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

# If a library is not installed in system paths then this
# CMAKE_PREFIX_PATH has to be added where find_package will look for
# a library's <name>Config.cmake file
set(CMAKE_PREFIX_PATH /tmp/install)

find_package(ExportedLibrary 1.0.0 REQUIRED)

add_executable(app)
target_sources(app PRIVATE main.cpp)
target_link_libraries(app PRIVATE MyLib::ExportedLibrary)