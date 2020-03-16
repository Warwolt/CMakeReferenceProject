cmake_minimum_required(VERSION 3.16)
project(HelloCmake)

# Force out-of-source builds (i.e don't allow building in project root)
if(${PROJECT_SOURCE_DIR} STREQUAL ${PROJECT_BINARY_DIR})
    message(FATAL_ERROR
    "\nIn-source compilation is not allowed!\n"
    "Create a build directory and run \"cmake ..\" from there. You might have "
    "to remove the generated CMakeCache.txt file and CMakeFiles directory.")
endif()

# Download and integrate Google Test
include(scripts/cmake/googletest_integrate.cmake)
include_directories(${PROJECT_BINARY_DIR}/googletest-src/googletest/include)
include_directories(${PROJECT_BINARY_DIR}/googletest-src/googlemock/include)
enable_testing() # Needed?

# Set compiler options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Output binaries in build directory root
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Add compile modules
add_subdirectory(thirdparty/extlib)
add_subdirectory(software) # contains release target
