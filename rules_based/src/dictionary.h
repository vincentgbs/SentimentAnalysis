#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>   /* gets */
#include <stdlib.h>  /* atoi, malloc */
#include <string.h>  /* strcpy */
#include "../library/uthash.h"

#define WORDLEN 50
// #define DICTLEN 86486 // 86487 lines with header

struct my_struct {
    char id[WORDLEN]; // [0]
    int Negative; // [7]
    int Positive; // [8]
    int Uncertainty; // [9]
    int Litigious; // [10]
    int Constraining; // [11]
    int Superfluous; // [12]
    int Interesting; // [13]
    int Modal; // [14]
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *dictionary = NULL;

void add_record(char *word, int neg, int pos, int uncert,
    int litig, int constrain, int superf, int interest, int modal) {
    struct my_struct *s;

    HASH_FIND_INT(dictionary, word, s);  /* id already in the hash? */
    if (s==NULL) {
        s = (struct my_struct *)malloc(sizeof *s);
        strcpy(s->id, word);
        s->Negative = neg;
        s->Positive = pos;
        s->Uncertainty = uncert;
        s->Litigious = litig;
        s->Constraining = constrain;
        s->Superfluous = superf;
        s->Interesting = interest;
        s->Modal = modal;
        HASH_ADD_INT( dictionary, id, s );  /* id: name of key field */
    }
}

struct my_struct *find_record(char *word) {
    struct my_struct *s;

    HASH_FIND_INT( dictionary, word, s );  /* s: output pointer */
    return s;
}

void print_dictionary() {
    struct my_struct *s;

    for(s=dictionary; s != NULL; s=(struct my_struct*)(s->hh.next)) {
        printf("word %s: pos %d, neg %d, uncert %d, lit %d, mod %d \n",
            s->id, s->Positive, s->Negative, s->Uncertainty, s->Litigious, s->Modal);
    }
}

#endif // DICTIONARY_H
