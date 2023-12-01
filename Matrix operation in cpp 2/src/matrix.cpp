#include <iostream>
#include "matrix.h"

Matrix::Matrix(int rows, int columns){
  _rows = rows;
  _columns = columns;
  
  _ptr = new double*[_rows];
  _ptr[0] = new double[_rows * _columns];
  for (int i = 1; i < _rows; ++i) {
    _ptr[i] = _ptr[0] + i * _columns;
  }
}


Matrix::Matrix(const Matrix & A) : Matrix(A.num_rows(), A.num_columns()) {
  for (int i = 0; i < _rows; ++i) {
    for (int j = 0; j < _columns; ++j) {
      _ptr[i][j] = A[i][j];
    }
  }
}

Matrix::~Matrix(){
  free(_ptr[0]);    
  free(_ptr);
}


double * Matrix::operator[](const int i) const {
  return _ptr[i];
}

Matrix operator+(const Matrix &A, const double k){
  Matrix outmat = Matrix(A.num_rows(), A.num_columns());
  for (int i = 0;i<A.num_rows();++i){
    for (int j = 0;j<A.num_columns();++j){
      outmat[i][j] = A[i][j] + k;
    }
  }
  return outmat;
}

Matrix operator+(const double k, const Matrix &A){
  return A+k;
}

Matrix operator*(const Matrix &A, const double k){
  Matrix outmat = Matrix(A.num_rows(), A.num_columns());
  for (int i = 0;i<A.num_rows();++i){
    for (int j = 0;j<A.num_columns();++j){
      outmat[i][j] = A[i][j] * k;
    }
  }
  return outmat;
}

Matrix operator*(const double k, const Matrix &A){
  return A*k;
}

Matrix operator-(const Matrix &A, const double k){
  return (-1*k)+A;
}

Matrix operator-(const double k, const Matrix &A){
  return (-1)*A + k; 
}

Matrix operator/(const Matrix &A, const double k){
  return (1/k)*A;
}

Vector operator*(const Matrix &A, const Vector &b ){
  if (A.num_columns() == b.length()){
    Vector outvec(A.num_rows());
    for (int i = 0;i<A.num_rows();++i){
      for (int j = 0;j<A.num_columns();++j){
        outvec[i] += + A[i][j] * b[j]; 
      }
    }
    return outvec;
  }
  else{
    throw std::domain_error("Number of columns for matrix does not match length of vector!");
  }
}

Matrix operator+(const Matrix &A, const Matrix &D){
  if (A.num_columns()== D.num_columns() && A.num_rows()==D.num_rows()){
     Matrix outmat = Matrix(A.num_rows(),A.num_columns());
     for (int i =0;i<A.num_rows();++i){
      for (int j = 0;j<A.num_columns();++j){
        outmat[i][j] = A[i][j] + D[i][j];
      }
     }
     return outmat;
  }else{
    throw std::domain_error("Sizes of the two matrices do not match!");
  }
}

Matrix operator-(const Matrix &A, const Matrix &D){
  if (A.num_columns()== D.num_columns() && A.num_rows()==D.num_rows()){
     Matrix C = Matrix(A.num_rows(),A.num_columns());
     C = -1.0*D;
     return A+C;
  }else{
    throw std::domain_error("Sizes of the two matrices do not match!");
  }
}

Matrix operator*(const Matrix &A, const Matrix &D){
  if (A.num_columns() == D.num_rows()){
    Matrix outmat = Matrix(A.num_rows(), D.num_columns());
    for (int i = 0; i < A.num_rows();++i){
      for (int j = 0; j <D.num_columns();++j){
        outmat[i][j] = 0;
        for (int k = 0; k<A.num_columns();++k){
          outmat[i][j] = outmat[i][j] + A[i][k]*D[k][j];
        }
      }
    }
   return outmat;
  }else{
    throw std::domain_error("Sizes of the two matrices do not match!");
  }
}

void Matrix::operator=(const Matrix &A){
  _rows = A.num_rows();
  _columns = A.num_columns();
  
  _ptr = new double*[_rows];
  _ptr[0] = new double[_rows * _columns];
  for (int i = 1; i < _rows; ++i) {
    _ptr[i] = _ptr[0] + i * _columns;
  }

  for (int i = 0;i< _rows;++i){
    for (int j =0; j<_columns;++j){
      _ptr[i][j] = A[i][j];
    }
  }
}


void Matrix::print(){
  std::cout << "Matrix = [" << std::endl;
  for (int i = 0; i < _rows; ++i){      
    for (int j = 0; j < _columns; ++j){      
      std::cout << _ptr[i][j] << " "; 
    }
    std::cout << std::endl;      
  }
  std::cout << "]" << std::endl;    
}
