project(extProj LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

add_library(foo
    foo.cpp
    foo2.cpp
)

target_include_directories(foo PUBLIC
    $<BUILD_INTERFACE:
        ${CMAKE_CURRENT_LIST_DIR}/include
        ${CMAKE_CURRENT_LIST_DIR}/include2>
    $<INSTALL_INTERFACE:include>)

include(GNUInstallDirs)
install(TARGETS foo
    EXPORT ext_dir
    ARCHIVE
        DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(HEADERS
    include/foo.h
    include2/foo2.hpp
)

set(DIRS include include2)

foreach(dir ${DIRS})
    install(DIRECTORY ${dir}/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${dir}
        FILES_MATCHING
            PATTERN "*.h"
            PATTERN "*.hpp")
endforeach()
# install(FILES ${HEADERS}
#     DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(EXPORT ext_dir
    NAMESPACE np::
    DESTINATION cmake
)