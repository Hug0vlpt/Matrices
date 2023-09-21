#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "functions.h"
#include "is_functions.h"
#include "user.h"
#include "save.h"

int** AllocationArr(int nb_r, int nb_c){
  int** arr = malloc(nb_r *sizeof(int*));
  
  for (int i=0; i<nb_r; ++i){
    arr[i] = malloc(nb_c *sizeof(int));
  }
  return arr;
}

Matrix* newMatrix(int nb_r, int nb_c){
  Matrix* A = malloc(sizeof(Matrix));
  Size(A,nb_r, nb_c);
  A->arr = AllocationArr(A->nb_r, A->nb_c);
  //-1: we don't know, 0: no, 1: yes
  A->trace = -1;
  A->rk = -1;
  A->is_saved = 0;
  A->is_row = -1;
  A->is_column = -1;
  A->is_sq = -1;
  A->is_null = -1;
  A->is_id = -1;
  A->is_diag = -1;
  A->is_scal = -1;
  A->is_up_tr = -1;
  A->is_str_up_tr = -1;
  A->is_low_tr = -1;
  A->is_str_low_tr = -1;
  A->is_sym = -1;
  A->is_asym = -1;
  A->is_inv = -1;

  return A;
}

int enoughZeros(Matrix A, int start_i, int start_j, int end_i, int end_j){
  int e_zeros = 1;
  int i = start_i;
  int j;
  if (start_j == -2) { j = i-1; } else { j = start_j; }

  int e_i = end_i;
  int e_j;
  if (end_j == -1) { e_j = i; } else if (end_j == -2) { e_j = i+1; } else { e_j = end_j; }

  do {  
    e_zeros = A.arr[i][j] == 0;
    if (j == e_j-1) {
      j = 0;
      i++;
      if (end_j == -1) {
        e_j = i;
      } else if (end_j == -2) {
        e_j = i+1;
      }
    } else {
      j++;
    }
  } while (e_zeros && i<e_i);

  return e_zeros;
}

int NbsameElemDiag(Matrix A, int elem) {
  int nb = 0;

  for (int i=0; i<A.nb_r; ++i){
    if (A.arr[i][i] == elem){
      nb++;
    } else {
      break;
    }
  }
  return nb;
}

Matrix* Get_sum(Matrix A, Matrix B){
  Matrix* C = newMatrix(A.nb_r, A.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_c; ++j){
      C->arr[i][j] = A.arr[i][j] + B.arr[i][j];
    }
  }
  return C;
}

int are_Equal(Matrix A, Matrix B)
{
  if (A.nb_r == B.nb_r && A.nb_c == B.nb_c) {
    for (int i=0; i<A.nb_r; ++i) {
      for (int j=0; j<A.nb_r; ++j) {
        if (A.arr[i][j] != B.arr[i][j]) {
          return 0;
        }
      }
    }
  } else {
    return -1;
  }
  return 1;
}

void Sum(ArrM* Am)
{
  Matrix* A;
  Matrix* B;
  Matrix* C;
  int size_check1[3] = {0,0,0};
  
  A = chooseNSmat(*Am, 0, size_check1, "For the first matrix, d");

  printf("\e[1;1H\e[2J");
  int size_check2[3] = {-1, A->nb_r, A->nb_c};
  B = chooseNSmat(*Am, 0, size_check2, "For the second matrix, d");

  C = Get_sum(*A,*B);

  display_Matrix(*A);
  printf("\n  +\n\n");
  display_Matrix(*B);
  printf("\n  =\n\n");
  display_Matrix(*C);
  printf("\n");

  if (!A->is_saved) { inputSaveM(Am,A,"first matrix"); }
  if (!B->is_saved) { inputSaveM(Am,B,"second matrix"); }
  inputSaveM(Am,C,"sum of the matrices");
}

Matrix* Get_product(Matrix A, Matrix B){
  Matrix* C = newMatrix(A.nb_r, B.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<B.nb_c; ++j){
      int sum = 0;
      for (int k=0; k<A.nb_c; ++k){
        sum += A.arr[i][k] * B.arr[k][j];
      }
      C->arr[i][j] = sum;
    }
  }
  return C;
}

void Product(ArrM* Am)
{
  Matrix* A;
  Matrix* B;
  Matrix* C;
  int size_check1[3] = {0,0,0};
  
  A = chooseNSmat(*Am, 0, size_check1, "For the first matrix, d");

  printf("\e[1;1H\e[2J");
  int size_check2[3] = {-2, A->nb_c, A->nb_r};
  B = chooseNSmat(*Am, 0, size_check2, "For the second matrix, d");

  C = Get_product(*A,*B);

  display_Matrix(*A);
  printf("\n  *\n\n");
  display_Matrix(*B);
  printf("\n  =\n\n");
  display_Matrix(*C);
  printf("\n");

  if (!A->is_saved) { inputSaveM(Am,A,"first matrix"); }
  if (!B->is_saved) { inputSaveM(Am,B,"second matrix"); }
  inputSaveM(Am,C,"product of the matrices");
}

Matrix* Get_productScalar(Matrix A, int sc)
{
  Matrix* B = newMatrix(A.nb_r,A.nb_c);
  for (int i=0; i<A.nb_r; ++i) {
    for (int j=0; j<A.nb_c; ++j) {
      B->arr[i][j] = A.arr[i][j] * sc;
    }
  }
  return B;
}

