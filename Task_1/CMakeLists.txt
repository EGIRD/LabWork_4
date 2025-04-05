cmake_minimum_required(VERSION 3.10)
project(Task_1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Task_1
              src/binary_search.cpp
              src/main.cpp 
              src/sorter.cpp 
              )