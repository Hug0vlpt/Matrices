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
    printf("Which operation do you want to perform ?\n\n"
        " - Trace (enter 1)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&operation);
    if (operation<1 || operation>2){
      printf("Please enter a number between 1 and 2\n");
    }
  } while(operation<1 || operation>2);
  system("clear");
  
  switch(operation){
    case 1: Trace(); break;    
    //case 2: Rank(); break;
  }
} 
 
void display_operations2m(){
 int operation;
  do{
    printf("Which operation do you want to perform ?\n\n"
        "  - Sum (enter 1)\n"
        "  - Product (enter 2)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&operation);
    if (operation<1 || operation>2){
      system("clear");
      printf("Please enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(operation<1 || operation>2);
  system("clear");
  
  switch(operation){
    case 1: Sum(); break;    
    case 2: Product(); break;
  }
} 

void display_findMatrix(){ 
 int option;
  do{
    printf("Which matrix do you want to find based on a matrix?\n\n"
        "  - Transpose (enter 1)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&option);
    if (option<1 || option>2){
      system("clear");
      printf("Please enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(option<1 || option>2);
  system("clear");
  
  switch(option){
    case 1: Transpose(); break;    
    //case 2: Invert(); break;
  }
} 

void display_checkTypes(){ 
 int type;
  do{
    printf("Which type do you want to test with a matrix ?\n\n"
        "  - Row matrix (enter 1)\n"
        "  - Column matrix (enter 2)\n"
        "  - Null matrix (enter 3)\n"
        "  - Square matrix (enter 4)\n"
        "  - Identity matrix (enter 5)\n"
        "  - Diagonal matrix (enter 6)\n"
        "  - Scalar matrix (enter 7)\n"
        "  - Triangular matrix (enter 8)\n"
        "  - Symmetric matrix (enter 9)\n"
        "  - Antisymmetric matrix (enter 10)\n\n"
        "Enter a number between 1 and 10: ");
    scanf("%d",&type);
    if (type<1 || type>10){
      system("clear");
      printf("Please enter a number between 1 and 10\n\n");
      clearBuffer();
    }
  } while(type<1 || type>10);
  system("clear");
  
  switch(type){
    case 1: is_Row(); break;    
    case 2: is_Column(); break;
    case 3: is_Null(); break;
    case 4: is_Square(); break;
    case 5: is_Identity(); break;
    case 6: is_Diagonal(); break;
    case 7: is_Scalar(); break;
    case 8: is_Triangular(); break;
    case 9: is_Symmetric(); break;
    case 10: is_AntiSymmetric(); break;
  }
} 

void display_options()
{
  int option;
  do{
    printf("Which action do you want to do ?\n\n"
        "  - Perform an operation on a matrix (enter 1)\n"
        "  - Perform operations between two matrices (enter 2)\n"
        "  - Find another matrix with a matrice (enter 3)\n"
        "  - Check if a matrix is a certain type (enter 4)\n\n"
        "Enter a number between 1 and 4: ");
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

void Size(Matrix* A, int nb_r, int nb_c)
{
  if (!nb_r) {
    do{
      printf("\nThe number of rows in the matrix: ");
      scanf("%d",&A->nb_r);
      if (A->nb_r <1){
        printf("The number of rows must be upper or equal to 1");
      }
    }while (A->nb_r <1);
    do{
      printf("The number of columns in the matrix: ");
      scanf("%d",&A->nb_c);
      if (A->nb_c <1){
        printf("The number of columns must be upper or equal to 1\n");
      }
    }while (A->nb_c <1);
  } else {
    A->nb_r = nb_r;
    A->nb_c = nb_c;
  }
  printf("\n");
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
