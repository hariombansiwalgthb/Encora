cmake_minimum_required(VERSION 3.16)
project(graph_lib)

# Set the required C++ version
set(CMAKE_CXX_STANDARD 17)  # Set C++17 (or 20 for C++20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforces the C++ version
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

#add_compile_options(-Wall -Wextra)

add_library(${PROJECT_NAME} SHARED src/graph.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

add_library(${PROJECT_NAME}_static STATIC src/graph.cpp)
target_include_directories(${PROJECT_NAME}_static PUBLIC include)


export(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_static FILE ${CMAKE_BINARY_DIR}/CMakeExports.cmake)