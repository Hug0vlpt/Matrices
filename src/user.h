#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#include "struct.h"

//menu
void display_options(ArrM* Am);
void display_operations1m(ArrM* Am);
void display_operations2m(ArrM* Am);
void display_findMatrix(ArrM* Am);
void display_checkTypes();

void Size(Matrix* A, int nb_r, int nb_c);
void enterValues(Matrix* A);
void clearBuffer();
void display_Matrix(Matrix A);
void display_Info_Matrix(Matrix A);

void display_Am(ArrM Am);
void inputSaveM(ArrM* Am, Matrix* A, char txt[]);

int restartOption(char name_opt[]);
int chooseM(ArrM A, int size_check[3]);
Matrix* chooseNSmat(ArrM Am, int sq_check, int size_check[3], char txt[]);

#endif
