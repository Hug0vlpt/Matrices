#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"

Matrix Allocation(int nb_r, int nb_c)
{
  Matrix A;
  A.arr = malloc(nb_r *sizeof(int*));
  
  for (int i=0; i<nb_r; ++i){
    A.arr[i] = malloc(nb_c *sizeof(int));
  }
  A.nb_r = nb_r;
  A.nb_c = nb_c;
  return A;
}

void Sum()
{
  Matrix A;
  Matrix B;
  Matrix C;
  
  printf("The first matrix:\n");
  Size(&A);
  A = Allocation(A.nb_r, A.nb_c);
  printf("\nThe matrix A:\n");
  enterValues(&A);  

  B.nb_r = A.nb_r;
  B.nb_c = A.nb_c;
  B = Allocation(B.nb_r, B.nb_c);
  printf("\nThe matrix B:\n");
  enterValues(&B);

  C.nb_r = A.nb_r;
  C.nb_c = A.nb_c;
  C = Allocation(C.nb_r, C.nb_c);

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
