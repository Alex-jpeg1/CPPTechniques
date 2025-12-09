cmake_minimum_required(VERSION 3.20)

project(Lambda)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lambda Lambdas.cpp)

target_compile_options(Lambda PUBLIC -Wall)
