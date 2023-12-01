#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* allocate_Matrix(int m, int n){
  double ** ptr = malloc(sizeof(double*) * m);

  // allocate contiguous memory for the
  // row-major storage of A
  ptr[0] = malloc(sizeof(double) * m * n);
  for (int i = 1; i < m; ++i){
    ptr[i] = ptr[0] + i * n;
  }

  // return a pointer to a new matrix object
  Matrix * A = malloc(sizeof(Matrix));
  A->m = m;
  A->n = n;
  A->ptr = ptr;
  return A;
}

void free_Matrix(Matrix *A){
  free(A->ptr[0]); 
  free(A->ptr);  
}

void print_Matrix(Matrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->m; ++i){
    for (int j = 0; j < A->n; ++j){
      printf("%7.2f  ", A->ptr[i][j]);
    }
    printf("\n");    
  }
  printf("]\n");
}

void multiply_Matrix_Vector(Vector* out, Matrix* A, Vector* x){
  for (int i = 0; i < A->m; ++i){
    out->ptr[i] = 0.0;
    for (int j = 0; j < A->n; ++j){
      double A_ij = A->ptr[i][j];
      double x_j = x->ptr[j];
      out->ptr[i] += A_ij * x_j;
    }
  }
}
