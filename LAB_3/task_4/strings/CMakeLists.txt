cmake_minimum_required(VERSION 3.10)

project(task_3_4_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_3_4_1 ./src/core.c ./src/main.c ./src/responses.c ./src/utils.c)

target_include_directories(task_3_4_1 PRIVATE ./include)