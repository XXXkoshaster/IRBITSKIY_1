cmake_minimum_required(VERSION 3.10)

project(task_3_10 C)

set(CMAKE_C_STANDARD 99)

add_executable(task_3_10 ./src/main.c ./src/core.c  ./src/responses.c ./src/utils.c)

target_include_directories(task_3_10 PRIVATE ./include)