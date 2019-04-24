#ifndef PARSER_H
#define PARSER_H

#include "dictionary.h"

#define MAXWORDS 100

void parseReview(char line[]);

void getReviews(char file[], int max);

#endif // PARSER_H
