#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

Matrix Allocation();
void Sum();
void Product(Matrix A, Matrix B);
void Transpose(Matrix A);
void Invert(Matrix A);

void Get_trace(Matrix A);
void Get_rank(Matrix A);

#endif 
