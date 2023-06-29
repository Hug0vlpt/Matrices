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
