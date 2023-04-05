cmake_minimum_required(VERSION 3.1)
# Set project name as `hello_mpi`
set(PROJECT_NAME hello_mpi)
# Set project
project(${PROJECT_NAME})

# Add the executable
add_executable(${PROJECT_NAME} hello_mpi.c)

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

# Add clean target
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles 
                  Makefile cmake_install.cmake CTestTestfile.cmake)