#include "vector.h"
#include "matrix.h"

#ifndef _DiagonalMatrix
#define _DiagonalMatrix

typedef struct{
  int n;
  double * ptr; 
} DiagonalMatrix;

#endif

void print_DiagonalMatrix(DiagonalMatrix* A);
DiagonalMatrix * allocate_DiagonalMatrix(int n);
void multiply_DiagonalMatrix_Vector(Vector* out, DiagonalMatrix* A, Vector* x);
void free_DiagonalMatrix(DiagonalMatrix* A);
DiagonalMatrix * DiagonalMatrix_copy(Matrix* A);
