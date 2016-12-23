cmake_minimum_required(VERSION 3.6)
project(E12C5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wall -Wextra -std=c++14")

set(SOURCE_FILES main.cpp)
add_executable(E12C5 ${SOURCE_FILES})