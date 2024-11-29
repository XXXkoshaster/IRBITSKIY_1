cmake_minimum_required(VERSION 3.12)

project(task_5_1 CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(task_5_1 ./src/main.cpp)

target_include_directories(task_5_1 PRIVATE ./inc)