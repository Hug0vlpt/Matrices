#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"
#include "functions.h"

void is_RowM(Matrix* A)
{
  if (A->nb_r == 1){
    A->is_row = 1;
  } else {
    A->is_row = 0;
  }
}

void is_Row()
{
  Matrix* A; 
  printf("\n");
  A = newMatrix(0,0);
  enterValues(A);

  is_RowM(A);
  if (A->is_row){
    printf("The matrix is a row one.\n\n");
  } else {
    printf("The matrix isn't a row one.\n\n");
  }
}

void is_ColumnM(Matrix* A)
{
  if (A->nb_c == 1){
    A->is_column = 1;
  } else {
    A->is_column = 0;
  }
}

void is_Column()
{
  Matrix* A;
  printf("\n");
  A = newMatrix(0,0);
  enterValues(A);
  
  is_ColumnM(A);

  if (A->is_column){
    printf("The matrix is a column one.\n\n");
  } else {
    printf("The matrix isn't a column one.\n\n");
  }
}

void is_NullM(Matrix* A)
{
  int nb_zeros = Get_nbZeros(*A);

  if (nb_zeros == (A->nb_r * A->nb_c)){
    A->is_null = 1;
  } else {
    A->is_null = 0;
  }
}

void is_Null()
{
  Matrix* A;
  A = newMatrix(0,0);
  printf("\n");
  enterValues(A);

  is_NullM(A);
  
  if (A->is_null){
    printf("\nThe matrix is null.\n\n");
  } else {
    printf("\nThe matrix isn't null.\n\n");
  }
}

void is_SquareM(Matrix* A)
{
  if (A->nb_r == A->nb_c){
    A->is_sq = 1;
  } else {
    A->is_sq = 0;
  }
}

void is_Square()
{
  Matrix* A;
  
  A = newMatrix(0,0);
  printf("\n");
  enterValues(A);

  is_SquareM(A);

  if (A->is_sq){
    printf("\nThe matrix is a square one.\n\n");
  } else {
    printf("\nThe matrix isn't a square one.\n\n");
  }
}

void is_IdentityM(Matrix* A)
{
  if (A->is_sq < 0){
    is_SquareM(A);
  }
  if (A->is_sq){
    int nb_zeros = Get_nbZeros(*A);
    int nb_one = NbsameElemDiag(*A,1);

    if (nb_zeros == ((A->nb_r*A->nb_c)-A->nb_r) && nb_one == A->nb_r){
      A->is_id = 1;
    } else {
      A->is_id = 0;
    }
  } else {
    A->is_id = 0;
  }
}

void is_Identity()
{
  Matrix* A;
  A = newMatrix(0,0);
  printf("\n");

  is_SquareM(A);
  if (A->is_sq){
    enterValues(A);
  }
  is_IdentityM(A);

  if (A->is_sq){
    if (A->is_id){
      printf("\nThe matrix is an identity one.\n\n");
    } else {
      printf("\nThe matrix isn't an identity one.\n\n");
    }
  } else {
    printf("\nThe matrix can't be an identity one because it isn't a square one.\n\n");
  }
}

void is_DiagonalM(Matrix* A)
{
  if (A->is_sq < 0){
    is_Square(A);
  }
  if (A->is_sq){
    int zero, i, j;
    zero = 1;
    i = j = 0;
    do {
      if (i!=j){
        zero = (A->arr[i][j] == 0);
      }
      if (j == (A->nb_c-1)){
        j = 0;
        i++;
      } else {
        j++;
      }
    } while(zero && i<A->nb_r);

    if (zero) {
      A->is_diag = 1;
    } else {
      A->is_diag = 0;
    }
  } else {
    A->is_diag = 0;
  }
}

void is_Diagonal()
{
  Matrix* A;
  
  A = newMatrix(0,0);
  printf("\n");
  
  if (A->is_id == 1){
    A->is_diag = 1;
  } else {
    is_SquareM(A);

    if (A->is_sq){
      enterValues(A);
    }
    is_DiagonalM(A);
  }

  if (A->is_sq){
    if (A->is_diag){
      printf("\nThe matrix is a diagonal one.\n\n");
    } else {
      printf("\nThe matrix isn't a diagonal one.\n\n");
    }
  } else {
    printf("\nThe matrix can't be a diagonal one because it isn't a square one.\n\n");
  }
}

void is_ScalarM(Matrix* A)
{
  int nb_elem_diag;
  
  if (A->is_diag < 0) {
    is_DiagonalM(A);
  } 
  
  if (A->is_diag == 1) {
    nb_elem_diag = NbsameElemDiag(*A, A->arr[0][0]);

    if (nb_elem_diag == A->nb_c) {
      A->is_scal = 1;
    } else {
      A->is_scal = 0;
    }
  } else {
    A->is_scal = 0;
  }
}

void is_Scalar()
{
  Matrix* A;
  
  A = newMatrix(0,0);
  printf("\n");
  is_SquareM(A);
  if (A->is_sq){
    enterValues(A);
  }
  if (A->is_id == 1 || A->is_null == 1){
    A->is_scal = 1;
  } else {
    is_ScalarM(A);
  }

  if (A->is_sq){
    if (A->is_scal){
      printf("\nThe matrix is a scalar one.\n\n");
    } else {
      printf("\nThe matrix isn't a scalar one.\n\n");
    }
  } else {
    printf("\nThe matrix can't be a scalar one because it isn't a square one.\n\n");
  }
}

