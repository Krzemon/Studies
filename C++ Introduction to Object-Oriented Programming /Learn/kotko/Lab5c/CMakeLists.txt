cmake_minimum_required(VERSION 3.10)

project(Main)

file(GLOB SOURCES
	src/*.cpp)

add_executable(exec ${SOURCES})
add_custom_target(valgrind 
    COMMAND valgrind --tool=memcheck ./exec
    DEPENDS exec)
