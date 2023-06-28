#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

int** Allocation();

void Sum();
void Product();
void Transpose(Matrix A);
void Invert(Matrix A);
void Trace();

Matrix Get_sum(Matrix A, Matrix B);
Matrix Get_product(Matrix A, Matrix B);
void Get_trace(Matrix* A);
void Get_rank(Matrix A);

#endif 
