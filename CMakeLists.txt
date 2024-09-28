cmake_minimum_required(VERSION 3.5)

# Set project and executable names as variables
set(PROJECT_NAME StairLightController)
set(EXECUTABLE_NAME ${PROJECT_NAME})
set(SANITIZED_EXECUTABLE_NAME ${PROJECT_NAME}Sanitized)

# Define project
project(${PROJECT_NAME} LANGUAGES C)

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED YES)

# Collect all source files in the src directory
file(GLOB_RECURSE SOURCES "src/*.c")

# Include the include directory
include_directories(include)

# Add the executable
add_executable(${EXECUTABLE_NAME} ${SOURCES})

# Add the executable with sanitizer flags applied
add_executable(${SANITIZED_EXECUTABLE_NAME} ${SOURCES})
target_compile_options(${SANITIZED_EXECUTABLE_NAME} PRIVATE -fsanitize=address,undefined,leak -fno-omit-frame-pointer)
target_link_options(${SANITIZED_EXECUTABLE_NAME} PRIVATE -fsanitize=address,undefined,leak)
