cmake_minimum_required(VERSION 3.13)
project(hxview)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-fPIC)
add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-pedantic)
add_compile_options(-Wconversion)
add_compile_options(-Werror)
add_compile_options(-Wfatal-errors)

include_directories("src")

file(GLOB_RECURSE HEADER_FILES
        "src/*.h"
        "src/*.hpp"
        )

file(GLOB_RECURSE SOURCE_FILES
        "src/*.c"
        "src/*.cpp"
        "src/*.cxx"
        )

list(REMOVE_ITEM SOURCE_FILES "${CMAKE_SOURCE_DIR}/src/main.cpp")

add_executable(hxview "src/main.cpp" "${SOURCE_FILES}")