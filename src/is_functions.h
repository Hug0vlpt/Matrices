#ifndef __ISFUNCTIONS_H_
#define __ISFUNCTIONS_H_
#include "struct.h"

int is_Row(Matrix A);
int is_Column(Matrix A);
int is_Null(Matrix A);
int is_Square(Matrix A);
int is_Identity(Matrix A);
int is_Elementary(Matrix A);
int is_Invertible(Matrix A);
int is_Diagonal(Matrix A);
int is_Scalar(Matrix A);
int is_Upper_Triangle(Matrix A);
int is_Strictly_Upper_Triangle(Matrix A);
int is_Lower_Triangle(Matrix A);
int is_Strictly_Lower_Triangle(Matrix A);
int is_Symmetric(Matrix A);
int is_AntiSymmetric(Matrix A);

#endif
