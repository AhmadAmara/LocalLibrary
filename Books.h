/*
// Created by ahmad on 7/29/19.
*/

#ifndef PRE_COURSE_1_C_AHMADAMARA_BOOKS_H
#define PRE_COURSE_1_C_AHMADAMARA_BOOKS_H

#include "books_constants.h"
#include "local_library.h"
#include "stdio.h"
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define cover_mask 0x1
#define indexing_mask 0x2
#define bar_code_mask 0x4
#define spine_pages_mask 0x8
#define missing_pages_mask 0x10
#define stained_pages_mask 0x20


enum zone_type{KIDS, HIGHSCHOOL, ADULT, DOCUMENTARY, COMICS};
typedef enum zone_type  zone_type;

enum genre_type{DRAMA, THRILLER, COMEDY, NON_FICTION};
typedef enum genre_type  genre_type;

typedef struct Book Book;
typedef struct BookCopy BookCopy;

struct BookCopy{
    int internal_book_num;
    int serial_num; /*(10,000—1,000,000,000)*/
    bool is_borrowed; /*true if the book is currently borrowed.*/
    int borrowing_times;
    unsigned int condition: 6;
};

typedef struct DRAMA{
    int text_quality;
    int plot_quality;
}drama;

typedef struct COMEDY{
    int humor_quality;
    char humor_type;
}comedy;

typedef union genre{
    drama _DRAMA;
    float _THRILLER;
    comedy _COMEDY;
    char* _NON_FICTION;
}genre;


struct Book{
    unsigned short book_num; /*internal book number (0—50,000)*/
    char  name[MAX_BOOK_NAME_LEN]; /*no longer than 50 characters*/
    char promotion; /*a number between -100 [less promoted] to 100 [most promoted]*/
    zone_type zone;
    genre _genre;
    genre_type gt;
};


void get_nice_book_name(char* dst, char* src);
void print_non_fiction(const struct Book* pbook);
void print_nicely(const struct Book* pbook);
void print_most_promoted(const struct Book* pbook);
char* get_genre_info(genre g, genre_type gt);

typedef void (*action)(const struct Book*);

void do_for_books(Book **books, unsigned int num, action)
char* get_zone_name(zone_type type);

void print_book(Book *book);

void print_copy(BookCopy *book);

void init_copy(BookCopy *book, int internal_numm);

int borrow_copy(BookCopy *book_copy, bool is_borrowing );

BookCopy* create_copy(int internal_num, bool cover_problem, bool indexing_problem, bool bar_code_problem,
                        bool spine_pages_problem, bool missing_pages_problem, bool stained_pages_problem);

bool is_librarian_required(BookCopy* book);
bool is_bookbinder_required(BookCopy* book);
bool is_repairable(BookCopy* book);
bool is_ok(BookCopy* book);
bool is_useless(BookCopy* book);
bool are_in_same_condition(BookCopy* book1, BookCopy* book2);



#endif /*PRE_COURSE_1_C_AHMADAMARA_BOOKS_H */
