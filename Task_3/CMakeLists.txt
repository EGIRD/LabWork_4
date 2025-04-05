cmake_minimum_required(VERSION 3.28.3)
project(Task_3)

set(CMAKE_CXX_STANDARD 17)

# Включаем все исходники
add_executable(Task_3
    src/calculate_Mediums.cpp
    main.cpp
)

# Подключаем заголовки
target_include_directories(Task_3 PRIVATE include)