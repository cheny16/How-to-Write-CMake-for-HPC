cmake_minimum_required(VERSION 3.15)
# Set project name as `hello_omp`
set(PROJECT_NAME hello_omp)
# Set project
project(${PROJECT_NAME})

# Add the executable
add_executable(${PROJECT_NAME} hello_omp.c)

# Find OpenMP
find_package(OpenMP)
# Check if found
if (OpenMP_C_FOUND)
    # Link the OpenMP library to the executable
    target_link_libraries(${PROJECT_NAME} PUBLIC OpenMP::OpenMP_C)
    # Set OpenMP compile flag
    target_compile_options(${PROJECT_NAME} PRIVATE ${OpenMP_C_FLAGS})
else()
    message(WARNING "OpenMP not found.\n")
endif()

# Add clean target
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles 
                  Makefile cmake_install.cmake CTestTestfile.cmake)
