#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"
#include "functions.h"

void is_Row()
{
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  printf("\n");

  if (A->nb_r == 1){
    printf("The matrix is a row one.\n\n");
    A->is_row = 1;
  } else {
    printf("The matrix isn't a row one.\n\n");
    A->is_row = 0;
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
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  printf("\n");
  
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
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  A->arr = AllocationArr(A->nb_r, A->nb_c);
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
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  is_SquareM(A);

  if (A->is_sq){
    printf("\nThe matrix is a square one.\n\n");
  } else {
    printf("\nThe matrix isn't a square one.\n\n");
  }
}

void is_IdentityM(Matrix* A)
{
  is_SquareM(A);
  if (A->is_sq){
    int nb_zeros = Get_nbZeros(*A);
    int nb_one = 0;

    for (int i=0; i<A->nb_r; ++i){
      if (A->arr[i][i] == 1){
        nb_one++;
      } else {
        break;
      }
    }
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
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  A->arr = AllocationArr(A->nb_r, A->nb_c);
  printf("\n");
  enterValues(A);
  
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
