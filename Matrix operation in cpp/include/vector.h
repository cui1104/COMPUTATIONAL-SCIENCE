#ifndef _VECTOR
#define _VECTOR

typedef struct{
  int length;
  double * ptr; 
} Vector;

#endif

void print_Vector(Vector * x);
void free_Vector(Vector * x);
Vector * allocate_Vector(int n);
double norm(Vector * x);
void * difference(Vector *A, Vector *B, Vector *out);
