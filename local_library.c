/*
// Created by ahmad on 02/08/2019.
/*/
#include "local_library.h"

Book books[] = {
        {1001, "Sun Don't Shine", 40, ADULT,{{1,2}}, DRAMA},
        {1002, "Irma la dos", -100, DOCUMENTARY,{._THRILLER=1.5}, THRILLER},
        {1003, "Starship Troopers: Invasion", -68, KIDS,{{2,5}}, DRAMA},
        {1004, "Year of the Jellyfish", 5, ADULT, {._COMEDY={.humor_quality=2,.humor_type='N'}}, COMEDY},
        {1005, "After Life", -95, DOCUMENTARY,{._THRILLER=3}, THRILLER },
        {1006, "Rest Stop", 20, HIGHSCHOOL, {._THRILLER=2}, THRILLER},
        {1007, "Wuthering Heights", 56, KIDS, {._NON_FICTION="CHEM"}, NON_FICTION},
        {1008, "New Adventures of Pippi Longstocking", 11, HIGHSCHOOL,{._NON_FICTION="CHEM"}, NON_FICTION},
        {1009, "She Does Not Drink, Smoke or Flirt", 23, KIDS,{._NON_FICTION="HIST"}, NON_FICTION},
        {1010, "F.I.S.T.", 97, HIGHSCHOOL, {{3,0}}, DRAMA},
        {1011, "Cruise", -97, HIGHSCHOOL,{{3,3}}, DRAMA},
        {1012, "Letter to Elia, A", 54, KIDS,{._COMEDY={.humor_quality=2,.humor_type='S'}}, COMEDY},
        {1013, "To Be and to Have", -57, ADULT,{._COMEDY={.humor_quality=2,.humor_type='P'}},COMEDY},
        {1014, "Get Hard", -66, HIGHSCHOOL,{._NON_FICTION="MUSC"}, NON_FICTION},
        {1015, "A Nation's Battle for Life", 51, ADULT, {._THRILLER=5}, THRILLER},
        {1016, "Place Called Chiapas", 76, COMICS,{._COMEDY={.humor_quality=1,.humor_type='O'}}, COMEDY},
        {1017, "A Drama of the Wilderness", 55, COMICS,{{3,4}}, DRAMA},
        {1018, "Ladies Man", 46, ADULT,{{6,6}}, DRAMA},
        {1019, "Film Geek", -100, COMICS,{{10,20}}, DRAMA},
        {1020, "Raining Stones", -83, DOCUMENTARY,{._THRILLER=2.5}, THRILLER}
};

const Book* first_book(){
    return &books[0];
}

int num_of_books(){
    return (sizeof(books)/sizeof(Book));
}

Book* find_book(int internal_num) {

    int i;
    if(0 > internal_num || internal_num > MAX_INTERNAL_NUM){
        printf(INVALID_INTERNAL_NUM_MESSAGE);
        return NULL;
    }
    for (i = 0; i < num_of_books(); i++) {
        if (books[i].book_num == internal_num) {
            return &books[i];
        }
    }
    return NULL;
}

char* get_name_of_book(int internal_num) {

    Book *founded_book = find_book(internal_num);
    if (founded_book) {
        return founded_book->name;
    } else {
        return NULL;

    }
}
