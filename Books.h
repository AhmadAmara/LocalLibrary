//
// Created by ahmad on 7/29/19.
//

#ifndef PRE_COURSE_1_C_AHMADAMARA_BOOKS_H
#define PRE_COURSE_1_C_AHMADAMARA_BOOKS_H

#include "books_constants.h"
#include <stdbool.h>


enum zone_type{kids, highschool, adult, documentary, commics};

struct Books {
    char  name[MAX_BOOK_NAME_LEN]; //no longer than 50 characters
    int book_num; //internal book number (0—50,000)
    int promotion; //a number between -100 [less promoted] to 100 [most promoted]
    enum zone_type zone;

}book;

struct BookCopy{
    int internal_book_num;
    int serial_num; //(10,000—1,000,000,000)
    bool is_borrowed; //true if the book is currently borrowed.
};



#endif //PRE_COURSE_1_C_AHMADAMARA_BOOKS_H
