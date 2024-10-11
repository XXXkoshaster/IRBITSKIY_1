cmake_minimum_required(VERSION 3.10)

project(task_1_9 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_1_9 task_9.c functions_9.c)
target_link_libraries(task_1_9 m)