cmake_minimum_required(VERSION 3.16)
project(graph_lib)

# Set the required C++ version
set(CMAKE_CXX_STANDARD 17)  # Set C++17 (or 20 for C++20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforces the C++ version
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

#add_compile_options(-Wall -Wextra)

add_library(${PROJECT_NAME} src/graph.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

install(TARGETS ${PROJECT_NAME}
        EXPORT graphConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)

