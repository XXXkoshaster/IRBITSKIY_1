cmake_minimum_required(VERSION 3.10)

project(TASK_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_4 task_4.c functions_4.c flags_4.c)
target_link_libraries(TASK_4 m)