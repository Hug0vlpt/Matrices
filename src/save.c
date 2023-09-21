#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "save.h"
#include "struct.h"
#include "functions.h"
#include "user.h"

void AllocationArrM(ArrM* Am, int rea) 
{
  if (!rea) {
    Am->arr = malloc(Am->nb_mat * sizeof(Matrix*));
  } else {
    Am->arr = realloc(Am->arr, Am->nb_mat * sizeof(Matrix));
  }
}

ArrM* InitAm() {
  ArrM* Am = malloc(sizeof(ArrM));
  Am->nb_mat = 0;
  AllocationArrM(Am,0);
  return Am;
}

void SaveMatrix(ArrM* Am, Matrix* A, char name[2]) 
{
  Am->nb_mat++;
  AllocationArrM(Am,1);
  strcpy(A->name, name);
  A->is_saved = 1;
  Am->arr[Am->nb_mat-1] = A;
}

void stockInfoM(Matrix* A, char* info, int nb_l, int nb_c, int nb_r) 
{
  if (nb_l == 0 && nb_c==0) {
    strcpy(A->name, info);
  } else if (nb_l == 1) {
    switch (nb_c) {
      case 0: A->nb_r = atoi(info); break;
      case 1: A->nb_c = atoi(info); break;
      case 2: A->trace = atoi(info); break;
      case 3: A->rk = atoi(info); break;
      case 4: A->is_saved = atoi(info); break;
      case 5: A->is_row = atoi(info); break;
      case 6: A->is_column = atoi(info); break;
      case 7: A->is_null = atoi(info); break;
      case 8: A->is_sq = atoi(info); break;
      case 9: A->is_id = atoi(info); break;
      case 10: A->is_diag = atoi(info); break;
      case 11: A->is_scal = atoi(info); break;
      case 12: A->is_up_tr = atoi(info); break;
      case 13: A->is_str_up_tr = atoi(info); break;
      case 14: A->is_low_tr = atoi(info); break;
      case 15: A->is_str_low_tr = atoi(info); break;
      case 16: A->is_sym = atoi(info); break;
      case 17: A->is_asym = atoi(info); break;
      case 18: A->is_inv = atoi(info); break;
    }
  } else if (nb_l >= 2 && nb_l <= nb_r+1) {
    A->arr[nb_l-2][nb_c] = atoi(info);
  }
}

void pullAmf(ArrM* Am)
{
  Matrix* A;
  FILE* fsave = NULL;
  char line[100];
  char* info_m = malloc(100 * sizeof(char));
  int nbLine, nbCol; 
  int nb_saved_m = 0;
  int nb_row = 0;
  int nb_column = 0; 
 
  nbLine = nbCol = 0;
  fsave = fopen("save_m.csv", "r");

  if (fsave == NULL) {
    printf("Error. You haven't any saved matrices.\n");
  } else {
    while (fgets(line,100,fsave) !=NULL) {
      if (nbLine == 0) { 
        A = malloc(sizeof(Matrix)); 
      }
      if (nbLine == 2) { A->arr = AllocationArr(nb_row,nb_column); } 
      info_m = strtok(line,";");
      if (nbLine == 1) { nb_row = atoi(info_m); }
      stockInfoM(A, info_m, nbLine, nbCol, nb_row);
      while (info_m != NULL) {
        nbCol++;
        if (nbLine == 0 && nbCol == 0) { nb_column = atoi(info_m); }
        info_m = strtok(NULL,";");  
        if (info_m !=NULL) {
          stockInfoM(A, info_m, nbLine, nbCol, nb_row);
        }
      }
      nbCol = 0;
      nbLine++;
      if (nbLine == nb_row+2) {
        nb_saved_m++;
        Am->nb_mat = nb_saved_m;
        AllocationArrM(Am, 1);
        Am->arr[nb_saved_m-1] = A; 
        nbLine = 0;
      }
    }
    fclose(fsave);
  }
}

void pushAmf(ArrM* Am)
{
  FILE* fsave = NULL;
  FILE* temp = NULL;

  fsave = fopen("save_m.csv", "r");
  temp = fopen("temp.csv", "a+");

  if (temp == NULL) {
    printf("Error when opening the temporary file.\n");
  } else {
    for (int i=0; i<Am->nb_mat; ++i) {
      SaveMFile(temp, *Am->arr[i]);
    }
    fclose(temp);
    if (fsave != NULL) { remove("save_m.csv"); }
    rename("temp.csv", "save_m.csv");
  }
}

void SaveMFile(FILE* fsave, Matrix A)
{
  fprintf(fsave, "%s;",A.name);
  fprintf(fsave, "\n");

  fprintf(fsave, "%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d", A.nb_r,A.nb_c,A.trace,A.rk,A.is_saved,A.is_row,A.is_column,A.is_null,A.is_sq,A.is_id,A.is_diag,A.is_scal,A.is_up_tr,A.is_str_up_tr,A.is_low_tr,A.is_str_low_tr,A.is_sym,A.is_asym,A.is_inv);
  fprintf(fsave, "\n");

  for (int i=0; i<A.nb_r; ++i) {
    for (int j=0; j<A.nb_c; ++j) {
      fprintf(fsave, "%d", A.arr[i][j]);
      if (j!=A.nb_c-1) { fprintf(fsave, ";"); }      }
    fprintf(fsave, "\n");
  }
}

int findIndexAm(ArrM Am, char nm[2]) {
  for (int i=0; i<Am.nb_mat; ++i) {
    if (!strcmp(Am.arr[i]->name, nm)) {
      return i;
    }
  }
  return -1;
}

