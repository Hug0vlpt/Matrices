#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

Matrix* newMatrix(int nb_r, int nb_c);
int** AllocationArr(int nb_r, int nb_c);

void Sum();
void Product();
void Transpose();
void Invert(Matrix A);
void Trace();

Matrix Get_sum(Matrix A, Matrix B);
Matrix Get_product(Matrix A, Matrix B);

int Get_nbZeros(Matrix A);
int NbsameElemDiag(Matrix A, int elem);
void Get_transpose(Matrix A);
void Get_trace(Matrix* A);
void Get_rank(Matrix A);

#endif 
