#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "struct.h"
#include "functions.h"

void display_options()
{
  int option;
  do{
    printf("Which action do you want to do ? Sum (enter 1)/ Product (enter 2)/ Trace (enter 3): ");
    scanf("%d",&option);
    clearBuffer();
    if (option<0 || option>3){
      printf("Please enter a number between 1 and 3\n");
    }
  } while(option<0 || option>3);
  system("clear");
  
  switch(option){
    case 1: Sum(); break;    
    case 2: Product(); break;
    case 3: Trace(); break;
  }
}

void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void Size(Matrix* A)
{
  do{
    printf("The number of rows of the matrix: ");
    scanf("%d",&A->nb_r);
    if (A->nb_r <1){
      printf("The number of rows must be upper or equal to 1");
    }
    clearBuffer();
  }while (A->nb_r <1);
  do{
    printf("The number of columns of the matrix: ");
    scanf("%d",&A->nb_c);
    if (A->nb_c <1){
      printf("The number of columns must be upper or equal to 1");
    }
    clearBuffer();
  }while (A->nb_c <1);
}

void enterValues(Matrix* A)
{
  for (int i=0; i<A->nb_r; ++i){
    for (int j=0; j<A->nb_c; ++j){
      printf("Enter the value of the row n°%d and the column n°%d: ",i+1,j+1);
      scanf("%d",&A->arr[i][j]);
    }
  }
}

void display_Matrix(Matrix A)
{
  for (int i=0; i<A.nb_r; ++i){
    printf("  | ");
    for (int j=0; j<A.nb_c; ++j){
      printf("%d | ",A.arr[i][j]);
    }
    printf("\n");
  }
}
