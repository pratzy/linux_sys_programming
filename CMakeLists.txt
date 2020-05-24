cmake_minimum_required(VERSION 3.10.0)
project(linux_systems_programming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set (OUTPUT_LIB_DIR ${CMAKE_BINARY_DIR}/../lib)
set (OUTPUT_BIN_DIR ${CMAKE_BINARY_DIR}/../bin)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_BIN_DIR})
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_LIB_DIR})

include_directories(include)

add_subdirectory(src)
add_subdirectory(src_network)

if (BUILD_TESTS)
    add_subdirectory(tests)
endif()
