# Standard options
cmake_minimum_required(VERSION 3.17...3.24)

# Create library with needed classes
add_library(TorusLib STATIC Torus.cpp Torus.h)
target_include_directories(TorusLib PRIVATE Torus.h)
