cmake_minimum_required(VERSION 3.10)

project(task_1_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_1_8 task_8.c functions_8.c)
target_link_libraries(task_1_8 m)