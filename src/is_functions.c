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
  A = newMatrix(0,0);
  enterValues(A);

  is_RowM(A);
  if (A->is_row){
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nis a row one.\n\n");
  } else {
    printf("The matrixn\n");
    display_Matrix(*A);
    printf("isn't a row one.\n\n");
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
  A = newMatrix(0,0);
  enterValues(A);
  
  is_ColumnM(A);

  if (A->is_column){
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nis a column one.\n\n");
  } else {
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nisn't a column one.\n\n");
  }
}

void is_NullM(Matrix* A)
{
  int e_zeros = enoughZeros(*A,0,0,A->nb_r,A->nb_c);

  if (e_zeros){
    A->is_null = 1;
  } else {
    A->is_null = 0;
  }
}

void is_Null()
{
  Matrix* A;
  A = newMatrix(0,0);
  enterValues(A);

  is_NullM(A);
  
  if (A->is_null){
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nis null.\n\n");
  } else {
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nisn't null.\n\n");
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
  enterValues(A);

  is_SquareM(A);

  if (A->is_sq){
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nis a square one.\n\n");
  } else {
    printf("The matrix\n\n");
    display_Matrix(*A);
    printf("\nisn't a square one.\n\n");
  }
}

void is_IdentityM(Matrix* A)
{
  if (A->is_sq < 0){
    is_SquareM(A);
  }
  if (A->is_sq) {
    Matrix* T = Get_transpose(*A);
    if (A->nb_r == 1) {
      if (A->arr[0][0] == 1) { A->is_id = 1; } else { A->is_id = 0; }
    } else {
      int e_zeros_lt = enoughZeros(*T,1,-2,A->nb_r,-1);
      int e_zeros_ut = enoughZeros(*A,1,-2,A->nb_r,-1);
      int nb_one = NbsameElemDiag(*A,1);

      if (e_zeros_lt && e_zeros_ut && nb_one == A->nb_r) {
        A->is_id = 1;
      } else {
        A->is_id = 0;
      }
    }
  } else {
    A->is_id = 0;
  }
}

void is_Identity()
{
  Matrix* A;
  A = newMatrix(0,0);

  is_SquareM(A);
  if (A->is_sq){
    enterValues(A);
  }
  is_IdentityM(A);

  if (A->is_sq){
    if (A->is_id){
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis an identity one.\n\n");      
    } else {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nisn't an identity one.\n\n"); 
    }
  } else {
      printf("The matrix can't be an identity one because it isn't a square one.\n\n");
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
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a diagonal one.\n\n");      
    } else {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nisn't a diagonal one.\n\n");      
    }
  } else {
      printf("The matrix can't be a diagonal one because it isn't a square one.\n\n");
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
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a scalar one.\n\n");      
    } else {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nisn't a scalar one.\n\n");      
    }
  } else {
      printf("The matrix can't be a scalar one because it isn't a square one.\n\n");
  }
}

void is_TriangularM(Matrix* A)
{
  if (A->is_sq < 0){
    is_SquareM(A);
  }
  if (A->is_sq) {
    Matrix* T = Get_transpose(*A);

    if (A->nb_r == 1) {
      if (A->arr[0][0] == 0) { A->is_str_up_tr = 1; A->is_str_low_tr = 1;} else { A->is_up_tr = 1; A->is_low_tr = 1; }
    } else {
      int e_zeros_str_ut = enoughZeros(*A,0,0,A->nb_r,-2);
      int e_zeros_str_l = enoughZeros(*T,0,0,A->nb_r,-2);
      int e_zeros_ut = enoughZeros(*A,1,-2,A->nb_r,-1);
      int e_zeros_lt = enoughZeros(*T,1,-2,A->nb_r,-1);
      
      if (e_zeros_str_ut) {
        A->is_str_up_tr = 1;
      } else {
        A->is_up_tr = 0;
      }
      if (e_zeros_str_l) {
        A->is_str_low_tr = 1;
      } else {
        A->is_str_low_tr = 0;
      }
      if (e_zeros_ut) {
        A->is_up_tr = 1;
      } else {
        A->is_up_tr = 0;
      }
      if (e_zeros_lt) {
        A->is_low_tr = 1;
      } else {
        A->is_low_tr = 0;
      }
    }
  } 
}

void is_Triangular()
{
  int str_up, str_l, up, low;
  Matrix* A;
  A = newMatrix(0,0);

  is_SquareM(A);
  if (A->is_sq){
    enterValues(A);
  }
  is_TriangularM(A);

  str_up = A->is_str_up_tr == 1;
  str_l = A->is_str_low_tr == 1;
  up = A->is_up_tr == 1;
  low = A->is_low_tr == 1;

  if (A->is_sq){
    if (str_up && str_l) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis null (both strictly upper triangular and strictly lower triangular).\n\n");      
    } else if (str_up) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a strictly upper triangular one.\n\n"); 
    } else if (str_l) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a strictly lower triangular one.\n\n");
    } else if (up && low) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a diagonal one (both upper triangular and lower triangular).\n\n"); 
    } else if (up) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis an upper triangular one.\n\n"); 
    } else if (low) {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a lower triangular one.\n\n"); 
    } else {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nisn't triangular.\n\n"); 
    }
  } else {
      printf("The matrix can't be an upper triangular one because it isn't a square one.\n\n");
  }
}

void is_SymmetricM(Matrix* A) {
  int equal;
  if (A->is_sq < 0){
    is_SquareM(A);
  }
  if (A->is_sq) {
    Matrix* T = Get_transpose(*A);
    equal = are_Equal(*A,*T);
    if (equal == 1) { A->is_sym = 1; } else { A->is_sym = 0; }
  } else {
    A->is_sym = 0;
  }
}

void is_Symmetric() 
{
  Matrix* A;
  A = newMatrix(0,0);

  is_SquareM(A);
  if (A->is_sq){
    enterValues(A);
  }
  is_SymmetricM(A);

  if (A->is_sq){
    if (A->is_sym){
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nis a symmetric one.\n\n");      
    } else {
      printf("The matrix\n\n");
      display_Matrix(*A);
      printf("\nisn't a symmetric one.\n\n"); 
    }
  } else {
      printf("The matrix can't be a symmetric one because it isn't a square one.\n\n");
  }
}



