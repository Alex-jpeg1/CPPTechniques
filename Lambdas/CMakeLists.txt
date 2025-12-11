cmake_minimum_required(VERSION 3.20)

project(Lambdas)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lambdas Lambdas.cpp)

target_compile_options(Lambdas PUBLIC -Wall)
