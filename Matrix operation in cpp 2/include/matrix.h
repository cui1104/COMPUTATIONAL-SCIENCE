#ifndef _MATRIX
#define _MATRIX
#include "vector.h"

class Matrix{
 public:
  Matrix(int rows, int columns);
  Matrix(const Matrix & A);  
  ~Matrix();
  
  int num_rows() const { return _rows; };
  int num_columns() const { return _columns; };
  double * operator[](const int i) const;
  void operator=(const Matrix & copy_from);
  void print();

 private:
  int _rows;
  int _columns;
  double ** _ptr;
 
};

  Matrix operator+(const Matrix &A, const double k);
  Matrix operator+(const double k, const Matrix &A);
  Matrix operator*(const Matrix &A, const double k);
  Matrix operator*(const double k, const Matrix &A);
  Matrix operator-(const Matrix &A, const double k);
  Matrix operator-(const double k, const Matrix &A);
  Matrix operator/(const Matrix &A, const double k);

  Vector operator*(const Matrix &A, const Vector &b );
  Matrix operator+(const Matrix &A, const Matrix &D);
  Matrix operator-(const Matrix &A, const Matrix &D);

  Matrix operator*(const Matrix &A, const Matrix &D);

#endif
