#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        "\t- Trace    (enter 1)\n\n"
        "Enter a number between 1 and 1: ");
    scanf("%d",&operation);
    if (operation<1 || operation>1){
      printf("Please enter a number between 1 and 1\n");
    }
  } while(operation<1 || operation>1);
  system("clear");
  
  switch(operation){
    case 1: do { Trace(); } while(restartOption("Trace calculation")==1); break;    
    //case 2: Rank(); break;
  }
} 
 
void display_operations2m(){
 int operation;
  do{
    printf("Which operation do you want to perform ?\n\n"
        "\t- Sum        (enter 1)\n"
        "\t- Product    (enter 2)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&operation);
    if (operation<1 || operation>2){
      system("clear");
      printf("Please enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(operation<1 || operation>2);
  printf("\e[1;1H\e[2J");
  
  switch(operation){
    case 1: do { Sum(); } while(restartOption("Sum operations")==1); break;    
    case 2: do { Product(); } while(restartOption("Product operations")==1); break;
  }
} 

void display_findMatrix(){ 
 int option;
  do{
    printf("Which matrix do you want to find based on a matrix?\n\n"
        "\t- Transpose    (enter 1)\n\n"
        "Enter a number between 1 and 1: ");
    scanf("%d",&option);
    if (option<1 || option>1){
      system("clear");
      printf("Please enter a number between 1 and 1\n\n");
      clearBuffer();
    }
  } while(option<1 || option>1);
  printf("\e[1;1H\e[2J");
  
  switch(option){
    case 1: do { Transpose(); } while(restartOption("Transpose matrices")==1); break;    
    //case 2: Invert(); break;
  }
} 

void display_checkTypes(){ 
 int type;
  do{
    printf("Which type do you want to test with a matrix ?\n\n"
        "\t- Row matrix             (enter 1)\n"
        "\t- Column matrix          (enter 2)\n"
        "\t- Null matrix            (enter 3)\n"
        "\t- Square matrix          (enter 4)\n"
        "\t- Identity matrix        (enter 5)\n"
        "\t- Diagonal matrix        (enter 6)\n"
        "\t- Scalar matrix          (enter 7)\n"
        "\t- Triangular matrix      (enter 8)\n"
        "\t- Symmetric matrix       (enter 9)\n"
        "\t- Antisymmetric matrix   (enter 10)\n\n"
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
    case 1: do { is_Row(); } while(restartOption("Row matrices")==1); break;    
    case 2: do { is_Column(); } while(restartOption("Column matrices")==1); break;
    case 3: do { is_Null(); } while(restartOption("Null matrices")==1); break;
    case 4: do { is_Square(); } while(restartOption("Square matrices")==1); break;
    case 5: do { is_Identity(); } while(restartOption("Identity matrices")==1); break;
    case 6: do { is_Diagonal(); } while(restartOption("Diagonal matrices")==1); break;
    case 7: do { is_Scalar(); } while(restartOption("Scalar matrices")==1); break;
    case 8: do { is_Triangular(); } while(restartOption("Triangular matrices")==1); break;
    case 9: do { is_Symmetric(); } while(restartOption("Symmetric matrices")==1); break;
    case 10:do { is_AntiSymmetric(); } while(restartOption("Antisymmetric matrices")==1); break;
  }
} 

void display_options()
{
  int option;
  do{
    printf("Which action do you want to do ?\n\n"
        "\t- Perform an operation on a matrix           (enter 1)\n"
        "\t- Perform operations between two matrices    (enter 2)\n"
        "\t- Find another matrix with a matrice         (enter 3)\n"
        "\t- Check if a matrix is a certain type        (enter 4)\n\n"
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
  char *token = malloc(20*sizeof(char));
  //i_t and j_t allows us to know in which box the 'r' was written
  int i_t = -1; 
  int j_t = -1;

  for (int i=0; i<A->nb_r; ++i){
    for (int j=0; j<A->nb_c; ++j){
      printf("Enter the value of the row n°%d and the column n°%d (<nb>/r): ",i+1,j+1);
      //erase the digit to be replaced
      if (!strcmp(token,"r")) { printf("                  \b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b"); }
      //erase the 'r' 
      if (i == i_t && j == j_t) { printf(" \b"); }

      clearBuffer();
      scanf( "%20[^\n]", token);

      if (!strcmp(token,"r")) {
        i_t = i;
        j_t = j;
        if (i==0 && j==0) { 
          printf("We are on the first box of the matrix.               \n");
          j -= 1;
        } else if (j==0) {
          j = A->nb_c-2; 
          i -= 1;
        } else {
          j -= 2;
        }
        //places the cursor on the digit to be replaced
        printf("\e[2A");
      } else {
        A->arr[i][j] = atoi(token);
      }
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

int restartOption(char name_opt[]) {
  int restart = 0;
  char token[2];

  printf("Do you want to continue with the %s ? (y/n): ", name_opt);
  clearBuffer();
  fgets(token, 2, stdin);
  restart = !strcmp(token,"y");
  printf("\e[1;1H\e[2J");

  return restart;
}
