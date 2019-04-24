#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#include "pointArray.h"
#include "methodB.h"

#define TRAIN

int main () {
    importReviews("EDITED_REVIEWS.txt", 2000, 0);
    initializePointArray(pointArray, 500);
    fileToArray("EDITED_REVIEWS.txt", 2000);
    actualRateRegression(pointArray, 500);
    predictAllReview("EDITED_REVIEWS.txt", 10000);
    return 0;
}
