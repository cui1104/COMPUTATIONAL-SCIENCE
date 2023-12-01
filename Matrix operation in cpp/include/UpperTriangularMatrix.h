#include "vector.h"
#include "matrix.h"

#ifndef _UpperTriangularMatrix
#define _UpperTriangularMatrix

typedef struct{
  int n;
  double ** ptr; 
} UpperTriangularMatrix;

#endif

void print_UpperTriangularMatrix(UpperTriangularMatrix* A);
UpperTriangularMatrix * allocate_UpperTriangularMatrix(int n);
void multiply_UpperTriangularMatrix_Vector(Vector* out, UpperTriangularMatrix* A, Vector* x);
void free_UpperTriangularMatrix(UpperTriangularMatrix* A);
UpperTriangularMatrix * UpperTriangularMatrix_copy(Matrix* A);