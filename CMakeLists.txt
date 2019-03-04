cmake_minimum_required(VERSION 3.0)
project(pointer-search)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/debug)

include_directories("./include")

add_executable(
    pointer-search
    src/main.c
)

target_link_libraries(pointer-search m)