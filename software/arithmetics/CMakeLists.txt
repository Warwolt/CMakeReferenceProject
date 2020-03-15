cmake_minimum_required(VERSION 3.16)
include(${CMAKE_SOURCE_DIR}/scripts/cmake/module_util.cmake)
project(Arithmetics)

add_module_library(MODULE SOURCES add.cpp)
add_module_library(TEST SOURCES add_test.cpp)
