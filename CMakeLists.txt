cmake_minimum_required(VERSION 3.14)
project(pre-course-1-c-AhmadAmara C)

set (CMAKE_C_FLAGS "-std=c89 -Wall -pedantic -Wconversion")


add_executable(pre-course-1-c-AhmadAmara main.c books_constants.h Books.h Books.c myUnitTest.c local_library.h local_library.c)