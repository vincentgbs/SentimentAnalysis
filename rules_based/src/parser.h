#ifndef PARSER_H
#define PARSER_H

#include "dictionary.h"

#define MAXWORDS 100

void parseReview(char line[], char results[]);

void getReviews(char reviews[], char results[], int max);

#endif // PARSER_H
