cmake_minimum_required(VERSION 3.16)
project(Software)

add_subdirectory(hello) # can subdirs be added autoamtically from a 'master list' of moduels?

# Release target
add_executable(app main.cpp) # todo mark this as a release target
target_link_libraries(app PRIVATE hello)

# Unit test target
add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE hello hello_test extlib) # use a master list of modules for these dependencies
