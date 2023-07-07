#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main (int argc, char *argv[])
{
  char token[2];
  
  do {
    display_options(); 
    printf("Do you want to go back to the menu ? (y/n): ");
    clearBuffer();
    fgets(token, 2, stdin);
    //clear the screen
    printf("\e[1;1H\e[2J");
  } while(!strcmp(token,"y"));

  return 0;
}
