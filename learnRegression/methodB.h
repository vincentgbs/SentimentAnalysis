/* Another way to predict review rate*/
#ifndef METHODB_H
#define METHODB_H

#include "pointArray.h"
#include "wordNode.h"
#include "r_pPair.h"

#define MAXWORDS 200

void parseReviewb(char *);
void getReviewsb(char file[], int max);
void reviewToArray(char *line);
void fileToArray (char file[], int max);
void predictOneReview(char *line, int ctr);
void predictAllReview (char file[], int max);

struct wordNode wordNodeArray[200000] = {0};
int w = 0;



void parseReviewb(char *line) {
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
    int stars = atoi(row[0]);

    for (j = 1; j < i; j++) {
      wordNodeArray[w++] = createNode(row[j], stars);
      addNode(&(wordNodeArray[w-1]));
    }
  free(str);
}

void getReviewsb(char file[], int max) {
   FILE* stream = fopen(file, "r"); // csv file
   char line[1024];
   int ctr = 0; // max reviews

   while (fgets(line, 1024, stream) && (ctr < max))
   {
      parseReviewb(line);
      ctr++;
   }
   fclose(stream);
}

void reviewToArray(char *line) {
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
    int stars = atoi(row[0]);
    float avgpoint = 0;
    for (j = 1; j < i; j++) {
      struct wordNode *node = findNode(HEAD, row[j]);
      if (node != NULL)
        avgpoint += node->point;
    }
    avgpoint = truncateTo2Decimals(avgpoint/j);
    updatePointPeriod(avgpoint, stars);
    /*some bug changed at 4.69 -4.70 for first 5 input*/
  free(str);
}

void fileToArray (char file[], int max) {
     FILE* stream = fopen(file, "r"); // csv file
   char line[1024];
   int ctr = 0; // max reviews

   while (fgets(line, 1024, stream) && (ctr < max))
   {
      reviewToArray(line);
      ctr++;
   }
   fclose(stream);
}

void predictOneReview(char *line, int ctr) {
  char* str = strdup(line); // duplicate line as string
  char *p = strtok(str, "|"); // split rating from review
  char *row[MAXWORDS]; // max review of MAXWORDS words
  int i = 0, j;
  float avgpoint = 0;
  float prediction = 0;

  while ((p != NULL) && (i < MAXWORDS))
  { // continue splitting line on spaces
      row[i] = p;
      i++;
      p = strtok(NULL, " ");
  }
  int stars = atoi(row[0]);
  for (j = 1; j < i; j++) {
    struct wordNode *node = findNode(HEAD, row[j]);
    if (node != NULL)
      avgpoint += node->point;
  }
  avgpoint = truncateTo2Decimals(avgpoint/j);
  prediction = getPrediction(pointArray, avgpoint);
  r_pArray[ctr] = createR_P(avgpoint, prediction);
  free(str);
}

void predictAllReview (char file[], int max) {
     FILE* stream = fopen(file, "r"); // csv file
   char line[1024];
   int ctr = 0; // max reviews

   while (fgets(line, 1024, stream) && (ctr < max))
   {
      predictOneReview(line, ctr);
      ctr++;
   }
   fclose(stream);
}

/*export result to a file*/
void exportResult (char file[], int max) {

  FILE* stream = fopen(file, "w+");
  int i;
  for (i = 0; i < max; i++) {
    fprintf(stream, "%d;%f;%f\n", r_pArray[i].result, r_pArray[i].prediction, r_pArray[i].error);
  }
  fclose(stream);
}


#endif
