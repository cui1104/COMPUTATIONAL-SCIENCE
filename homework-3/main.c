#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "DiagonalMatrix.h"
#include "UpperTriangularMatrix.h"
#include "TridiagonalMatrix.h"

int main(void){

  int m = 5;
  int n = 5;
  Matrix * A = allocate_Matrix(m, n);
  
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      A->ptr[i][j] = (double) (i+j);
    }
  }
  //code for DiagonalMatrix
  printf("Running DiagonalMatrix...\n");
  DiagonalMatrix * D = DiagonalMatrix_copy(A);
  print_DiagonalMatrix(D);
  
  //code for UpperTriangularMatrix
  printf("Running UpperTriangularMatrix...\n");
  UpperTriangularMatrix * E = UpperTriangularMatrix_copy(A);
  print_UpperTriangularMatrix(E);
  
  //code for TridiagonalMatrix
  printf("Running TridiagonalMatrix...\n");
  TridiagonalMatrix * F = TridiagonalMatrix_copy(A);
  print_TridiagonalMatrix(F);


 
  free_DiagonalMatrix(D);
  free_UpperTriangularMatrix(E);
  free_TridiagonalMatrix(F);
  free_Matrix(A);
}

