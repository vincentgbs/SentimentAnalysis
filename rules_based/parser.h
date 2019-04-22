#ifndef PARSER_H
#define PARSER_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void getFile();
// void splitLine();

// int main() {
//     int i, j; // iterators
//     char *row[100]; // max review of 100 words
//     FILE* stream = fopen("reviews.txt", "r"); // csv file
//     char line[1024];
//     int max = 0; // max lines (only for testing purposes)
//     while (fgets(line, 1024, stream) && (max < 5))
//     {
//         char* str = strdup(line); // duplicate line as string
//         char *p = strtok(str, " "); // split line on spaces
//
//         i = 0;
//         while (p != NULL)
//         {
//             row[i++] = p;
//             p = strtok(NULL, " ");
//         }
//
//         printf("Row: ");
//         for (j = 0; j < i; j++) {
//             // if the word row[j] is in the dictionary, sum up its properties
//             double pos = 0.50; // positive
//             double neg = 0.50; // negative
//             // uncertainty
//             // litigious
//             // weak_modal
//             // moderate_modal
//             // strong_modal
//             // constraining
//         }
//
//         double pos = 0.50;
//         // then divide by word count to get percentages
//         printf("The review: '%s', is %f positive, according to our analysis", str, pos);
//         // then compare to json rating "overall" to see success of S.A. predictions
//
//         printf("\n");
//
//         free(str); // deallocate memory from line pointer
//         max++; // only for testing
//     }
//     return 0;
// }

#endif // PARSER_H
