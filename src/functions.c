#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"

int** AllocationArr(int nb_r, int nb_c){
  int** arr = malloc(nb_r *sizeof(int*));
  
  for (int i=0; i<nb_r; ++i){
    arr[i] = malloc(nb_c *sizeof(int));
  }
  return arr;
}

Matrix newMatrix(int nb_r, int nb_c){
  Matrix A;
  A.nb_r = nb_r;
  A.nb_c = nb_c;
  A.arr = AllocationArr(nb_r, nb_c);
  //-1: we don't know, 0: no, 1: yes
  A.rk = -1;
  A.is_row = -1;
  A.is_column = -1;
  A.is_null = -1;
  A.is_id = -1;
  A.is_elem = -1;
  A.is_inv = -1;
  A.is_diag = -1;
  A.is_scal = -1;
  A.is_up_tr = -1;
  A.is_str_up_tr = -1;
  A.is_low_tr = -1;
  A.is_str_low_tr = -1;
  A.is_sym = -1;
  A.is_asym = -1;

  return A;
}

int Get_nbZeros(Matrix A){
  int nb_zeros = 0;
  for(int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_c; ++j){
      if (A.arr[i][j] == 0){
        nb_zeros++;
      }
    }
  }
  return nb_zeros;
}

Matrix Get_sum(Matrix A, Matrix B){
  Matrix C = newMatrix(A.nb_r, A.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_c; ++j){
      C.arr[i][j] = A.arr[i][j] + B.arr[i][j];
    }
  }
  return C;
}

void Sum()
{
  Matrix A,B,C;
  
  printf("The matrix A:\n\n");
  Size(&A);
  printf("\n");
  A.arr = AllocationArr(A.nb_r, A.nb_c);
  enterValues(&A);  

  B.nb_r = A.nb_r;
  B.nb_c = A.nb_c;
  B.arr = AllocationArr(B.nb_r, B.nb_c);
  printf("\nThe matrix B:\n");
  enterValues(&B);
  
  C = Get_sum(A,B);

  printf("\n");
  display_Matrix(A);
  printf("\n  +\n\n");
  display_Matrix(B);
  printf("\n  =\n\n");
  display_Matrix(C);
  printf("\n");
}

Matrix Get_product(Matrix A, Matrix B){
  Matrix C = newMatrix(A.nb_r, B.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<B.nb_c; ++j){
      int sum = 0;
      for (int k=0; k<A.nb_c; ++k){
        sum += A.arr[i][k] * B.arr[k][j];
      }
      C.arr[i][j] = sum;
    }
  }
  return C;
}

void Product()
{
  Matrix A,B,C;

  printf("The matrix A:\n");
  Size(&A);
  A.arr = AllocationArr(A.nb_r, A.nb_c);
  printf("\n");
  enterValues(&A);  

  printf("\nThe matrix B:\n");
  B.nb_r = A.nb_c;
  do {
    printf("Enter the number of columns of the matrix B: ");
    scanf("%d", &B.nb_c);
    if (B.nb_c<1){
      printf("Please enter a number upper or equal to 1.\n");
    }
  } while(B.nb_c<1);
  B.arr = AllocationArr(B.nb_r, B.nb_c);
  printf("\n");
  enterValues(&B);

  C = Get_product(A,B);

  printf("\n");
  display_Matrix(A);
  printf("\n  *\n\n");
  display_Matrix(B);
  printf("\n  =\n\n");
  display_Matrix(C);
  printf("\n");
}

void Get_trace(Matrix* A)
{
  int trace = 0;
  for (int i=0; i<A->nb_r; ++i){
    trace += A->arr[i][i];
  }
  A->trace = trace;
}

void Trace()
{
  Matrix A;
  do {
    printf("Enter the size of the matrix: ");
    scanf("%d", &A.nb_r);
    if (A.nb_r<1){
      printf("Please enter a size upper or equal to 1.\n");
    }
  } while(A.nb_r<1);
  A.nb_c = A.nb_r;

  A.arr = AllocationArr(A.nb_r, A.nb_c);
  printf("\n");
  enterValues(&A);
  printf("\n");
  display_Matrix(A);

  Get_trace(&A);
  printf("\nThe trace of the matrix A is equal to %d.\n\n",A.trace);
}

Matrix Get_transpose(Matrix A){
  Matrix T = newMatrix(A.nb_c, A.nb_r); 

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_c; ++j){
      T.arr[j][i] = A.arr[i][j];
    }
  }
  return T;
}

void Transpose()
{
  Matrix A, T;
  Size(&A);
  A.arr = AllocationArr(A.nb_r, A.nb_c);

  printf("\n");
  enterValues(&A);

  T = Get_transpose(A);
  
  printf("%d:\n",A.arr[0][1]);

  printf("\nThe transpose of\n");
  printf("\n");
  display_Matrix(A);
  printf("\nis\n\n");
  display_Matrix(T);
  printf("\n");
}
