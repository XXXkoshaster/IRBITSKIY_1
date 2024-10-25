cmake_minimum_required(VERSION 3.10)

project(task_2_10 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_2_10 ./src/funcs.c ./src/utils_2_10.c ./src/main_2_10.c)

target_include_directories(task_2_10 PRIVATE ./include)