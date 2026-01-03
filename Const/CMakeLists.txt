cmake_minimum_required(VERSION 3.20)

project(Const)

set(CMAKE_CXX_STANDARD 17)

add_executable(Const Const.cpp)

target_compile_options(Const PUBLIC -Wall)
