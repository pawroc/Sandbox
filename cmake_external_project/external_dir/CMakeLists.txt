# Reference source: https://cmake.org/cmake/help/latest/manual/cmake-packages.7.html#creating-relocatable-packages

project(extProj LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_library(fooLib
    foo.cpp
    foo2.cpp
)

target_include_directories(fooLib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include2>
    $<INSTALL_INTERFACE:include>
    $<INSTALL_INTERFACE:include/include2>
    $<INSTALL_INTERFACE:include/include>
)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
set(HEADERS
    include/foo.h
    include2/foo2.hpp
)

set(fooLibVersion 1.0.0)
set_property(TARGET fooLib PROPERTY VERSION ${fooLibVersion})
set_property(TARGET fooLib PROPERTY INTERFACE_fooLib_MAJOR_VERSION 3)
set_property(TARGET fooLib APPEND PROPERTY COMPATIBLE_INTERFACE_STRING fooLib_MAJOR_VERSION)

install(TARGETS fooLib EXPORT fooLibTargets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

include(GNUInstallDirs)
set(DIRS include include2)

# This allows to keep directory structure of an original project
foreach(dir ${DIRS})
    install(DIRECTORY ${dir}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${dir}
        FILES_MATCHING
            PATTERN "*.h"
            PATTERN "*.hpp")
endforeach()

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/fooLib/fooLibConfigVersion.cmake"
  VERSION ${fooLibVersion}
  COMPATIBILITY AnyNewerVersion
)

export(EXPORT fooLibTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/fooLib/fooLibTargets.cmake"
  NAMESPACE Lib::
)
configure_file(cmake/fooLibConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/fooLib/fooLibConfig.cmake"
  COPYONLY
)

set(ConfigPackageLocation lib/cmake/fooLib)
install(EXPORT fooLibTargets
  FILE
  fooLibTargets.cmake
  NAMESPACE
    Lib::
  DESTINATION
    ${ConfigPackageLocation}
)
install(
  FILES
    cmake/fooLibConfig.cmake
    "${CMAKE_CURRENT_BINARY_DIR}/fooLib/fooLibConfigVersion.cmake"
  DESTINATION
    ${ConfigPackageLocation}
)