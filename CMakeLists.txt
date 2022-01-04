cmake_minimum_required(VERSION 3.21)
project(Linux_cmd C)

set(CMAKE_C_STANDARD 99)

add_executable(Linux_cmd main.c cmake-build-debug/02more.c 01_1_more.c 01_2_more.c)
