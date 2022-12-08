#ifndef _VECTOR
#define _VECTOR

class Vector{
public:
  Vector(const int length);
  Vector(const Vector & x);
  ~Vector();
  
  int length(void) const{ return length_; };  
  double * get_ptr() const{ return ptr_; };
  void print();
  Vector& operator=(const Vector& copy_from);

  // for indexing (e.g., x[i] = 1.0);  
  double & operator[](const int i) const; 

private:
  int length_;
  double * ptr_;
};


Vector operator-(const Vector &A, const Vector &B);
Vector operator+(const Vector &A, const Vector &B);
Vector operator/(const Vector A, const double k);
Vector operator-(const double k, const Vector A);
Vector operator-(const Vector A, const double k);
Vector operator*(const double k, const Vector A);
Vector operator*(const Vector A, const double k);
Vector operator+(const double k, const Vector A);
Vector operator+(const Vector A, const double k);



#endif
