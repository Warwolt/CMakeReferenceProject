cmake_minimum_required(VERSION 3.16)
include(CMakePrintHelpers)
project(hello_cmake)

# List all sources
set(RELEASE_SOURCES main.cpp)
set(COMMON_SOURCES hello.cpp)
# Add directory prefixes
list(TRANSFORM RELEASE_SOURCES PREPEND ${hello_cmake_SOURCE_DIR}/src/)
list(TRANSFORM COMMON_SOURCES PREPEND ${hello_cmake_SOURCE_DIR}/src/)

# Release target 
add_executable(app ${RELEASE_SOURCES} ${COMMON_SOURCES})
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Unit test target 
add_executable(tests testmain.cpp ${COMMON_SOURCES})
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/inc thirdparty)

# Debugging
# cmake_print_variables(RELEASE_SOURCES)