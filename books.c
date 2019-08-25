/*
// Created by ahmad on 7/29/19.
*/

#define MIN(a,b) (((a)<(b))?(a):(b))


#include "books.h"

static char* types_arr[5] =  {"KIDS", "HIGHSCHOOL", "ADULT", "DOCUMENTARY", "COMICS"};
extern Book books[];
char* get_zone_name(zone_type type){

    return types_arr[type] ;

}



void print_book(Book *book){
    char* temp = get_genre_info(book->_genre, book->gt);

    printf(BOOK_DETAILS_MESSAGE);
    printf(BOOK_NAME_FORMAT, book->name);
    printf(BOOK_NUM_FORMAT, book->book_num);
    printf(BOOK_PROM_FORMAT, book->promotion);
    printf(ZONE_TYPE_FORMAT, get_zone_name(book->zone));
    printf(GENRE_INFO_FORMAT,temp);
    free(temp);
}


void print_copy(BookCopy *book){
    printf(BOOK_INTERNAL_NUM_FORMAT, book->internal_book_num);
    printf(BOOK_SERIAL_NUM_FORMAT, book->serial_num);
    printf(IS_BORROWED_FORMAT, book->is_borrowed ? "Yes":"No");
    printf(BORROWING_TIMES_FORMAT, book->borrowing_times);
    printf(BOOK_COND_FORMAT);
    if(is_librarian_required(book)){
        printf(LIBRARIAN_MESSAGE);
    }
    if(is_bookbinder_required(book)){
        printf((BOOKBINDER_MESSAGE));
    }
    if(is_repairable(book)){
        printf(REPAIRABLE_MESSAGE);
    }
    if(is_ok(book)){
        printf(OK_COND_MESSAGE);
    }
    if(is_useless(book)){
        printf(USELESS_MESSAGE);
    }
}


int borrow_copy(BookCopy *book_copy, bool is_borrowing ){
    if(is_borrowing == book_copy->is_borrowed){
        fprintf(stderr, BORROWING_ERROR_MESSAGE);
        return -1;
    }
    book_copy->borrowing_times++;


    book_copy->is_borrowed = is_borrowing;
    return 0;
}

void init_copy(BookCopy *book, int internal_numm){
    static int current_serial_num = FIRST_SERIAL_NUM;
    book->internal_book_num = internal_numm;
    book->serial_num = current_serial_num;
    current_serial_num++;
    book->is_borrowed = false;
    book->borrowing_times = 0;
    book->condition = ZERO_BITS;
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
        new_book->condition |= missing_pages_mask;
    }
    if(stained_pages_problem){
        new_book->condition |= stained_pages_mask;
    }
}

BookCopy* create_copy(int internal_num, bool cover_problem, bool indexing_problem, bool bar_code_problem,
                      bool spine_pages_problem, bool missing_pages_problem, bool stained_pages_problem){

    BookCopy *new_book;


    if(0 > internal_num || internal_num > 50000){
        printf(INVALID_INTERNAL_NUM_MESSAGE);
        return NULL;
    }

    new_book = (BookCopy*)malloc(sizeof(BookCopy));
    init_copy(new_book, internal_num);

   update_book_condition(new_book,cover_problem, indexing_problem, bar_code_problem,
           spine_pages_problem, missing_pages_problem, stained_pages_problem);

    return new_book;
}


bool is_librarian_required(BookCopy* book){
    return book->condition & cover_mask || book->condition & indexing_mask || book->condition & bar_code_mask;
}


bool is_bookbinder_required(BookCopy* book){
    return book->condition & missing_pages_mask || book->condition & spine_pages_mask
                                                || book->condition & stained_pages_mask;
}

bool is_repairable(BookCopy* book){
    return !(book->condition & missing_pages_mask || book->condition & stained_pages_mask);
}


bool is_ok(BookCopy* book){
    return book->condition == 0;
}

bool is_useless(BookCopy* book){
    int j;
    int mask =1;
    int counter = 0;
    for(j = 0; j < 6; j++){
        if(book->condition & mask){
            counter++;
        }
        mask *= 2;
    }
    return counter >= 4;
}

bool are_in_same_condition(BookCopy* book1, BookCopy* book2){
    return (book1->condition ^ book2->condition) == 0;
}

void get_nice_book_name(char *dst, char *src) {
    int i;

    if( src[0] >= 'a' && src[0] <= 'z'){
        dst[0] = (char) ((int) src[0] - 32);
    }else{
        dst[0] = src[0] ;
    }
    for (i = 1; src[i]!='\0'; i++) {
        if(src[i] >= 'A' && src[i] <= 'Z') {
            dst[i] = (char) ((int) src[i] + 32);
        }else{
            dst[i] = src[i];
        }
    }
    dst[i] = '\0';
}

char * get_genre_info(genre g, genre_type gt) {
    char* genre_info_buff = (char*)malloc(sizeof(char)*100);


    if(gt == 0){
        sprintf(genre_info_buff, "text quality = %d, plot quality = %d\n",
                g._DRAMA.text_quality, g._DRAMA.plot_quality);
    }else if(gt == 1){
        sprintf(genre_info_buff, "thrilling factor = %f\n", g._THRILLER);
    }else if(gt == 2){
        sprintf(genre_info_buff, "humor quality = %d, humor type = %c\n",
                g._COMEDY.humor_quality, g._COMEDY.humor_type);
    }else{
        sprintf(genre_info_buff, "non fiction filed = %s\n",g._NON_FICTION);
    }

    return genre_info_buff;
}

void print_nicely(const struct Book* pbook){
    char* dst = (char*)malloc(sizeof(pbook->name));
    get_nice_book_name(dst, pbook->name);
    printf("%s\n", dst);
    free(dst);
}

void print_non_fiction(const struct Book* pbook){
    if(pbook->gt == NON_FICTION){
        print_nicely(pbook);
        printf("non fiction filed  = %s\n",pbook->_genre._NON_FICTION);
    }
}

void print_most_promoted(const struct Book* pbook){
        if(pbook->promotion > 50){
            print_book(pbook);
        }
    }


int get_min_promotion(Book* books)
{
    int i;
    int min_promotion = books->promotion;

    for(i = 1; i < num_of_books(); i++ ){
            min_promotion = MIN((books+i)->promotion,min_promotion) ;

    }
    return min_promotion;
}

float get_min_thrilling_factor(Book* books)
{
    int i;
    float min_thrilling_factor = 0.5f;

    for(i = 1; i < num_of_books(); i++ ){
        if ((books+i)->gt == THRILLER){
            min_thrilling_factor = MIN((books+i)->_genre._THRILLER, min_thrilling_factor) ;
        }
    }
    return min_thrilling_factor;
}

