cmake_minimum_required(VERSION 3.10.0)
project(linux_systems_programming)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../lib )

include_directories(include/**)

add_subdirectory(src)
