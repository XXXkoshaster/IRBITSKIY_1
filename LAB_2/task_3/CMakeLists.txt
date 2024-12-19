cmake_minimum_required(VERSION 3.10)

project(task_2_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_2_3 ./src/task_3.c ./src/main_functions_3.c)

target_include_directories(task_2_3 PRIVATE ./include)