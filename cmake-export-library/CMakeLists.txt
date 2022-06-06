project(ExportedLibrary LANGUAGES CXX)
cmake_minimum_required(VERSION 3.16)

# For CPack usage
include(CPack)
set(CMAKE_DEBUG_POSTFIX d)

# Targets
add_library(${CMAKE_PROJECT_NAME})
target_sources(${CMAKE_PROJECT_NAME}
    PRIVATE
        src/interface.cpp)

target_include_directories(${CMAKE_PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# For cmake --install usage
install(TARGETS ${CMAKE_PROJECT_NAME} EXPORT ${CMAKE_PROJECT_NAME}Targets
    LIBRARY  DESTINATION lib
    ARCHIVE  DESTINATION lib
    RUNTIME  DESTINATION bin
    INCLUDES DESTINATION include)

install(EXPORT ${CMAKE_PROJECT_NAME}Targets
    FILE ${CMAKE_PROJECT_NAME}Targets.cmake
    NAMESPACE MyLib::
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(${CMAKE_PROJECT_NAME}ConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/Config.cmake.in
    "${CMAKE_PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "lib/cmake/${CMAKE_PROJECT_NAME}"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO
    )

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}ConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_PROJECT_NAME}Config.cmake
    DESTINATION lib/cmake/${CMAKE_PROJECT_NAME})

install(
    FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/interface.hpp
    DESTINATION include)