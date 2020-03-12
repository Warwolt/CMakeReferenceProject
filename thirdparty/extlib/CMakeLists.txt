# This is a script file for the 'third party mock' called extlib
cmake_minimum_required(VERSION 3.16)
project(Extlib)

add_library(extlib INTERFACE) # header only --> interface
target_include_directories(extlib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
