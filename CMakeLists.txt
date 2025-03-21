cmake_minimum_required(VERSION 3.10)

# Set variables for global usage or project
set(PROJECT_NAME cristian_marcu_21032025)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
#set(CMAKE_CXX_COMPILER gcc-14)
set(CMAKE_BUILD_TYPE Debug)

project(${PROJECT_NAME})

# Set source files(.cpp and hpp)
set(SOURCES 
    main.cpp
    ComputePipeline.cpp
    CompressedData.cpp
    ImageDecoder.cpp
    )

# Createas an executable file
add_executable(${PROJECT_NAME} ${SOURCES})

# Add include directories 
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Link libraries
# target_link_libraries(${PROJECT_NAME} /usr/local/lib/)

# Compiler Warnings (Optional: Add strict warnings for better code quality)
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()
