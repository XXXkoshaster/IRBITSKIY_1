cmake_minimum_required(VERSION 3.10)

project(task_1_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_1_2 task_2.c equations.c rows.c lims.c)
target_link_libraries(task_1_2 m)
