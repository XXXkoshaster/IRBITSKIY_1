cmake_minimum_required(VERSION 3.10)

project(task_2_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_2_8 ./src/funcs.c ./src/utils_2_8.c ./src/main_2_8.c)

target_include_directories(task_2_8 PRIVATE ./include)