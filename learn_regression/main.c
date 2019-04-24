#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#include "pointArray.h"
#include "methodB.h"

#define TRAIN

int main () {
  char line[1024];
  getReviewsb("7.txt", 200);
  initializePointArray(pointArray, 500);
  // for (int i = 0; i < 500; i++) {
  //     printf("%d: %f - %d - %f - %f\n", i, pointArray[i].avgPoint, pointArray[i].frequency, pointArray[i].actualRate, pointArray[i].predictRate);
  // }
  fileToArray("7.txt", 200);
  actualRateRegression(pointArray, 500);
  for (int i = 0; i < 500; i++) {
      printf("%d: %f - %d - %f - %f\n", i, pointArray[i].avgPoint, pointArray[i].frequency, pointArray[i].actualRate, pointArray[i].predictRate);
  }
  predictAllReview ("7.txt", 700);
  return 0;
}
