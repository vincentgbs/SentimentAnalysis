#ifndef  R_PPAIR_H
#define R_PPAIR_H

#include <math.h>

#define MAXRESULTPREDICTION 10000

struct r_p {
  int result;
  float prediction;
  float error;
};

struct r_p r_pArray[MAXRESULTPREDICTION] = {0};

struct r_p createR_P (int result, float prediction) {
  struct r_p a;
  a.result = result;
  a.prediction = prediction;
  a.error = fabs(a.prediction - a.result);
  return a;
}

#endif