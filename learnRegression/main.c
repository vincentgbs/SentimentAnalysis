#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#include "pointArray.h"
#include "methodB.h"

#define TRAIN


int main () {
  char line[1024];
  getReviewsb("7.txt",2000);
  initializePointArray(pointArray, 500);
  fileToArray("7.txt", 2000);
  actualRateRegression(pointArray, 500);
  predictAllReview ("7.txt", 10000);
  exportResult("bResult.csv", 10000);
  return 0;
}
