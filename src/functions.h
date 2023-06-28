#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include "struct.h"

int** Allocation();
void Sum();
void Product();
void Transpose(Matrix A);
void Invert(Matrix A);

void Get_trace(Matrix A);
void Get_rank(Matrix A);

#endif 
