#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "struct.h"
#include "functions.h"
#include "is_functions.h"
#include "save.h"

void clearBuffer() {
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void display_operations1m(ArrM* Am){
 int operation;
  do{
    printf("Which operation do you want to perform ?\n\n"
        "\t- Trace    (enter 1)\n"
        "\t- Product in a row (enter 2)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&operation);
    if (operation<1 || operation>2){
      printf("\e[1;1H\e[2J");
      printf("Please enter a number between 1 and 2\n\n");
    }
  } while(operation<1 || operation>2);
  printf("\e[1;1H\e[2J");
  
  switch(operation){
    case 1: do { Trace(Am); } while(restartOption("Trace calculation")==1); break;    
    case 2: do { ProductRow(Am); } while(restartOption("Product in a row")==1); break;
    //case 2: Rank(); break;
  }
} 
 
void display_operations2m(ArrM* Am){
 int operation;
  do{
    printf("Which operation do you want to perform ?\n\n"
        "\t- Sum        (enter 1)\n"
        "\t- Product    (enter 2)\n\n"
        "Enter a number between 1 and 2: ");
    scanf("%d",&operation);
    if (operation<1 || operation>2){
      printf("\e[1;1H\e[2J");
      printf("Please enter a number between 1 and 2\n\n");
      clearBuffer();
    }
  } while(operation<1 || operation>2);
  printf("\e[1;1H\e[2J");
  
  switch(operation){
    case 1: do { Sum(Am); } while(restartOption("Sum operations")==1); break;    
    case 2: do { Product(Am); } while(restartOption("Product operations")==1); break;
  }
} 

void display_findMatrix(ArrM* Am){ 
 int option;
  do{
    printf("Which matrix do you want to find based on a matrix?\n\n"
        "\t- Transpose    (enter 1)\n\n"
        "Enter a number between 1 and 1: ");
    scanf("%d",&option);
    if (option<1 || option>1){
      printf("\e[1;1H\e[2J");
      printf("Please enter a number between 1 and 1\n\n");
      clearBuffer();
    }
  } while(option<1 || option>1);
  printf("\e[1;1H\e[2J");
  
  switch(option){
    case 1: do { Transpose(Am); } while(restartOption("Transpose matrices")==1); break;    
    //case 2: Invert(); break;
  }
} 

void display_checkTypes(ArrM* Am){ 
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
      printf("\e[1;1H\e[2J");
      printf("Please enter a number between 1 and 10\n\n");
      clearBuffer();
    }
  } while(type<1 || type>10);
  printf("\e[1;1H\e[2J");
  
  switch(type){
    case 1: do { is_Row(Am); } while(restartOption("Row matrices")==1); break;    
    case 2: do { is_Column(Am); } while(restartOption("Column matrices")==1); break;
    case 3: do { is_Null(Am); } while(restartOption("Null matrices")==1); break;
    case 4: do { is_Square(Am); } while(restartOption("Square matrices")==1); break;
    case 5: do { is_Identity(Am); } while(restartOption("Identity matrices")==1); break;
    case 6: do { is_Diagonal(Am); } while(restartOption("Diagonal matrices")==1); break;
    case 7: do { is_Scalar(Am); } while(restartOption("Scalar matrices")==1); break;
    case 8: do { is_Triangular(Am); } while(restartOption("Triangular matrices")==1); break;
    case 9: do { is_Symmetric(Am); } while(restartOption("Symmetric matrices")==1); break;
    case 10:do { is_AntiSymmetric(Am); } while(restartOption("Antisymmetric matrices")==1); break;
  }
} 

void display_options(ArrM* Am)
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
      printf("\e[1;1H\e[2J");
      printf("\nPlease enter a number between 1 and 4\n\n");
      clearBuffer();
    }
  } while(option<1 || option>4);
  printf("\e[1;1H\e[2J");

  switch(option){
    case 1: display_operations1m(Am); break;    
    case 2: display_operations2m(Am); break;
    case 3: display_findMatrix(Am); break;
    case 4: display_checkTypes(Am); break;
  }
}

