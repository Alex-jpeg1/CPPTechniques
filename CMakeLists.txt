cmake_minimum_required(VERSION 3.20)

project(Catch)

set(INCLUDE_PATHS extern/Catch2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Catch catch.cpp)

#target_include_directories(Catch PUBLIC ${INCLUDE_PATHS})

add_subdirectory(${INCLUDE_PATHS})

target_link_libraries(Catch PRIVATE Catch2::Catch2WithMain)

