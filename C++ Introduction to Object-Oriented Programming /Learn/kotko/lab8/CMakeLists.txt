cmake_minimum_required(VERSION 3.10)

project(Subaru)

set(CMAKE_CXX_FLAGS "-Wall -g")

file(GLOB SOURCES
	src/*.cpp)

include_directories( include )

add_executable(exec ${SOURCES})
add_custom_target(valgrind 
    COMMAND valgrind --tool=memcheck ./exec
    DEPENDS exec)
