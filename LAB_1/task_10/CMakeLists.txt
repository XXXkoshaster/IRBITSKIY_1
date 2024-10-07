cmake_minimum_required(VERSION 3.10)

project(TASK_10 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_10 task_10.c functions_10.c)
target_link_libraries(TASK_10 m)