#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

Matrix createMatrix(int nb_r, int nb_c);
int** AllocationArr(int nb_r, int nb_c);

void Sum();
void Product();
void Transpose();
void Invert(Matrix A);
void Trace();

Matrix Get_sum(Matrix A, Matrix B);
Matrix Get_product(Matrix A, Matrix B);

void Get_transpose(Matrix A);
void Get_trace(Matrix* A);
void Get_rank(Matrix A);

#endif 
