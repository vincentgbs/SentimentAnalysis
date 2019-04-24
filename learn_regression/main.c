#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordNode.h"
#include "pointArray.h"
#include "methodB.h"

#define TRAIN

int main () {
    importReviews("EDITED_REVIEWS.txt", 200, 0);
    initializePointArray(pointArray, 500);
    fileToArray("EDITED_REVIEWS.txt", 200);
    actualRateRegression(pointArray, 500);
    predictAllReview("EDITED_REVIEWS.txt", 700);
    return 0;
}
