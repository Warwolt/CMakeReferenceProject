cmake_minimum_required(VERSION 3.16)
project(HelloCmake)

# Add compile modules
add_subdirectory(thirdparty/extlib)

# List all sources
set(COMMON_SOURCES hello.cpp) # TODO: check if variables can be lowercase
set(RELEASE_SOURCES main.cpp)
set(TEST_SOURCES testmain.cpp)

# Add directory prefixes
list(TRANSFORM RELEASE_SOURCES PREPEND ${HelloCmake_SOURCE_DIR}/src/)
list(TRANSFORM COMMON_SOURCES PREPEND ${HelloCmake_SOURCE_DIR}/src/)
list(TRANSFORM TEST_SOURCES PREPEND ${HelloCmake_SOURCE_DIR}/src/)

# Release target 
add_executable(app ${RELEASE_SOURCES} ${COMMON_SOURCES})
target_include_directories(app PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Unit test target 
add_executable(tests ${TEST_SOURCES} ${COMMON_SOURCES})
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(tests PRIVATE extlib)


# Debugging
# include(CMakePrintHelpers)
# cmake_print_variables(RELEASE_SOURCES)