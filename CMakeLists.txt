cmake_minimum_required(VERSION 3.16)
project(HelloCmake)

# Force out-of-source builds
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR
    "\nIn-source compilation is not allowed!\n"
    "Create a build directory and run \"cmake ..\" from there. You might have "
    "to remove the generated CMakeCache.txt file and CMakeFiles directory.")
endif()

# Set binaries to be generated here
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Add compile modules
add_subdirectory(thirdparty/extlib)
add_subdirectory(software) # contains release target
