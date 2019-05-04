#ifndef PARSER_H
#define PARSER_H

#include "dictionary.h"

void parseReview(char line[], char results[]);

void getReviews(char reviews[], char results[], int max);

float rulePrediction(int pos, int neg);

#endif // PARSER_H
