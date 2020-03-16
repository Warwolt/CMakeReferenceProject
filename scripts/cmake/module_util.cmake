##
# Brief: Assign the name of the current directory to the variable 'name_var'
function(get_local_module_name _name_var)
    get_filename_component(module_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    set(${_name_var} ${module_name} PARENT_SCOPE)
endfunction()

##
# Brief: Wrapper to add_library() for module libraries
#
# This macro acts as a wrapper for declaring a library target for a local
# module, and for the module unit tests.
#
# - MODULE:  Flag for adding module source library
# - TEST:    Flag for adding module unit tests library
# - SOURCES: A list of all source files names (e.g. foo.cpp bar.cpp)
# - MODULE_DEPS: List of other modules that this module depends
macro(add_module_library)
    # Parse arguments
    set(options MODULE TEST)
    set(multiValueArgs SOURCES MODULE_DEPS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}"
                          "${multiValueArgs}" ${ARGN})

    # Setup variables and declare library target
    get_local_module_name(MODULE_NAME)
    if(${ARG_MODULE})
        # Module source
        list(TRANSFORM ARG_SOURCES PREPEND src/)
        add_library(${MODULE_NAME} STATIC ${ARG_SOURCES})
        target_include_directories(${MODULE_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
        target_link_libraries(${MODULE_NAME} PUBLIC ${ARG_MODULE_DEPS})
    elseif(${ARG_TEST})
        # Module unit tests
        set(MODULE_TEST_NAME ${MODULE_NAME}_test)
        list(TRANSFORM ARG_SOURCES PREPEND test/)
        add_library(${MODULE_TEST_NAME} STATIC ${ARG_SOURCES})
        target_link_libraries(${MODULE_TEST_NAME} PUBLIC ${MODULE_NAME})
        target_include_directories(${MODULE_TEST_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)
        target_link_libraries(${MODULE_TEST_NAME} PUBLIC ${ARG_MODULE_DEPS})
    endif()
endmacro()
