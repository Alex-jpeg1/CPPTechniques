cmake_minimum_required(VERSION 3.20)

project(Macros)

set(CMAKE_CXX_STANDARD 17)

add_executable(Macros MacrosProblems.cpp)

target_compile_options(Macros PUBLIC -Wall)
