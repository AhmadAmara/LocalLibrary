cmake_minimum_required(VERSION 3.14)
project(pre-course-1-c-AhmadAmara C)

set (CMAKE_C_FLAGS "-std=c89 -Wall -pedantic -Wconversion")


add_executable(pre-course-1-c-AhmadAmara  books_constants.h books.h books.c main.c local_library.h local_library.c)