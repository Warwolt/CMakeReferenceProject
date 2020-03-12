cmake_minimum_required(VERSION 3.16)
project(Hello)

set(SRC src/hello.cpp) # TODO: check if variables can be lowercase
add_library(hello STATIC ${SRC})
