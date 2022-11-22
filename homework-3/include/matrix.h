#include "vector.h"

#ifndef _MATRIX
#define _MATRIX

typedef struct{
  int m;
  int n;
  double ** ptr; 
} Matrix;

#endif

void print_Matrix(Matrix* A);
Matrix * allocate_Matrix(int m, int n);
void multiply_Matrix_Vector(Vector* out, Matrix* A, Vector* x);
void free_Matrix(Matrix* A);


