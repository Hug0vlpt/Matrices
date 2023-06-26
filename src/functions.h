#ifndef __FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "struct.h"

Matrix Allocation(Matrix A);
Matrix SUM(Matrix A, Matrix B);
Matrix Product(Matrix A, Matrix B);
Matrix Transpose(Matrix A);
Matrix Invert(Matrix A);

int Get_trace(Matrix A);
int Get_rank(Matrix A);

#endif__FUNCTIONS_H_
