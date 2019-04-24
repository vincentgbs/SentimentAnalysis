#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#define MAXWORDS 200

void parseReview(char *);
void getReviews(char file[], int max);

int main () {
   char line[1024];
  //getReviews("4.txt",1);

  
   /* opening file for reading */
  /*FILE *fp = fopen("4.txt" , "r");
  if(fp == NULL) {
    perror("Error opening file");
    return(-1);
  }
  int ctr = 0; // max reviews
  int max = 2;
  while (fgets(line, 1024, fp) && (ctr < max))
  {
      //parseReview(line);
      ctr++;
  }*/


  
   char *arr[4] ={"1","aab","aaa","aac"} ; 
   int i = 0;
   for (i= 1; i < 4; i++ ) {
      struct wordNode a = createNode(arr[i], 1);
      addNode(&a);
   }
   printList(HEAD);
  

  
   return 0;
}

void parseReview(char *line) {
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
      struct wordNode x = createNode(row[j], stars);
      addNode(&x);
   }
}

void getReviews(char file[], int max) {
   FILE* stream = fopen(file, "r"); // csv file
   char line[1024];
   int ctr = 0; // max reviews

   while (fgets(line, 1024, stream) && (ctr < max))
   {
      parseReview(line);
      ctr++;
   }

}