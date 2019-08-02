/*
// Created by ahmad on 8/1/19.
/*/

#include <stdio.h>
#include "local_library.h"


extern Book books[];
extern Book* find_book();



int main(int argc, char** argv) {

    unsigned int book_copies_number;
    unsigned int i;
    int internal_num;
    unsigned int j;
    BookCopy *book_copies;
    Book *needed_book;
    BookCopy *bc;
    int choice;
    printf("Please input the number of book copies you want : ");
    scanf("%u", &book_copies_number);
    book_copies = (BookCopy*)malloc(book_copies_number * sizeof(BookCopy));

    for(i = 0; i < num_of_books(); i++){
        print_book(&books[i]);
    }
    
    for(j = 0; j < book_copies_number; j++){

        printf("Please input an internal book number : ");
        scanf("%d", &internal_num);

        while (0 > internal_num || internal_num > 50000){
            printf("Invalid number ! Please input an internal book number : ");
            scanf("%d", &internal_num);
        }

        needed_book = find_book(internal_num);
        while(needed_book == NULL){
            printf("Invalid number ! Please input an internal book number : ");
            scanf("%d", &internal_num);
            needed_book = find_book(internal_num);
        }

        bc = (BookCopy*)malloc(sizeof(BookCopy));
        init_copy(bc, internal_num);
        book_copies[j] = *bc;
        print_copy(&book_copies[j]);
        free(bc);

    }
    printf("\n%s\n%s\n", "borrowing stage :", "insert a number from the below :");
    printf("1. Borrow a book-copy\n2. Return a book-copy\n9. Exit");
    scanf("%d", &choice);

    /*if(choice == 1){}*/

    return 0;
}
