/*
// Created by ahmad on 7/29/19.
*/

#include "Books.h"
static char* types_arr[5] =  {"KIDS", "HIGHSCHOOL", "ADULT", "DOCUMENTARY", "COMICS"};

char* get_zone_name(enum zone_type type){

    return types_arr[type] ;

}


void print_book(Book *book){
    printf(" ### book details ### \n");
    printf("book name = %s\n", book->name);
    printf("book number = %d\n", book->book_num);
    printf("promotion = %d\n", book->promotion);
    printf("zone_type = %s\n\n", get_zone_name(book->zone));
}


void print_copy(BookCopy *book){
    printf("internal_book_num = %d\n", book->internal_book_num);
    printf("serial_num number = %d\n", book->serial_num);
    printf("is_borrowed = %s\n", book->is_borrowed ? "true":"false");
    printf("borrowing times = %d\n", book->borrowing_times);

}


void borrow_copy(BookCopy *book_copy,bool is_borrowing ){
    book_copy->borrowing_times++;
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
    book->borrowing_times = 0;
    book->condition = 0;

}


void update_book_condition(BookCopy* new_book, bool cover_problem, bool indexing_problem, bool bar_code_problem,
                           bool spine_pages_problem, bool missing_pages_problem, bool stained_pages_problem){
    if(cover_problem) {
        new_book->condition |= cover_mask;
    }
    if(indexing_problem){
        new_book->condition |= indexing_mask;
    }
    if(bar_code_problem){
        new_book->condition |= bar_code_mask;
    }
    if(spine_pages_problem){
        new_book->condition |= spine_pages_mask;
    }
    if(missing_pages_problem){
        new_book->condition |= missing_pages_problem;
    }
    if(stained_pages_problem){
        new_book->condition |= stained_pages_mask;
    }
}

BookCopy* create_copy(int internal_num, bool cover_problem, bool indexing_problem, bool bar_code_problem,
                      bool spine_pages_problem, bool missing_pages_problem, bool stained_pages_problem){

    BookCopy *new_book;


    if(0 > internal_num || internal_num > 50000){
        printf("Invalid internal number ! ");
        return NULL;
    }

    new_book = (BookCopy*)malloc(sizeof(BookCopy));
    init_copy(new_book, internal_num);

   update_book_condition(new_book,cover_problem, indexing_problem, bar_code_problem,
           spine_pages_problem, missing_pages_problem, stained_pages_problem);

    return new_book;
}


