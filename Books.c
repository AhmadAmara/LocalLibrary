/*
// Created by ahmad on 7/29/19.
*/

#include "Books.h"
static char* types_arr[5] =  {"KIDS", "HIGHSCHOOL", "ADULT", "DOCUMENTARY", "COMICS"};

char* get_zone_name(enum zone_type type){

    return types_arr[type] ;

}


void print_book(Book *book){
    printf("book name = %s\n", book->name);
    printf("book number = %d\n", book->book_num);
    printf("promotion = %d\n", book->promotion);
    printf("zone_type = %s\n", get_zone_name(book->zone));
}


void print_copy(BookCopy *book){
    printf("internal_book_num = %d\n", book->internal_book_num);
    printf("serial_num number = %d\n", book->serial_num);
    printf("is_borrowed = %s\n", book->is_borrowed ? "true":"false");
}


void borrow_copy(BookCopy *book_copy,bool is_borrowing ){
    if(is_borrowing == book_copy->is_borrowed){
        printf((const char *) stderr, "book is already borrowed while trying to borrow it, or is not borrowed while trying to return it to the library");
        exit(-1);
    }

    book_copy->is_borrowed = is_borrowing;
}

void init_copy(BookCopy *book, int internal_numm){
    static int current_serial_num = 10000;
    book->internal_book_num = internal_numm;
    book->serial_num = current_serial_num;
    current_serial_num++;
    book->is_borrowed = false;

}


