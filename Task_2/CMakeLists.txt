cmake_minimum_required(VERSION 3.10)
project(Task_2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 0N)

include_directories(include)
include_directories(src)

add_executable(Task_2  
               src/main.cpp
               src/binpow.cpp 
               src/interpolation_sort.cpp 
               )
