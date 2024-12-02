cmake_minimum_required(VERSION 3.16)
project(Application)

# Set the required C++ version
set(CMAKE_CXX_STANDARD 17)  # Set C++17 (or 20 for C++20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforces the C++ version
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

#add_compile_options(-Wall -Wextra)

add_executable(${PROJECT_NAME} main.cpp)

find_package(graph_lib REQUIRED)
find_package(clock_lib REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE graph_lib::graph_lib clock_lib::clock_lib)

