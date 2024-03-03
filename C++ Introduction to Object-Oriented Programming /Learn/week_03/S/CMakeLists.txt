cmake_minimum_required(VERSION 3.1.0)
project (S03)

# prevent for in-source building
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(SEND_ERROR "In-source builds are not allowed.")
endif ()

add_definitions(-DPROJECTPATH=\"${PROJECT_SOURCE_DIR}\")
################## LAB04 ##################
# Dodaj flagę kompilacji PROCEED_WITH_VERIFICATION
add_definitions(-DPROCEED_WITH_VERIFICATION)

# To jest tylko przykład, jak zdefiniować flagę kompilacji tylko w niektórych konkretnych plikach.
# Jeśli chcesz zdefiniować flagę w całym projekcie, to można to zrobić globalnie.

# Dodaj plik źródłowy do projektu
#add_executable(MyExecutable main.cpp)

# Powiąż flagę kompilacji z wybranymi plikami źródłowymi
#target_compile_definitions(MyExecutable PRIVATE PROCEED_WITH_VERIFICATION)

# Dla wszystkich plików źródłowych można użyć:
# target_compile_definitions(MyExecutable PRIVATE PROCEED_WITH_VERIFICATION)

##########################################
set(CMAKE_BUILD_TYPE Debug) #Release
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
include_directories(${INCLUDES})

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})
