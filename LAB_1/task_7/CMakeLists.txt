cmake_minimum_required(VERSION 3.10)

project(task_1_7 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_1_7 task_7.c functions_7.c flags_7.c)
target_link_libraries(task_1_7 m)