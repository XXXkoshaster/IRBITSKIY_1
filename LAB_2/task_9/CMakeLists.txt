cmake_minimum_required(VERSION 3.10)

project(task_2_9 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_2_9 ./src/task_2_9.c ./src/main_functions_2_9.c ./src/helping_functions_2_9.c)

target_include_directories(task_2_9 PRIVATE ./include)
