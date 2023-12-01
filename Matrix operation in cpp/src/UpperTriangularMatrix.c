#include <stdio.h>
#include <stdlib.h>
#include "UpperTriangularMatrix.h"

UpperTriangularMatrix* allocate_UpperTriangularMatrix(int n){
  double ** ptr = malloc(sizeof(double*) * n);

  // allocate contiguous memory for the
  // row-major storage of A
  ptr[0] = malloc(sizeof(double) * (n*(n+1))/2);
  for (int i = 1; i < n; ++i){
    ptr[i] = ptr[i-1] + n - i;
  }

  // return a pointer to a new matrix object
  UpperTriangularMatrix * A = malloc(sizeof(UpperTriangularMatrix));
  A->n = n;
  A->ptr = ptr;
  return A;
}

void free_UpperTriangularMatrix(UpperTriangularMatrix *A){
  free(A->ptr[0]); 
  free(A->ptr);  
}

void print_UpperTriangularMatrix(UpperTriangularMatrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
        if (j < i){
            printf("       ");
        } 
        else {
            printf("%7.2f", A->ptr[i][j]);
        }
    }
    printf("\n");    
  }
  printf("]\n");
}

UpperTriangularMatrix * UpperTriangularMatrix_copy(Matrix* A){
  int m = A->m;
  double ** ptr = A->ptr;
  UpperTriangularMatrix * D = allocate_UpperTriangularMatrix(m);

 for (int i = 0 ;i<m;++i){
    for (int j = i; j<m;++j){
        D->ptr[i][j] = A->ptr[i][j];
    }
 }

return D; 

}

void multiply_UpperTriangularMatrix_Vector(Vector* out, UpperTriangularMatrix* A, Vector* x){
  for (int i = 0; i < A->n; ++i){
    out->ptr[i] = 0.0;
    for (int j = i; j < A->n; ++j){
      double A_ij = A->ptr[i][j];
      double x_j = x->ptr[j];
      out->ptr[i] += A_ij * x_j;
    }
  }
}
