#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#include "methodB.h"
#define MAXWORDS 200

int main () {
  char line[1024];
  void parseReview(char *);


  
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


  struct wordNode n = createNode ("aaa", 3);
  struct wordNode n2 = createNode ("aab",3);
  struct wordNode n3 = createNode ("aac",3);
  struct wordNode n4 = createNode ("aac",10);
  addNode(&n);
  addNode(&n2);
  addNode(&n3);
  addNode(&n4);
  printList(&n);


  
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

}