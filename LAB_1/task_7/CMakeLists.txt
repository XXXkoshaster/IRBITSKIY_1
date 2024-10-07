cmake_minimum_required(VERSION 3.10)

project(TASK_7 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_7 task_7.c functions_7.c flags_7.c)
target_link_libraries(TASK_7 m)