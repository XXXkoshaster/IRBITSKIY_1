cmake_minimum_required(VERSION 3.10)

project(task_1_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_1_4 task_4.c functions_4.c flags_4.c)
target_link_libraries(task_1_4 m)