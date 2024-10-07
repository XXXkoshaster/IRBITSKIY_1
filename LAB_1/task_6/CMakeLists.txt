cmake_minimum_required(VERSION 3.10)

project(TASK_6 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_6 task_6.c functions_6.c)
target_link_libraries(TASK_6 m)