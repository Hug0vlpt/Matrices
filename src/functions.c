#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"

int** Allocation(int nb_r, int nb_c)
{
  int** arr = malloc(nb_r *sizeof(int*));
  
  for (int i=0; i<nb_r; ++i){
    arr[i] = malloc(nb_c *sizeof(int));
  }
  return arr;
}

void Sum()
{
  Matrix A,B,C;
  
  printf("The matrix A:\n\n");
  Size(&A);
  printf("\n");
  A.arr = Allocation(A.nb_r, A.nb_c);
  enterValues(&A);  

  B.nb_r = A.nb_r;
  B.nb_c = A.nb_c;
  B.arr = Allocation(B.nb_r, B.nb_c);
  printf("\nThe matrix B:\n");
  enterValues(&B);

  C.nb_r = A.nb_r;
  C.nb_c = B.nb_c;
  C.arr = Allocation(C.nb_r, C.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<A.nb_r; ++j){
      C.arr[i][j] = A.arr[i][j] + B.arr[i][j];
    }
  }
  printf("\n");
  display_Matrix(A);
  printf("\n  +\n\n");
  display_Matrix(B);
  printf("\n  =\n\n");
  display_Matrix(C);
  printf("\n");
}

void Product()
{
  Matrix A,B,C;

  printf("The matrix A:\n");
  Size(&A);
  A.arr = Allocation(A.nb_r, A.nb_c);
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
  B.arr = Allocation(B.nb_r, B.nb_c);
  enterValues(&B);

  C.nb_r = A.nb_r;
  C.nb_c = B.nb_c;
  C.arr = Allocation(C.nb_r, C.nb_c);

  for (int i=0; i<A.nb_r; ++i){
    for (int j=0; j<B.nb_c; ++j){
      int sum = 0;
      for (int k=0; k<A.nb_c; ++k){
        sum += A.arr[i][k] * B.arr[k][j];
      }
      C.arr[i][j] = sum;
    }
  }
  
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

  A.arr = Allocation(A.nb_r, A.nb_c);
  printf("\n");
  enterValues(&A);
  printf("\n");
  display_Matrix(A);

  Get_trace(&A);
  printf("\nThe trace of the matrix A is equal to %d.\n\n",A.trace);
}
