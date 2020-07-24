cmake_minimum_required(VERSION 3.16)
project(student_management C)

set(CMAKE_C_STANDARD 99)

add_executable(student_management main.c student.c)