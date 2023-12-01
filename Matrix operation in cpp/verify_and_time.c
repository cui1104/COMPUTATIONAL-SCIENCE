#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "matrix.h"
#include "DiagonalMatrix.h"
#include "UpperTriangularMatrix.h"
#include "TridiagonalMatrix.h"
#include <time.h>

int main(void){
  int m = 100;
  int n = 100;
  Matrix * A = allocate_Matrix(m, n); 
  Vector * x = allocate_Vector(n);

  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      A->ptr[i][j] = (double) (i+j);
    }
  }
  for (int j = 0; j < n; ++j){
    x->ptr[j] = j+1;
  }
  // Verify
  //code for DiagonalMatrix
  Vector * out_1 = allocate_Vector(n);
  Matrix * A_diag = allocate_Matrix(m,n);
  for (int i = 0;i<m;++i){
      for(int j = 0;j<n;++j){
  	if (i==j){
  	  A_diag->ptr[i][j] = i+j;
  	}else{
  	  A_diag->ptr[i][j] = 0;
  	}
      }
  }
  
  multiply_Matrix_Vector(out_1, A_diag, x); // matrix type
  
  DiagonalMatrix * D = DiagonalMatrix_copy(A);
  Vector * out_2 = allocate_Vector(n);
  multiply_DiagonalMatrix_Vector(out_2, D, x); //Diagonal Matrix type
  Vector * diff = allocate_Vector(n);
  difference(out_1, out_2, diff); // find the difference
  double diff_opt1 = norm(diff); // find the norm
  printf("The norm of the difference between the two matrix-vector products for DiagonalMatrix is %f\n", diff_opt1);
  
//code for UpperTriangularMatrix
  UpperTriangularMatrix * U = UpperTriangularMatrix_copy(A);
  Matrix * A_upper = allocate_Matrix(m,n); //matrix type
  for(int i = 0; i <m; ++i){
      for(int j = 0; j < n; ++j){
         if(i <= j){
            A_upper->ptr[i][j] = i + j;
         }else{
            A_upper->ptr[i][j] = 0;
         }
      }
   }
   
   multiply_Matrix_Vector(out_1, A_upper,x);
   
   multiply_UpperTriangularMatrix_Vector(out_2, U, x); //UpperTriangularMatrix type
   Vector * diff_2 = allocate_Vector(n);
   difference(out_1, out_2, diff_2);
   double diff_opt2 = norm(diff_2);
   printf("The norm of the difference between the two matrix-vector products for UpperTriangularMatrix is %f\n", diff_opt2);
   
//code for TridiagonalMatrix
   TridiagonalMatrix *T = TridiagonalMatrix_copy(A); //tridiagonalmatrix type
   Matrix * A_tri = allocate_Matrix(m,n); //matrix type
   for(int i =0;i<m;++i){
      for(int j = 0;j<n;++j){
         if (i - j <= 1 && i - j >= 0 || j - i <= 1 && j - i >= 0){
            A_tri -> ptr[i][j] = i+j;
         }
         else{
            A_tri -> ptr[i][j] = 0;
         }
      }
   }
   
   multiply_Matrix_Vector(out_1, A_tri, x); //matrix type
   multiply_TridiagonalMatrix_Vector(out_2, T, x); //tridiagonalmatrix type
   Vector * diff_3 = allocate_Vector(n);
   difference(out_1, out_2, diff_3);
   double diff_opt3 = norm(diff_3);
   printf("The norm of the difference between the two matrix-vector products for TridiagonalMatrix is %f\n", diff_opt3);
   
   //Time
   //Code for diagonal matrix
   clock_t start_t, end_t;
   double total_t_mat;
   double total_t_diag;
   
   for(int i=0;i<100;++i){
       start_t = clock();   
       multiply_Matrix_Vector(out_1, A_diag, x); //matrix type
       end_t = clock();
       total_t_mat += (double)(end_t - start_t) / CLOCKS_PER_SEC;
       
       start_t = clock();   
       multiply_DiagonalMatrix_Vector(out_2, D, x); //diagonal matrix type
       end_t = clock();
       total_t_diag += (double)(end_t - start_t) / CLOCKS_PER_SEC;
   }
   
   total_t_mat /= 100;
   total_t_diag /= 100;
   printf("The average time used by DiagonalMatrix type is %g s\n",total_t_diag);
   printf("The average time used by Matrix type is %g s\n",total_t_mat);
   //Code for UpperTriangularMatrix
   double total_t_mat2;
   double total_t_upper;
   
   for(int i=0;i<100;++i){
       start_t = clock();   
       multiply_Matrix_Vector(out_1, A_upper,x); //matrix type
       end_t = clock();
       total_t_mat2 += (double)(end_t - start_t) / CLOCKS_PER_SEC ;
       
       start_t = clock();   
       multiply_UpperTriangularMatrix_Vector(out_2, U, x); //upper triangular matrix type
       end_t = clock();
       total_t_upper += (double)(end_t - start_t) / CLOCKS_PER_SEC;
   }
   
   total_t_mat2 /= 100;
   total_t_upper /= 100;
   printf("The average time used by UpperTriangularMatrix type is %g s\n",total_t_upper);
   printf("The average time used by Matrix type is %g s\n",total_t_mat2);
   //Code for TridiagonalMatrix
   double total_t_mat3;
   double total_t_tri;
   
   for(int i=0;i<100;++i){
       start_t = clock();   
       multiply_Matrix_Vector(out_1, A_tri, x); //matrix type
       end_t = clock();
       total_t_mat3 += (double)(end_t - start_t) / CLOCKS_PER_SEC ;
       
       start_t = clock();   
       multiply_TridiagonalMatrix_Vector(out_2, T, x); //tridiagonal matrix type
       end_t = clock();
       total_t_tri += (double)(end_t - start_t) / CLOCKS_PER_SEC;
   }
   
   total_t_mat3 /= 100;
   total_t_tri /= 100;
   printf("The average time used by Tridiagonal type is %g s\n",total_t_tri);
   printf("The average time used by Matrix type is %g s\n",total_t_mat3);
   
   //free the memory
   free_Matrix(A);
   free_Vector(x);
   free_Vector(out_1);
   free_Matrix(A_diag);
   free_DiagonalMatrix(D);
   free_Vector(out_2);
   free_Vector(diff);
   free_UpperTriangularMatrix(U);
   free_Vector(diff_2);
   free_Vector(diff_3);
   free_TridiagonalMatrix(T);
   free_Matrix(A_tri);
   free_Matrix(A_upper);
   
}
