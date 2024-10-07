cmake_minimum_required(VERSION 3.10)

project(TASK_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_5 task_5.c functions_5.c)
target_link_libraries(TASK_5 m)