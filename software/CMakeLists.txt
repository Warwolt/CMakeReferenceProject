cmake_minimum_required(VERSION 3.16)
project(Software)

# List all sources
set(COMMON_SOURCES hello.cpp) # TODO: check if variables can be lowercase
set(RELEASE_ONLY_SOURCES main.cpp)
# set(TEST_SOURCES )

# Add directory prefixes
list(TRANSFORM COMMON_SOURCES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/src/)
list(TRANSFORM TEST_SOURCES PREPEND ${CMAKE_CURRENT_SOURCE_DIR}/test/)

# Release target 
add_executable(app ${RELEASE_ONLY_SOURCES} ${COMMON_SOURCES})
target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Unit test target 
add_executable(tests testmain.cpp ${TEST_SOURCES} ${COMMON_SOURCES})
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)
target_link_libraries(tests PRIVATE extlib)

# # Debugging
# include(CMakePrintHelpers)
# cmake_print_variables(CMAKE_CURRENT_SOURCE_DIR)