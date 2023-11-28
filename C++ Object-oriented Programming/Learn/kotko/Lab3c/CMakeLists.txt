cmake_minimum_required(VERSION 3.0)
project(Lab3)

add_library(binary binary.cpp binary.h)
add_library(cipher cipher.cpp)
add_library(mystring mystring.cpp)
add_library(xor xor.cpp)

add_executable(exec main.cpp)
target_link_libraries(exec binary cipher mystring xor)
