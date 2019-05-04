#include "parser.h"

#define MAXLINELENGTH 1024
#define MAXWORDS 128
// RESULTS 1 = export to csv, RESULTS 0 = write to console
#define RESULTS 0

const char* const stopwords[] = {"ME", "MY", "MYSELF", "WE", "OUR", "OURS", "OURSELVES", "YOU", "YOUR", "YOURS",
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
float deviation = 0; // deviation squared sum
int predictions; // number of predictions made

float rulePrediction(int pos, int neg) {
    if (pos - neg > 1) {
        return 4.5;
    } else if (pos - neg == 1) {
        return 4;
    } else if (pos - neg < 1) {
        return 3.5;
    } else {
        return 3; // "neutral"
    }
}

// format assumed to be: 5|REVIEW TEXT
void parseReview(char line[], char results[]) {
    char* str = strdup(line); // duplicate line as string
    char *p = strtok(str, "|"); // split rating from review
    char *row[MAXWORDS]; // review of MAXWORDS words
    float pos, neg, pred, error;
    int i = 0, j, stars;

    FILE *output = fopen(results, "a");
    if (output == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((p != NULL) && (i < MAXWORDS))
    { // continue splitting line on spaces
        row[i] = p;
        i++; // MAXWORDS counter
        p = strtok(NULL, " ");
    }

    stars = atoi(row[0]); // rating
    pos = 0; // positive starting value
    neg = 0; // negative starting value
    for (j = 1; j < i; j++) {
        struct dictRecord *word = find_record(row[j]);
        if (word) { // null check
            if (word->Positive > 0) {
                pos++;
            }
            if (word->Negative > 0) {
                neg++;
            }
        }
    }

    if (pos != 0 || neg != 0) {
        pred = rulePrediction(pos, neg);
        error = pred - stars;
        if (RESULTS == 0) {
            printf("This review is %f positive and %f negative. Our prediction was %f stars. The reviewer gave it %d stars. \n", (pos/i), (neg/i), pred, stars);
        } else if (RESULTS == 1) {
            fprintf(output, "%f, %f, %f, %d, %f\n", pos, neg, pred, stars, error);
        }
        deviation += (error * error);
        predictions++;
    } // else {
    //     printf("There was not enough data for our algorithm.\n");
    // }

    free(str); // deallocate memory from line pointer
    fclose(output);
}

void getReviews(char reviews[], char results[], int max) {
    FILE* stream = fopen(reviews, "r"); // txt file
    char line[MAXLINELENGTH]; // max line length
    int ctr = 0; // max reviews

    if (RESULTS == 1) {
        FILE *write = fopen(results, "w");
        fprintf(write, "positive, negative, prediction, stars, error\n");
        fclose(write); // clear previous results, parse will append
    }
    while (fgets(line, MAXLINELENGTH, stream) && (ctr < max))
    {
        parseReview(line, results);
        ctr++;
    }

    printf("The standard error for predictions was %f\n", (deviation/predictions));

}
