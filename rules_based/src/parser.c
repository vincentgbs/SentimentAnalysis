#include "parser.h"
// #include "export.h"

const char* const stopWords[] = {"ME", "MY", "MYSELF", "WE", "OUR", "OURS", "OURSELVES", "YOU", "YOUR", "YOURS",
"YOURSELF", "YOURSELVES", "HE", "HIM", "HIS", "HIMSELF", "SHE", "HER", "HERS", "HERSELF",
"IT", "ITS", "ITSELF", "THEY", "THEM", "THEIR", "THEIRS", "THEMSELVES", "WHAT", "WHICH",
"WHO", "WHOM", "THIS", "THAT", "THESE", "THOSE", "AM", "IS", "ARE", "WAS", "WERE", "BE",
"BEEN", "BEING", "HAVE", "HAS", "HAD", "HAVING", "DO", "DOES", "DID", "DOING", "AN",
"THE", "AND", "BUT", "IF", "OR", "BECAUSE", "AS", "UNTIL", "WHILE", "OF", "AT", "BY",
"FOR", "WITH", "ABOUT", "BETWEEN", "INTO", "THROUGH", "DURING", "BEFORE",
"AFTER", "ABOVE", "BELOW", "TO", "FROM", "UP", "DOWN", "IN", "OUT", "ON", "OFF", "OVER",
"UNDER", "AGAIN", "FURTHER", "THEN", "ONCE", "HERE", "THERE", "WHEN", "WHERE", "WHY",
"HOW", "ALL", "ANY", "BOTH", "EACH", "FEW", "MORE", "MOST", "OTHER", "SOME", "SUCH",
"NO", "NOR", "NOT", "ONLY", "OWN", "SAME", "SO", "THAN", "TOO", "VERY", "CAN",
"JUST", "SHOULD", "NOW"};

// format assumed to be: 5|REVIEW TEXT
void parseReview(char line[]) {
    char* str = strdup(line); // duplicate line as string
    char *p = strtok(str, "|"); // split rating from review
    char *row[MAXWORDS]; // max review of MAXWORDS words
    int i = 0, j;

    while ((p != NULL) && (i < MAXWORDS))
    { // continue splitting line on spaces
        row[i] = p;
        i++;
        p = strtok(NULL, " ");
    }

    int stars = atoi(row[0]); // rating
    double pos = 0; // positive DEFAULT VALUE
    double neg = 0; // negative DEFAULT VALUE
    for (j = 1; j < i; j++) {
        struct dictRecord *word = find_record(row[j]);
        if (word) { // null check
            // printf("[%s] in dictionary\n", row[j]);
            if (word->Positive > 0) {
                // printf("[%s] is POSITIVE\n", row[j]);
                pos++;
            }
            if (word->Negative > 0) {
                // printf("[%s] is NEGATIVE\n", row[j]);
                neg++;
            }
        }
        // else {
        //     printf("[%s] not in dictionary\n", row[j]);
        // }
    }
    if (pos != 0 || neg != 0) {
        printf("This review is %f positive and %f negative, according to our analysis. The reviewer gave it %d stars. \n", (pos/i), (neg/i), stars);
    }
    // else {
    //     printf("There was not enough data for our algorithm.\n");
    // }

    free(str); // deallocate memory from line pointer
}

void getReviews(char file[], int max) {
    FILE* stream = fopen(file, "r"); // txt file
    char line[1024];
    int ctr = 0; // max reviews

    while (fgets(line, 1024, stream) && (ctr < max))
    {
        parseReview(line);
        ctr++;
    }

}
