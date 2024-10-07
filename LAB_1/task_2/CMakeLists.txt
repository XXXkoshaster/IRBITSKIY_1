cmake_minimum_required(VERSION 3.10)

project(TASK_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(TASK_2 task_2.c equations.c rows.c lims.c)
target_link_libraries(TASK_2 m)
