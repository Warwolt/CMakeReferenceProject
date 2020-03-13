cmake_minimum_required(VERSION 3.16)
project(Hello)
include(${CMAKE_SOURCE_DIR}/scripts/cmake/module_util.cmake)

# Source
set(SRC src/hello.cpp)
add_library(hello STATIC ${SRC})

# Unit tests
set(TEST_SRC test/hello_test.cpp)
set_module_name(MODULE_NAME)
add_library(${MODULE_NAME}_test STATIC ${SRC} ${TEST_SRC}) # extract this into a function? or some kind of common file?
target_include_directories(${MODULE_NAME}_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
