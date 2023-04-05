# CMakeLists for MPI Programs

## Syntax
To write a CMakeLists.txt for your MPI programs:
1. Find: `find_package` to find the MPI package;
2. Include: `target_include_directories` to include MPI include path;
3. Compile: `target_compile_options` to set MPI compile flag
4. Link: `target_link_libraries` to link the MPI library to the executable

For example, for a C program:
```cmake
# Find MPI
find_package(MPI REQUIRED)
# Check if found
if (MPI_FOUND)
    # Add include path for mpi.h
    target_include_directories(${PROJECT_NAME} PRIVATE ${MPI_C_INCLUDE_PATH})
    # Set MPI compile flag
    target_compile_options(${PROJECT_NAME} PRIVATE ${MPI_C_COMPILE_FLAGS})
    # Link the MPI library to the executable
    target_link_libraries(${PROJECT_NAME} PUBLIC ${MPI_C_LIBRARIES} ${MPI_C_LINK_FLAGS})
else()
    message(FATAL_ERROR "MPI not found.\n")
endif()
```

For C++ program, just replace `C` with `CXX`:
```cmake
# Find MPI
find_package(MPI REQUIRED)
# Check if found
if (MPI_FOUND)
    # Add include path for mpi.h
    target_include_directories(${PROJECT_NAME} PRIVATE ${MPI_CXX_INCLUDE_PATH})
    # Set MPI compile flag
    target_compile_options(${PROJECT_NAME} PRIVATE ${MPI_CXX_COMPILE_FLAGS})
    # Link the MPI library to the executable
    target_link_libraries(${PROJECT_NAME} PUBLIC ${MPI_CXX_LIBRARIES} ${MPI_CXX_LINK_FLAGS})
else()
    message(FATAL_ERROR "MPI not found.\n")
endif()
```

## Useful Links
[CMake-module: FindMPI](https://cmake.org/cmake/help/latest/module/FindMPI.html)
