#ifndef __OUTPUT_H_
#define __OUTPUT_H_
#include "struct.h"

//menu
void display_options();
void display_operations1m();
void display_operations2m();
void display_findMatrix();
void display_checkTypes();

void Size(Matrix* A, int nb_r, int nb_c);
void enterValues(Matrix* A);
void clearBuffer();
void display_Matrix(Matrix A);
void display_Info_Matrix(Matrix A);

int restartOption(char name_opt[]);

#endif
