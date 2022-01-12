project(CustomCommand LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

set(EXT_DIR_PREFIX ${CMAKE_BINARY_DIR}/ext_dir)

add_custom_target(ExtDirTarget
    COMMAND ${CMAKE_COMMAND} -S ${CMAKE_CURRENT_LIST_DIR}/../external_dir -B ${EXT_DIR_PREFIX}
    COMMAND ${CMAKE_COMMAND} --build ${EXT_DIR_PREFIX}
    COMMAND ${CMAKE_COMMAND} --install ${EXT_DIR_PREFIX} --prefix ${EXT_DIR_PREFIX}
    COMMENT "Build & install external project: fooLib"
    VERBATIM
)

add_executable(main main.cpp)

list(APPEND CMAKE_PREFIX_PATH ${EXT_DIR_PREFIX})
find_package(fooLib REQUIRED)

message(STATUS "ABCD fooLib_FOUND = ${fooLib_FOUND}")
target_link_libraries(main PRIVATE Lib::fooLib)
