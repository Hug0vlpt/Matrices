#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "functions.h"
#include "save.h"

int main (int argc, char *argv[])
{
  FILE* fsave = NULL;
  ArrM* Am = InitAm(); 
  int l;

  fsave = fopen("save_m.csv", "r");
  if (fsave != NULL) { pullAmf(Am); }
  
  do {
    display_options(Am); 
    
    printf("Do you want to go back to the menu ? (y/n): ");
    clearBuffer();
    l = getchar();
    //clear the screen
    printf("\e[1;1H\e[2J");
  } while(l == 'y');

  //write changes in the save file
  pushAmf(Am); 

  for (int i=0; i<Am->nb_mat; ++i) {
    free(Am->arr[i]);
  }
  free(Am);

  return 0;
}
