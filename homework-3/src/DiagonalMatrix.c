#include <stdio.h>
#include <stdlib.h>
#include "DiagonalMatrix.h"

DiagonalMatrix * allocate_DiagonalMatrix(int n){
  // allocate contiguous memory for the
  // row-major storage of A
  DiagonalMatrix * A = malloc(sizeof(DiagonalMatrix));
  A->n = n;
  A->ptr = malloc(sizeof(double)*n);
  return A;
}

void free_DiagonalMatrix(DiagonalMatrix *A){
  free(A->ptr);  
}

void print_DiagonalMatrix(DiagonalMatrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
        if (j < i){
            printf("       ");
        } 
        else if (j == i){
            printf("%7.2f", A->ptr[i]);
        }
        else if (j > i){
            printf("       ");
        }
    }
    printf("\n");    
  }
  printf("]\n");
}

DiagonalMatrix * DiagonalMatrix_copy(Matrix* A){
  int n = A->n;
  DiagonalMatrix * D = allocate_DiagonalMatrix(n);

 for (int i = 0 ;i<n;++i){
    D->ptr[i] = A->ptr[i][i];
 }
D->n = n;
return D; 

}


void multiply_DiagonalMatrix_Vector(Vector* out, DiagonalMatrix* A, Vector* x){
  for (int i = 0; i < A->n; ++i){
    out->ptr[i] = 0.0;
    double A_i = A->ptr[i];
    double x_i = x->ptr[i];
    out->ptr[i] += A_i * x_i;
  }
}

