cmake_minimum_required(VERSION 3.10)

project(task_2_4 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_2_4 ./src/task_2_4.c ./src/convex.c ./src/gorner.c ./src/kaprekar.c ./src/helping_functions_2_4.c)

target_include_directories(task_2_4 PRIVATE ./include)