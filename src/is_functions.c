#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "user.h"
#include "functions.h"
#include "save.h"

void is_RowM(Matrix* A)
{
  if (A->nb_r == 1){
    A->is_row = 1;
  } else {
    A->is_row = 0;
  }
}

void is_Row(ArrM* Am)
{
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 0, size_check, "D");

  is_RowM(A);

  printf("\nThe matrix\n\n");
  display_Matrix(*A);
  if (A->is_row){
    printf("\nis a row one.\n\n");
  } else {
    printf("\nisn't a row one.\n\n");
  }

  if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
}

void is_ColumnM(Matrix* A)
{
  if (A->nb_c == 1){
    A->is_column = 1;
  } else {
    A->is_column = 0;
  }
}

void is_Column(ArrM* Am)
{  
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 0, size_check, "D");

  is_ColumnM(A);

  printf("\nThe matrix\n\n");
  display_Matrix(*A);
  if (A->is_column){
    printf("\nis a column one.\n\n");
  } else {
    printf("\nisn't a column one.\n\n");
  }
  
  if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
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

void is_Null(ArrM* Am)
{ 
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 0, size_check, "D");

  is_NullM(A);
  
  printf("\nThe matrix\n\n");
  display_Matrix(*A);
  if (A->is_null){
    printf("\nis null.\n\n");
  } else {
    printf("\nisn't null.\n\n");
  }
  if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
}

void is_SquareM(Matrix* A)
{
  if (A->nb_r == A->nb_c){
    A->is_sq = 1;
  } else {
    A->is_sq = 0;
  }
}

void is_Square(ArrM* Am)
{ 
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 0, size_check, "D");

  is_SquareM(A);

  printf("\nThe matrix\n\n");
  display_Matrix(*A);
  if (A->is_sq){
    printf("\nis a square one.\n\n");
  } else {
    printf("\nisn't a square one.\n\n");
  }
  if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
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

void is_Identity(ArrM* Am)
{ 
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_IdentityM(A);

  if (A->is_sq){
    printf("The matrix\n\n");
    display_Matrix(*A);
    if (A->is_id){
      printf("\nis an identity one.\n\n");      
    } else {
      printf("\nisn't an identity one.\n\n"); 
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }

  } else {
      printf("\nThe matrix can't be an identity one because it isn't a square one.\n\n");
  }
}

void is_DiagonalM(Matrix* A)
{
  if (A->is_sq < 0){
    is_SquareM(A);
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

void is_Diagonal(ArrM* Am)
{
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_DiagonalM(A);

  if (A->is_sq){
    printf("\nThe matrix\n\n");
    display_Matrix(*A);
    if (A->is_diag){
      printf("\nis a diagonal one.\n\n");      
    } else {
      printf("\nisn't a diagonal one.\n\n");      
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }

  } else {
      printf("\nThe matrix can't be diagonal because it isn't a square one.\n\n");
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

void is_Scalar(ArrM* Am)
{
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_ScalarM(A);
  
  if (A->is_sq){
    printf("\nThe matrix\n\n");
    display_Matrix(*A);
    if (A->is_scal){
      printf("\nis a scalar one.\n\n");      
    } else {
      printf("\nisn't a scalar one.\n\n");      
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
  } else {
      printf("\nThe matrix can't be scalar because it isn't a square one.\n\n");
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

void is_Triangular(ArrM* Am)
{
  int str_up, str_l, up, low;

  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_TriangularM(A);

  str_up = A->is_str_up_tr == 1;
  str_l = A->is_str_low_tr == 1;
  up = A->is_up_tr == 1;
  low = A->is_low_tr == 1;

  if (A->is_sq){
    printf("The matrix\n\n");
    display_Matrix(*A);
    if (str_up && str_l) {
      printf("\nis null (both strictly upper triangular and strictly lower triangular).\n\n");      
    } else if (str_up) {
      printf("\nis a strictly upper triangular one.\n\n"); 
    } else if (str_l) {
      printf("\nis a strictly lower triangular one.\n\n");
    } else if (up && low) {
      printf("\nis a diagonal one (both upper triangular and lower triangular).\n\n"); 
    } else if (up) {
      printf("\nis an upper triangular one.\n\n"); 
    } else if (low) {
      printf("\nis a lower triangular one.\n\n"); 
    } else {
      printf("\nisn't triangular.\n\n"); 
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
  } else {
      printf("\nThe matrix can't be triangular because it isn't a square one.\n\n");
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

void is_Symmetric(ArrM* Am) 
{
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_SymmetricM(A);

  if (A->is_sq){
    printf("The matrix\n\n");
    display_Matrix(*A);
    if (A->is_sym){
      printf("\nis a symmetric one.\n\n");      
    } else {
      printf("\nisn't a symmetric one.\n\n"); 
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }

  } else {
      printf("\nThe matrix can't be symmetric because it isn't a square one.\n\n");
  }
}

void is_AntiSymmetricM(Matrix* A)
{
  int equal;
  if (A->is_sq < 0){
    is_SquareM(A);
  }
  if (A->is_sq) {
    Matrix* T = Get_transpose(*A);
    Matrix* B = Get_productScalar(*A,-1);
    equal = are_Equal(*B,*T);
    if (equal == 1) { A->is_asym = 1; } else { A->is_asym = 0; }
  } else {
    A->is_asym = 0;
  }
}

void is_AntiSymmetric(ArrM* Am)
{
  Matrix* A;
  int size_check[3] = {0,0,0};

  A = chooseNSmat(*Am, 1, size_check, "D");

  is_AntiSymmetricM(A);

  if (A->is_sq){
    printf("The matrix\n\n");
    display_Matrix(*A);
    if (A->is_asym){
      printf("\nis an antisymmetric one.\n\n");      
    } else {
      printf("\nisn't an antisymmetric one.\n\n"); 
    }
    if (!A->is_saved) { inputSaveM(Am,A,"matrix"); }
  } else {
      printf("\nThe matrix can't be antisymmetric because it isn't a square one.\n\n");
  }
}

