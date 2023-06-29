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

void is_Column()
{
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  printf("\n");

  if (A->nb_c == 1){
    printf("The matrix is a column one.\n\n");
    A->is_column = 1;
  } else {
    printf("The matrix isn't a column one.\n\n");
    A->is_column = 0;
  }
}

void is_Null()
{
  Matrix* A = malloc(sizeof(Matrix));
  Size(A);
  A->arr = AllocationArr(A->nb_r, A->nb_c);
  printf("\n");
  enterValues(A);
  
  int nb_zeros = 0;
  for(int i=0; i<A->nb_r; ++i){
    for (int j=0; j<A->nb_c; ++j){
      if (A->arr[i][j] == 0){
        nb_zeros++;
      } else {
        break;
      }
    }
  }

  if (nb_zeros == (A->nb_r * A->nb_c)){
    A->is_null = 1;
    printf("\nThe matrix is null.\n\n");
  } else {
    A->is_null = 0;
    printf("\nThe matrix isn't null.\n\n");
  }
}
