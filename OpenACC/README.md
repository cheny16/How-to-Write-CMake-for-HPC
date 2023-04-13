# CMakeLists for OpenACC Programs

## Syntax

To write a `CMakeLists.txt` for your OpenACC programs:

1. Select compiler: compare `CMAKE_C_COMPILER_ID` with compiler IDs, to set different compiling flags;
2. Find: `find_package` to find the OpenACC package;
3. Compile: `set_source_files_properties` to set OpenACC compile flag;
4. Link: `set_target_properties` to link the OpenACC library to the executable.

For example, for a C program:

```cmake
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

# Set compile flags
set_source_files_properties(hello_acc.c PROPERTIES COMPILE_FLAGS "${OpenACC_C_FLAGS}")
# Set link flags
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "${OpenACC_C_FLAGS}")
```
