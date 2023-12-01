#include <stdio.h>
#include <stdlib.h>
#include "TridiagonalMatrix.h"

TridiagonalMatrix * allocate_TridiagonalMatrix(int n){
  // allocate memory for the bands
  double * ptr_lower = malloc(sizeof(double)*(n-1));
  double * ptr_mid = malloc(sizeof(double)* n);
  double * ptr_upper = malloc(sizeof(double)*(n-1));

  // allocate contiguous memory for the
  // row-major storage of A
  TridiagonalMatrix * A = malloc(sizeof(TridiagonalMatrix));
  A->n = n;
  A->ptr_lower = ptr_lower;
  A->ptr_mid = ptr_mid;
  A->ptr_upper = ptr_upper;
  return A;
}

void free_TridiagonalMatrix(TridiagonalMatrix *A){
  free(A->ptr_lower);
  free(A->ptr_mid);
  free(A->ptr_upper);  
}

void print_TridiagonalMatrix(TridiagonalMatrix * A){
  printf("A = [\n");
  for (int i = 0; i < A->n; ++i){
    for (int j = 0; j < A->n; ++j){
        if (j < i-1){
            printf("       ");
        } 
        else if (j == i-1){
            printf("%7.2f", A->ptr_lower[j]);
        }
        else if (j == i){
            printf("%7.2f", A->ptr_mid[j]);
        }
        else if (j == i+1){
            printf("%7.2f", A->ptr_upper[i]);
        }
        else if (j > i+1){
            printf("       ");
        }
    }
    printf("\n");    
  }
  printf("]\n");
}

TridiagonalMatrix * TridiagonalMatrix_copy(Matrix* A){
  int m = A->m;
  double ** ptr = A->ptr;
  TridiagonalMatrix * D = allocate_TridiagonalMatrix(m);

  for (int i = 0 ;i<m;++i){
     D->ptr_mid[i] = A->ptr[i][i];
  }

  for (int i = 0 ;i<m-1;++i){
     D->ptr_lower[i] = A->ptr[i+1][i];
     D->ptr_upper[i] = A->ptr[i][i+1];
  }

  return D; 

}

void multiply_TridiagonalMatrix_Vector(Vector* out, TridiagonalMatrix* A, Vector* x){
   for (int i = 0; i < A->n; ++i){
      out->ptr[i] = 0.0;
      if (i==0){
          out -> ptr[i] = A->ptr_mid[i] * x->ptr[i] + A->ptr_upper[0] * x->ptr[1];
      }
      else if (i>0 && i < (A->n)-1){
          out ->ptr[i] = A->ptr_mid[i] * x->ptr[i] + A->ptr_lower[i-1] * x->ptr[i-1] + A->ptr_upper[i] * x->ptr[i+1];
      }
       else if (i == (A->n)-1){
          out -> ptr[i] = A->ptr_mid[i] * x->ptr[i] + A->ptr_lower[i-1] * x->ptr[i-1];
      }
    }
}
