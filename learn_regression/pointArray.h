#ifndef POINTARRAY_H
#define POINTARRAY_H

struct pointPeriod {
  float avgPoint;
  int frequency;
  float actualRate;
  float predictRate;
};

struct pointPeriod createPointPeriod (float avgPoint) {
  struct pointPeriod p;
  p.avgPoint = avgPoint;
  p.frequency = 1;
  p.actualRate = avgPoint;
  p.predictRate = avgPoint;
  return p;
}

void initializePointArray (struct pointPeriod [], int);
void updatePointPeriod (float avgPoint, float actualRate);
void printPointPeriodArray(struct pointPeriod array[], int size);
void actualRateRegression (struct pointPeriod array[], int size);
float truncateTo2Decimals(float x);
void printDiff ();

struct pointPeriod pointArray[500] = {0};

/* Create array of scores */
void initializePointArray (struct pointPeriod array[], int arrayLength) {
  int i = 0;
  for (i = 0; i < arrayLength; i++) {
    float f = ((float) i) / 100;
    array[i] = createPointPeriod(f);
  }
}

/* update one pointPeriod to the point Array*/
void updatePointPeriod (float avgPoint, float actualRate) {
  int position = (int) (truncateTo2Decimals (avgPoint) * 100);
  if (position > 500) {
      printf("Error updating point!\n");
      exit(1);
  }
  pointArray[position].actualRate = (pointArray[position].actualRate * pointArray[position].frequency + actualRate) / (pointArray[position].frequency + 1);
  pointArray[position].frequency++;
}

void printPointPeriodArray(struct pointPeriod array[], int size) {
  int i;
  for (i= 0; i < size; i++) {
    printf("id: %f, f: %d, rate: %f\n", array[i].avgPoint, array[i].frequency, array[i].actualRate);
  }
}

/*regression for actualRate*/
void actualRateRegression (struct pointPeriod array[], int size) {
  int i, j, f; /*f is the frequency of regression*/
  for (i = 0; i < size; i++) {
    f = 1;
    for (j = 0; j < size; j++) {
      if (j < i) {
        if (pointArray[j].actualRate > pointArray[i].avgPoint) {
          pointArray[i].predictRate = ((pointArray[i].predictRate * f) + (pointArray[j].actualRate * pointArray[j].frequency))/(f + pointArray[j].frequency);
          f = f + pointArray[j].frequency;
        }
      }
      else if (j > i) {
        if (pointArray[j].actualRate < pointArray[i].avgPoint) {
          pointArray[i].predictRate = ((pointArray[i].predictRate * f) + (pointArray[j].actualRate * pointArray[j].frequency))/(f + pointArray[j].frequency);
          f = f + pointArray[j].frequency;
        }
      }
      else {
        if (pointArray[j].actualRate != pointArray[i].avgPoint) {
          pointArray[i].predictRate = ((pointArray[i].predictRate * f) + (pointArray[j].actualRate * pointArray[j].frequency))/(f + pointArray[j].frequency);
          f = f + pointArray[j].frequency;
        }
      }
    }
  }
}

float getPrediction (struct pointPeriod array[], float avgPoint) {
  int position = (int) (truncateTo2Decimals (avgPoint) * 100);
  return array[position].predictRate;
}

float truncateTo2Decimals(float x) {
  return ((float) ((int) (x * 100))) / 100;
}

/*find where avgPoint != actualRate, for debuggin purpose*/
void printDiff () {
    int i;
  for (i= 0; i < 500; i++) {
    if (pointArray[i].avgPoint != pointArray[i].actualRate) {
      printf("%d: %f - %f - f: %d - r: %f\n",i,pointArray[i].avgPoint, pointArray[i].actualRate, pointArray[i].frequency, pointArray[i].predictRate );
    }
  }
}
#endif
