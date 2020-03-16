cmake_minimum_required(VERSION 3.16)
project(Software)

# Declare project submodules
set(modules
        hello
        arithmetics)

# Include each submodule
foreach(module IN LISTS modules)
    add_subdirectory(${module})
endforeach()

# Set target dependencies
set(module_targets ${modules}) # module libs named after the modules themselves
set(unit_test_targets ${modules}) # assume each module 'foo' has a 'foo_test'
list(TRANSFORM unit_test_targets APPEND _test) # 'foo' -> 'foo_test'
set(third_party_libs extlib)

# Release target
add_executable(app main.cpp) # todo mark this as a release target
target_link_libraries(app PUBLIC
    ${module_targets}
    ${third_party_libs}
)

# Unit test target
add_executable(tests test_main.cpp)
target_link_libraries(tests PUBLIC
    gtest
    ${module_targets}
    ${unit_test_targets}
    ${third_party_libs}
)
