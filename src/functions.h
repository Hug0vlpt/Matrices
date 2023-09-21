#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

//init
Matrix* newMatrix(int nb_r, int nb_c);
int** AllocationArr(int nb_r, int nb_c);
void assignArr(Matrix* B, Matrix A);
void assignMatrix(Matrix* B, Matrix A);

//operations with 2 matrices
void Sum();
void Product();
Matrix* Get_sum(Matrix A, Matrix B);
Matrix* Get_product(Matrix A, Matrix B);

//operations with one matrix
void Transpose();
Matrix* Get_transpose(Matrix A);
void Invert(Matrix A);

//operations on one matrix
void Trace(ArrM* Am);
void Get_trace(Matrix* A);
void ProductRow(ArrM* Am);
//void Get_rank(Matrix A);

//useful in functions
Matrix* Get_productScalar(Matrix A, int sc);
int enoughZeros(Matrix A, int start_i, int start_j, int end_i, int end_j);
int NbsameElemDiag(Matrix A, int elem);
int are_Equal(Matrix A, Matrix B);
int isRightSize(Matrix B, int size_check[3]);

//elementary row operations
void perfProdR(Matrix* A, int nb_row, int scal);
void perfSumR(Matrix* A, int nb_r1, int nb_r2, int scal);
void perfswapR(Matrix* A, int nb_r1, int nb_r2);

#endif 
