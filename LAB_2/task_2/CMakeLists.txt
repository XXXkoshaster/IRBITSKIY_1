cmake_minimum_required(VERSION 3.10)

project(task_2_2 C)

set(CMAKE_C_STANDARD 99)

set(ASAN_FLAGS "-fsanitize=address -g")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${ASAN_FLAGS}")

add_executable(task_2_2 task_2.c functions_2.c)
