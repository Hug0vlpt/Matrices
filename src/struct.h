#ifndef __STRUCT_H_
#define __STRUCT_H_

typedef struct {
  //the name of the matrix when saved
  char name[2];
  //the array that contains the elements of the Matrix
  int** arr;
  //number of rows
  int nb_r; 
  //number of columns
  int nb_c;
  //value of the trace of the matrix
  int trace;
  //value of the rank
  int rk;
  //is the matrix saved?
  int is_saved;
  //is the matrix a row one?
  int is_row;
  //is the matrix a column one?
  int is_column;
  //is the matrix a null one?
  int is_null;
  //is the matrix a square?
  int is_sq;
  //is the matrix an identity one?
  int is_id;
  //is the matrix a diagonal one?
  int is_diag;
  //is the matrix a scalar one?
  int is_scal;
  //is the matrix an upper triangle one?
  int is_up_tr;
  //is the matrix a strictly upper triangle one?
  int is_str_up_tr;
  //is rhe matrix a lower triangle one?
  int is_low_tr;
  //is the matrix a strictly lower triangle one?
  int is_str_low_tr;
  //is the matrix a symmetric one?
  int is_sym;
  //is the matrix a antisymmetrical one?
  int is_asym;
  //is the matrix an invertible one? 
  int is_inv;
} Matrix;

typedef struct {
  int nb_mat;
  Matrix** arr;
} ArrM;

#endif
