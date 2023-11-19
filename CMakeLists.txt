# Standard options
cmake_minimum_required(VERSION 3.17...3.24)
project(ConsoleDonutProject
    VERSION 1.0 
    DESCRIPTION "Prints spinning donut in the console" 
    LANGUAGES CXX
)

# Create executable code
add_executable(TorusMain src/main.cpp)

# Add libraries
add_subdirectory(src)

# Link library with needed classes to executable code
target_link_libraries(TorusMain PRIVATE TorusLib)

# Setting C++17 as standard for TorusMain compilation
set_target_properties(TorusMain PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# GTEST
enable_testing()
include(GoogleTest)
add_subdirectory(tests)