void Get_trace(Matrix* A)
{
  int trace = 0;
  for (int i=0; i<A->nb_r; ++i){
    trace += A->arr[i][i];
  }
  A->trace = trace;
}

void Trace(ArrM* Am)
{
  Matrix* A = malloc(sizeof(Matrix));
  int size_check[3] = {0,0,0};
  
  A = chooseNSmat(*Am, 1, size_check, "D");
  
  if (A->is_sq) {
    Get_trace(A);
    printf("\nThe trace of the matrix\n\n");
    display_Matrix(*A);  
    printf("\nis equal to %d.\n\n",A->trace);

    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
  } else {
    printf("The trace can't be calculated because the matrix isn't a square one.\n\n");
  }
}

void perfProdR(Matrix* A, int nb_row, int scal)
{
  for (int j=0; j<A->nb_c; ++j) {
    A->arr[nb_row][j] *= scal;
  }
}

void ProductRow(ArrM* Am) 
{
  Matrix* A = malloc(sizeof(Matrix));
  char restartSame[2];
  int size_check[3] = {0,0,0};
  int nb_row, scal;

  A = chooseNSmat(*Am, 1, size_check, "D");
  
  do { 
    printf("\e[1;1H\e[2J");
    printf("\nYou chosed the matrix\n\n");
    display_Matrix(*A);

    if (A->nb_r == 1) {
      nb_row = 1;
    } else {
      printf("\nEnter the number of the row that will be modified (1 -> %d): ",A->nb_r);
      scanf("%d",&nb_row);
    }
    printf("\nEnter the value of the scalar number: ");
    scanf("%d",&scal);

    perfProdR(A, nb_row-1, scal);

    printf("\nThe matrix is now\n\n");
    display_Matrix(*A);
    printf("\nDo you want to continue with the same matrix ? (y/n): ");
    clearBuffer();
    fgets(restartSame, 2, stdin);
    printf("\n");
  } while(!strcmp(restartSame, "y"));

  if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
}

void sumRows(Matrix* A, int nb_r1, int nb_r2, int scal)
{
  for (int j=0; j<A->nb_c; ++j) {
    A->arr[nb_r1][j] += A->arr[nb_r2][j] * scal;
  }
}

void swapRows(Matrix* A, int nb_r1, int nb_r2)
{
  int temp;
  for (int j=0; j<A->nb_c; ++j) {
    temp = A->arr[nb_r1][j];
    A->arr[nb_r1][j] = A->arr[nb_r2][j];
    A->arr[nb_r2][j] = temp;
  }
}

Matrix* Get_transpose(Matrix A){
  Matrix* T = newMatrix(A.nb_c, A.nb_r); 

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_c; ++j){
      T->arr[j][i] = A.arr[i][j];
    }
  }
  return T;
}

void Transpose(ArrM* Am)
{
  Matrix* A;
  Matrix* T;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 0, size_check, "D");

  T = Get_transpose(*A);
  
  printf("The transpose of\n");
  printf("\n");
  display_Matrix(*A);
  printf("\nis\n\n");
  display_Matrix(*T);
  printf("\n");
  
  if (!A->is_saved) { inputSaveM(Am,A,"first matrix"); }
  inputSaveM(Am,T,"transpose of the first matrix");
}

void assignArr(Matrix* B, Matrix A)
{
  for (int i=0; i<A.nb_r; ++i) {
    for (int j=0; j<A.nb_c; ++j) {
      B->arr[i][j] = A.arr[i][j];
    }
  }
}

void assignMatrix(Matrix* B, Matrix A)
{
  Size(B, A.nb_r, A.nb_c);
  B->arr = AllocationArr(B->nb_r, B->nb_c);
  assignArr(B,A);

  B->rk = A.rk;
  B->is_row = A.is_row;
  B->is_column = A.is_column;
  B->is_sq = A.is_sq;
  B->is_null = A.is_null;
  B->is_id = A.is_id;
  B->is_diag = A.is_diag;
  B->is_scal = A.is_scal;
  B->is_up_tr = A.is_up_tr;
  B->is_str_up_tr = A.is_str_up_tr;
  B->is_low_tr = A.is_low_tr;
  B->is_str_low_tr = A.is_str_low_tr;
  B->is_sym = A.is_sym;
  B->is_asym = A.is_asym; 
  B->is_inv = A.is_inv; 
}

int isRightSize(Matrix B, int size_check[3]) {
  int right_size = 0;

  switch (size_check[0]) {
    //sum
    case -1: 
      right_size = (B.nb_r == size_check[1] && B.nb_c == size_check[2]); 
      if (!right_size) { 
        printf("\e[1;1H\e[2J");
        printf("\nYou must choose a matrix with the same size as the first matrix (%d rows and %d columns).\n",size_check[1], size_check[2]); 
      }
      break;
    //product
    case -2: 
      right_size = (B.nb_r == size_check[1]); // index 1 because: see comments in chooseNSmat in user.c  
      if (!right_size) {
        printf("\e[1;1H\e[2J");
        printf("\nYou must choose a matrix with the same amount of rows as the amount of columns of the first matrix (%d rows needed)", size_check[1]);
      }
      break;
  }
  return (right_size) ? -size_check[0] : size_check[0];
}
