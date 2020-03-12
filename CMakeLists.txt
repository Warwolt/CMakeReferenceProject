cmake_minimum_required(VERSION 3.16)
project(HelloCmake)

# Set binaries to be generated here
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Add compile modules
add_subdirectory(thirdparty/extlib)
add_subdirectory(software) # contains release target
