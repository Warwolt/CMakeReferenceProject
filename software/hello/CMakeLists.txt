cmake_minimum_required(VERSION 3.16)
include(${CMAKE_SOURCE_DIR}/scripts/cmake/module_util.cmake)
project(Hello)

add_module_library(MODULE
    SOURCES
    hello.cpp

    MODULE_DEPS
    arithmetics
)

add_module_library(TEST
    SOURCES
    hello_test.cpp
)
