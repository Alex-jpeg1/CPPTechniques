Cmake_minimum_required(VERSION 3.20)

project(DangerousCStyleCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(DangerousCStyleCode main.cpp)

target_compile_options(DangerousCStyleCode PUBLIC -Wall -Wextra -Wpedantic)


