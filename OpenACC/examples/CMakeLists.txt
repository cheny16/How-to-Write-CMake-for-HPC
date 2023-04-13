cmake_minimum_required(VERSION 3.1)
# Set project name as `hello_acc`
set(PROJECT_NAME hello_acc)
# Set project
project(${PROJECT_NAME})

# Detect compiler
# PGI compiler
if (CMAKE_C_COMPILER_ID MATCHES "PGI")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -alias=ansi")
# GCC compiler
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fstrict-aliasing")
endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

# Find OpenACC
find_package(OpenACC)

# Variable ACC_VERBOSE for printing compiler feedback
if (NOT ACC_VERBOSE)
    set(ACC_VERBOSE true)
endif (NOT ACC_VERBOSE)
# Set verbose according to compiler
if (CMAKE_C_COMPILER_ID MATCHES "PGI")
    set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -Minfo=accel")
elseif (CMAKE_C_COMPILER_ID MATCHES "GNU")
   set(OpenACC_C_VERBOSE "${OpenACC_C_VERBOSE} -fopt-info-optimized-omp")
endif (CMAKE_C_COMPILER_ID MATCHES "PGI")

if (ACC_VERBOSE)
    set(OpenACC_C_FLAGS "${OpenACC_C_FLAGS} ${OpenACC_C_VERBOSE}")
endif()

# Add the executable
add_executable(${PROJECT_NAME} hello_acc.c)
# Set compile flags
set_source_files_properties(hello_acc.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
# Set link flags
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")

# Add clean target
add_custom_target(distclean COMMAND rm -rf CMakeCache.txt CMakeFiles 
                  Makefile cmake_install.cmake CTestTestfile.cmake)