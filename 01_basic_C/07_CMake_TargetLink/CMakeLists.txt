cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# set the project name and version
project(sample CXX)

# compile executable file
add_executable(sampleApp sample.cpp)

# set include directory
target_include_directories(sampleApp PRIVATE ./util)
