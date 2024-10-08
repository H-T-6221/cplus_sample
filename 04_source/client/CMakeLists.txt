cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the project name and version
project(client CXX)

# compile library file
## status src library
set(LOG_NAME
    ../log/log.h
    ../log/log.cpp
    )
add_library(Log STATIC ${LOG_NAME})

# compile executable file
add_executable(client client.cpp)

# link to main
target_link_libraries(client Log)

# set include directory
target_include_directories(client PRIVATE ../log)
target_include_directories(Log INTERFACE ../log/log)