void Size(Matrix* A, int nb_r, int nb_c)
{
  if (!nb_r) {
    do{
      printf("\nEnter the amount of rows in the matrix: ");
      scanf("%d",&A->nb_r);
      if (A->nb_r <1){
        printf("The amount of rows must be upper or equal to 1");
      }
    }while (A->nb_r <1);
  } else {
    A->nb_r = nb_r;
  }
  if (!nb_c) {
    do{
      printf("Enter the amount of columns in the matrix: ");
      scanf("%d",&A->nb_c);
      if (A->nb_c <1){
        printf("The amount of columns must be upper or equal to 1\n");
      }
    }while (A->nb_c <1);
  } else {
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
  int l;
  
  printf("Do you want to continue with the %s ? (y/n): ", name_opt);
  clearBuffer();
  l = getchar();
  restart = (l == 'y');
  printf("\e[1;1H\e[2J");

  return restart;
}

void display_Am(ArrM Am)
{
  printf("\nSaved matrices:\n\n|");
  for (int i=0; i<Am.nb_mat; i++) {
    printf(" %s |",Am.arr[i]->name);
  }
  printf("\n");
}

void inputSaveM(ArrM* Am, Matrix* A, char txt[]) 
{
  int l;
  int i = -1;
  char name[2];

  printf("Do you want to save the %s ? (y/n): ", txt);
  clearBuffer();
  l = getchar();
  if(l == 'y') {
    do {
      printf("\nEnter the name of the matrix (1 character): ");
      clearBuffer();
      fgets(name,2* sizeof(char), stdin);
      if (Am->nb_mat+1 > 1) { i = findIndexAm(*Am, name); }
      if (i != -1) { printf("\nThe name %s is already taken. Choose another name.\n", name); }
    } while(i != -1);
    SaveMatrix(Am, A, name);
  }
  printf("\n");
}

int chooseM(ArrM Am, int size_check[3]) {
  char name[5];
  char nm[2];
  int i = 0;

  do {
    display_Am(Am);
    printf("\nEnter the name of the matrix you want to use (<name>/'quit'): ");
    clearBuffer();
    scanf( "%5[^\n]", name);
    
    //if user doesn't want to quit
    if (strcmp(name, "quit")) { 
      strncpy(nm, name, 2);
      i = findIndexAm(Am,nm);
    }
    //if matrix not found
    if (i<0) { 
      printf("\e[1;1H\e[2J");
      printf("There isn't a saved matrix called %s. Retry.\n",name); 
    //if the size is unchecked when necessary
    } else if (size_check[0] < 0 && strcmp(name, "quit")) {
      size_check[0] = isRightSize(*Am.arr[i],size_check);
    }


  } while (i<0 || (size_check[0] < 0 && strcmp(name,"quit")));

  return (strcmp(name,"quit")) ? i : -1;
}

Matrix* chooseNSmat(ArrM Am, int sq_check, int size_check[3], char txt[]) {
  Matrix* A;
  int l;
  int i = -1;
  int savedM = 0;
  
  if (Am.nb_mat != 0) {
    printf("\n%so you want to use a new matrix or a saved one? (n/s): ", txt);
    clearBuffer();
    l = getchar();

    if (l == 's') {
      i = chooseM(Am,size_check);
      //if a saved matrix has been chosen
      if (i > -1) {
        A = Am.arr[i];
        savedM = 1;
        if (sq_check) { is_SquareM(A); }
      }
    }
  }
  //if a saved matrix hasn't been chosen
  if (!savedM) {
    // if (size_check[0] == -1 (sum) { 
    // size_check[1] = A.nb_r; 
    // size_check[2] = A.nb_c;
    // } else if (size_check[0] == -2) {
    // size_check[1] = A.nb_c;
    // } else { .. = 0; }

    //we can choose the amount of columns    
    if (size_check[0] == -2) { size_check[2] = 0; } 

    A = newMatrix(size_check[1], size_check[2]);
    if (sq_check) { 
      is_SquareM(A);
      if (A->is_sq) {
        enterValues(A);
      }
    } else {
      enterValues(A);
    }
  }
  return A;
}
