#include <stdio.h>
#include <stdlib.h>
#include <math.h> // for the sqrt function
#include "vector.h"

void print_Vector(Vector * x){
  printf("Vector = [\n");
  for (int i = 0; i < x->length; ++i){
    printf("%7.2f\n", x->ptr[i]);
  }
  printf("]\n");

}

Vector * allocate_Vector(int n){
  Vector * x = malloc(sizeof(Vector));
  x->length = n;
  x->ptr = malloc(sizeof(double) * n);
  return x;
}

void free_Vector(Vector * x){
  free(x->ptr);
}

double norm(Vector * x){
  double val = 0.0;
  for (int i = 0; i < x->length; ++i){
    double x_i = x->ptr[i];
    val += x_i * x_i;
  }
  return sqrt(val);
}

void * difference(Vector *A, Vector *B, Vector *out){
  int n = A->length;
  double * ptrout = malloc(sizeof(double) *n);
  for (int i=0;i<n;++i){
     ptrout[i] = A->ptr[i] - B->ptr[i];
  }
  out -> ptr = ptrout;
  out -> length = n;
 }
