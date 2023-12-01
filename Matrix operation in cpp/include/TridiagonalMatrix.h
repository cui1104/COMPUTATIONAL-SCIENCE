#include "vector.h"
#include "matrix.h"

#ifndef _TridiagonalMatrix
#define _TridiagonalMatrix

typedef struct{
  int n;
  double * ptr_lower; 
  double * ptr_mid;
  double * ptr_upper;
} TridiagonalMatrix;

#endif

void print_TridiagonalMatrix(TridiagonalMatrix* A);
TridiagonalMatrix * allocate_TridiagonalMatrix(int n);
void multiply_TridiagonalMatrix_Vector(Vector* out, TridiagonalMatrix* A, Vector* x);
void free_TridiagonalMatrix(TridiagonalMatrix* A);
TridiagonalMatrix * TridiagonalMatrix_copy(Matrix* A);