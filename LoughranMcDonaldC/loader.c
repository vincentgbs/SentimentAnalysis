#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define STRLEN 100

// typedef struct {
//     char word[STRLEN];
//     int seqNum;
//     long int wordCount;
//     double wordProp;
//     double avgProp;
//     double StdDev;
//     int docCount;
//     int neg;
//     int pos;
//     int uncert;
//     int litig;
//     int constrain;
//     int superf;
//     int interest;
//     int modal;
//     int irrVerb;
//     int harvard;
//     int syllab;
//     char src[STRLEN];
// } dictRow;

int main() {
    int i, j; // iterators
    char *row[20]; // max 20 columns
    FILE* stream = fopen("LoughranMcDonald_MasterDictionary_2018.csv", "r"); // csv file
    char line[1024];
    int max = 0; // max lines (only for testing purposes)
    while (fgets(line, 1024, stream) && (max < 999))
    {
        char* str = strdup(line); // duplicate line as string
        char *p = strtok(str, ","); // split line on comas

        i = 0;
        while (p != NULL)
        {
            row[i++] = p;
            p = strtok(NULL, " ");
        }

        printf("Row: ");
        for (j = 0; j < i; j++) {
            printf("%s ", row[j]);
        }
        printf("\n");

        free(str); // deallocate memory from line pointer
        max++; // only for testing
    }
    return 0;
}
