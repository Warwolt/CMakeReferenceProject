macro(say_hello)
    message("Hello macro!")
endmacro()

# Assign the name of the current directory to the variable 'name_var'
function(set_module_name name_var)
    get_filename_component(module_name ${CMAKE_CURRENT_SOURCE_DIR} NAME) 
    set(${name_var} ${module_name} PARENT_SCOPE)
endfunction()
