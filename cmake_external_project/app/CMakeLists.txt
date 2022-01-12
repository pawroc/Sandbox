project(CustomCommand LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

set(EXT_DIR_PREFIX ${CMAKE_BINARY_DIR}/ext_dir)

add_custom_target(ExtDirTarget ALL
    COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_LIST_DIR}/../external_dir -B ${EXT_DIR_PREFIX}
    COMMAND ${CMAKE_COMMAND} --build ${EXT_DIR_PREFIX}
    COMMAND ${CMAKE_COMMAND} --install ${EXT_DIR_PREFIX} --prefix ${EXT_DIR_PREFIX}
    COMMENT "ABCD"
    VERBATIM
)

add_executable(main main.cpp)
add_dependencies(main ExtDirTarget)

# get_target_property(LIB_DIR foo FOO_LIB_DIR)

# message(STATUS "ABCD LIB_DIR = ${LIB_DIR}")

# To jest OK
include(GNUInstallDirs)
target_link_directories(main PRIVATE ${EXT_DIR_PREFIX}/${CMAKE_INSTALL_LIBDIR})
target_include_directories(main PRIVATE ${EXT_DIR_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR})

target_link_libraries(main PRIVATE foo)
