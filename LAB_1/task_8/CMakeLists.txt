cmake_minimum_required(VERSION 3.10)

project(TASK_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_8 task_8.c functions_8.c)
target_link_libraries(TASK_8 m)