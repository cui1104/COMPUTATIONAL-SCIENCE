#include <iostream>
#include "vector.h"

// constructor
Vector::Vector(const int length) {
  length_ = length;
  ptr_ = (double*) malloc(sizeof(double) * length_);
  for (int i = 0; i < length_; ++i){
    ptr_[i] = 0.0;
  }
}

// copy constructor
Vector::Vector(const Vector & x){
  length_ = x.length();
  ptr_ = new double[length_];
  for (int i = 0; i < length_; ++i){
    ptr_[i] = x[i];
  }
}

// destructor
Vector::~Vector(){    
  free(ptr_);
  ptr_ = nullptr; // C++ can use nullptr instead of NULL
}

void Vector::print(){
  std::cout << "Vector = [" << std::endl;
  for (int i = 0; i < length_; ++i){
    std::cout << ptr_[i] << std::endl;
  }
  std::cout << "]" << std::endl;
}

double & Vector::operator[](const int i) const {
  return ptr_[i];
}

Vector operator+(const Vector A, const double k){
  Vector outvec = Vector(A.length());
  for (int i = 0;i<A.length();++i){
      outvec[i] = A[i] + k;
  }
  return outvec;
}

Vector operator+(const double k, const Vector A){
  return A+k;
}

Vector operator*(const Vector A, const double k){
  Vector outvec = Vector(A.length());
  for (int i =0; i<A.length();++i){
    outvec[i] = A[i] * k;
  }
  return outvec;
}

Vector operator*(const double k, const Vector A){
 return A*k;
}

Vector operator-(const Vector A, const double k){
  return A+(-1*k);
}

Vector operator-(const double k, const Vector A){
  return k + (-1)*A;
}

Vector operator/(const Vector A, const double k){
  return A * (1/k);
}

Vector operator+(const Vector &A, const Vector &B){
  if (A.length() == B.length()){
    Vector outvec = Vector(A.length());
    for (int i = 0;i<A.length();++i){
      outvec[i] = A[i]+B[i];
    }
    return outvec;
  }else{
    throw std::domain_error("Lengths of the two vectors do not match!");
  }
}

Vector operator-(const Vector &A, const Vector &B){
  return A + (-1*B);
}

Vector & Vector::operator=(const Vector &A){
  length_ = A.length();
  ptr_ = (double*) malloc(sizeof(double) * length_);
  for (int i = 0; i < A.length(); ++i){
    ptr_[i] = A[i];
  }
  
  return *this;
}
