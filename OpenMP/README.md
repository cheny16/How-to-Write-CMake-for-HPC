# CMakeLists for OpenMP Programs
## Basic Structure

To write a CMakeLists.txt for your OpenMP programs, just: 
1. Use `find_package` to find the OpenMP package;
2. Use `target_link_libraries` to link to the executable;
3. Use `target_compile_options` to set OpenMP compile flag. 

For example:

```cmake
# Find OpenMP
find_package(OpenMP)
# Check if found
if (OpenMP_C_FOUND)
    # Link the OpenMP library to the executable
    target_link_libraries(executable PUBLIC OpenMP::OpenMP_C)
    # Set OpenMP compile flag
    target_compile_options(executable PRIVATE ${OpenMP_C_FLAGS})
else()
    message(WARNING "OpenMP not found.\n")
endif()
```
For C++ program:
```cmake
find_package(OpenMP)
# Check if found
if (OpenMP_CXX_FOUND)
    # Link the OpenMP library to the executable
    target_link_libraries(executable PUBLIC OpenMP::OpenMP_CXX)
    # Set OpenMP compile flag
    target_compile_options(executable PRIVATE ${OpenMP_CXX_FLAGS})
else()
    message(WARNING "OpenMP not found.\n")
endif()
```

You could also set OpenMP as `REQUIRED`:
```cmake
find_package(OpenMP REQUIRED)
if (NOT OpenMP_C_FOUND)
    message(FATAL_ERROR "OpenMP required.\n")
endif()
```

Note that if you're using CMake version >= 3.9, you might not need to explicitly set the `target_compile_options` for `OpenMP_C_FLAGS` when using the `target_link_libraries` command with the `OpenMP::OpenMP_C`. The reason is that starting from CMake 3.9, the OpenMP flags are automatically propagated through the imported target when you link against it. However, it's still a good practice to add the compile options explicitly for compatibility.

## Another Way
Another way is by using `set_target_properties`, for example:
```cmake
set_target_properties(executable PROPERTIES COMPILE_FLAGS ${OpenMP_C_FLAGS})
set_target_properties(executable PROPERTIES LINK_FLAGS "${OpenMP_C_FLAGS}")
```

Both of them would work well. In general, it is recommended to use the `target_link_libraries` approach with imported targets (e.g., `OpenMP::OpenMP_C`) as it is more idiomatic, easier to use, and more portable. `set_target_properties(LINK_FLAGS)` is less portable between different compilers and platforms.

