#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

#define WORDLEN 50
// #define DICTLEN 86486 // 86487 lines with header


struct my_struct {
    int id;            /* we'll use this field as the key */
    char name[WORDLEN];
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *users = NULL;

void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, id, s );
}

struct my_struct *find_user(int user_id) {
    struct my_struct *s;

    HASH_FIND_INT( users, &user_id, s );
    return s;
}

typedef struct {
    char *Word[WORDLEN]; // 0
    char *WordPtr;
    int SequenceNumber;
    int WordCount;
    double WordProportion;
    double AverageProportion;
    double StdDev;
    int DocCount;
    int Negative; // 7
    int Positive; // 8
    int Uncertainty; // 9
    int Litigious; // 10
    int Constraining; // 11
    int Superfluous; // 12
    int Interesting; // 13
    int Modal; // 14
    int Irr_Verb;
    int Harvard_IV;
    int Syllables;
    char *Source;
}  DictRow;

int main() {
    int i, j; // iterators
    char *row[20]; // max 20 columns
    FILE* stream = fopen("LoughranMcDonald_MasterDictionary_2018.csv", "r"); // csv file
    char line[512];
    int max = 0; // max lines (only for testing purposes)

    // add_user(users);

    // while (fgets(line, 512, stream) && (max < 99))
    // {
    //     char* str = strdup(line); // duplicate line as string
    //     char *p = strtok(str, ","); // split line on comas
    //
    //     i = 0;
    //     while (p != NULL)
    //     {
    //         row[i++] = p;
    //         p = strtok(NULL, " ");
    //     }
    //
    //     // DictRow dictRow1 = {};
    //     // dictRow1.WordPtr = dictRow1.Word[0];
    //     // strcpy(dictRow1.WordPtr, row[0]);
    //     // dictRow1.Negative = atoi(row[7]);
    //     // dictRow1.Positive = atoi(row[8]);
    //     // dictRow1.Uncertainty = atoi(row[9]);
    //     // dictRow1.Litigious = atoi(row[10]);
    //     // dictRow1.Constraining = atoi(row[11]);
    //     // dictRow1.Superfluous = atoi(row[12]);
    //     // dictRow1.Interesting = atoi(row[13]);
    //     // dictRow1.Modal = atoi(row[14]);
    //     // printf("Row: saved in dictRow1");
    //     // printf("%s ; %d ; %d ", dictRow1.WordPtr, dictRow1.Negative, dictRow1.Positive);
    //     // printf("\n");
    //
    //     free(str); // deallocate memory from line pointer
    //     max++; // only for testing
    // }

    printf("Done\n");
    return 0;
}
