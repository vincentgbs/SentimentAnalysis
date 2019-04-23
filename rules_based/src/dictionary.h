#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../library/uthash.h"

#define WORDLEN 50
#define DICTLEN 86487

struct dictRecord {
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

void add_record(char *word, int neg, int pos, int uncert,
    int litig, int constrain, int superf, int interest, int modal);

struct dictRecord *find_record(char *word);

void print_dictionary();

void loadDictionary(char file[], int max);

#endif // DICTIONARY_H
