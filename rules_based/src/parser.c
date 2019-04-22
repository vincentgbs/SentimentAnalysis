#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h" // FOR TESTING

#define MAXWORDS 100

void parseReview(char line[]) {
    char* str = strdup(line); // duplicate line as string
    char *p = strtok(str, " "); // split line on spaces
    char *row[MAXWORDS]; // max review of MAXWORDS words
    int i = 0, j;

    while ((p != NULL) && (i < MAXWORDS))
    { // continue splitting line on spaces
        row[i] = p;
        i++;
        p = strtok(NULL, " ");
    }

    double pos = 0.50; // positive DEFAULT VALUE
    double neg = 0.50; // negative DEFAULT VALUE
    printf("Review: ");
    for (j = 0; j < (i - 1); j++) {
        // if the word row[j] is in the dictionary, sum up its properties
        printf("[%s]", row[j]);
        // struct my_struct *word = find_record(row[j]);
        // if (word->Positive > 0) {
        //     printf("[%s] is positive", row[j]);
        //     // pos++;
        // }
        // if (word->Positive > 0) {
        //     printf("[%s] is negative", row[j]);
        //     // neg++;
        // }
    }
    // then divide by word count to get percentages
    printf("This review is %f positive, according to our analysis", pos);
    // then compare to json rating "overall" to see success of S.A. predictions

    printf("\n");

    free(str); // deallocate memory from line pointer
}

void getReviews(char file[]) {
    FILE* stream = fopen(file, "r"); // csv file
    char line[1024];
    while (fgets(line, 1024, stream))
    {
        parseReview(line);
    }

}

int main() {
    loadDictionary("../LoughranMcDonald_MasterDictionary_2018.csv", 99);
    getReviews("reviews.txt");
    return 0;
}

#endif // PARSER_H
