add_library(myLib lib.cpp subLib/lib2.cpp)

target_include_directories(myLib
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/subLib
)