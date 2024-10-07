cmake_minimum_required(VERSION 3.10)

project(TASK_3 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_3 task_3.c functions_3.c flags_3.c)
target_link_libraries(TASK_3 m)