cmake_minimum_required(VERSION 3.10)
project(Task_3_PR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(Task_3_PR
              src/calculate_medium.cpp
              src/main.cpp 
              src/sorting.cpp 
              )