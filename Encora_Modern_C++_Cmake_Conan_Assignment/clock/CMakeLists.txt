cmake_minimum_required(VERSION 3.16)
project(clock_lib)

# Set the required C++ version
set(CMAKE_CXX_STANDARD 17)  # Set C++17 (or 20 for C++20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # Enforces the C++ version
set(CMAKE_CXX_EXTENSIONS OFF)  # Disable compiler-specific extensions

#add_compile_options(-Wall -Wextra)

find_package(graph_lib REQUIRED)

add_library(${PROJECT_NAME} src/clock.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC graph_lib)
target_include_directories(${PROJECT_NAME} PUBLIC include ${graph_lib_INCLUDE_DIRS})

install(TARGETS ${PROJECT_NAME}
        EXPORT clockConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include)
install(DIRECTORY include/ DESTINATION include)

