/*
// Created by ahmad on 7/29/19.
*/

#ifndef PRE_COURSE_1_C_AHMADAMARA_BOOKS_H
#define PRE_COURSE_1_C_AHMADAMARA_BOOKS_H

#include "books_constants.h"
#include "stdio.h"
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

enum zone_type{KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS};


typedef struct Book Book;
typedef struct BookCopy BookCopy;

struct Book{
    int book_num; /*internal book number (0—50,000)*/
    char  name[MAX_BOOK_NAME_LEN]; /*no longer than 50 characters*/
    int promotion; /*a number between -100 [less promoted] to 100 [most promoted]*/
    enum zone_type zone;

};

struct BookCopy{
    int internal_book_num;
    int serial_num; /*(10,000—1,000,000,000)*/
    bool is_borrowed; /*true if the book is currently borrowed.*/
};


char* get_zone_name(enum zone_type type);

void print_book(Book *book);

void print_copy(BookCopy *book);

void init_copy(BookCopy *book, int internal_numm);

void borrow_copy(BookCopy *book_copy, bool is_borrowing );
#endif /*PRE_COURSE_1_C_AHMADAMARA_BOOKS_H */
