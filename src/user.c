#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "struct.h"
#include "functions.h"
#include "is_functions.h"

void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void display_operations1m(){
 int operation;
  do{
    printf("Which operation do you want to perform ? Trace (enter 1): ");
    scanf("%d",&operation);
    if (operation<0 || operation>2){
      printf("Please enter a number between 1 and 2\n");
    }
  } while(operation<0 || operation>2);
  system("clear");
  
  switch(operation){
    case 1: Trace(); break;    
    //case 2: Rank(); break;
  }
} 
 
void display_operations2m(){
 int operation;
  do{
    printf("Which operation do you want to perform ? Sum (enter 1)\nProduct (enter 2): ");
    scanf("%d",&operation);
    if (operation<0 || operation>2){
      system("clear");
      printf("\nPlease enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(operation<0 || operation>2);
  system("clear");
  
  switch(operation){
    case 1: Sum(); break;    
    case 2: Product(); break;
  }
} 

void display_findMatrix(){ 
 int option;
  do{
    printf("Which matrix do you want to find based on a matrix? Transpose (enter 1): ");
    scanf("%d",&option);
    if (option<0 || option>2){
      system("clear");
      printf("\nPlease enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(option<0 || option>2);
  system("clear");
  
  switch(option){
    case 1: Transpose(); break;    
    //case 2: Invert(); break;
  }
} 

void display_checkTypes(){ 
 int type;
  do{
    printf("Which type do you want to test with a matrix ?\nRow Matrix (enter 1): ");
    scanf("%d",&type);
    if (type<0 || type>2){
      system("clear");
      printf("\nPlease enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(type<0 || type>2);
  system("clear");
  
  switch(type){
    case 1: is_Row(); break;    
  }
} 

void display_options()
{
  int option;
  do{
    printf("Which action do you want to do ?\nPerform an operation on a matrix (enter 1)\nPerform operations between two matrices (enter 2)\nFind another matrix with a matrice (enter3)\nCheck if a matrix is a certain type (enter 4)\nEnter a number between 1 and 4: ");
    scanf("%d",&option);
    if (option<1 || option>4){
      system("clear"); 
      printf("\nPlease enter a number between 1 and 4\n\n");
      clearBuffer();
    }
  } while(option<1 || option>4);
    system("clear");

  switch(option){
    case 1: display_operations1m(); break;    
    case 2: display_operations2m(); break;
    case 3: display_findMatrix(); break;
    case 4: display_checkTypes(); break;
  }
}

void Size(Matrix* A)
{
  do{
    printf("The number of rows of the matrix: ");
    scanf("%d",&A->nb_r);
    if (A->nb_r <1){
      printf("The number of rows must be upper or equal to 1");
    }
  }while (A->nb_r <1);
  do{
    printf("The number of columns of the matrix: ");
    scanf("%d",&A->nb_c);
    if (A->nb_c <1){
      printf("The number of columns must be upper or equal to 1");
    }
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
