cmake_minimum_required(VERSION 3.16)
project(Hello)

# Source
set(SRC src/hello.cpp)
add_library(hello STATIC ${SRC})

# Unit tests
set(TEST_SRC test/hello_test.cpp)
add_library(hello_test STATIC ${SRC} ${TEST_SRC})
target_include_directories(hello_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
