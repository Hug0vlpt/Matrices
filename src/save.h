#ifndef __SAVE_H_
#define __SAVE_H_
#include "struct.h"

//functions for saving the matrix
ArrM* InitAm();
void AllocationArrM(ArrM* Am, int rea);
void SaveMatrix(ArrM* Am, Matrix* A, char name[2]);
void stockInfoM(Matrix* A, char* info, int nb_l, int nb_c, int nb_r);
void SaveMFile(FILE* fsave, Matrix A);
int findIndexAm(ArrM Am, char name[2]);
void pullAmf(ArrM* Am);
void pushAmf(ArrM* Am);

#endif
