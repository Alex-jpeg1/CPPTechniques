cmake_minimum_required(VERSION 3.20)

project(GoodOOPPractices)

set(CMAKE_CXX_STANDARD 17)

add_executable(GoodOOPPractices GoodOOPPractices.cpp)

target_compile_options(GoodOOPPractices PUBLIC -Wall)
