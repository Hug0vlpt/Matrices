#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

int main (int argc, char *argv[])
{
  char token[2];
  
  do {
    display_options(); 
    printf("Do you want to do something else ? (y/n): ");
    clearBuffer();
    fgets(token, 2, stdin);
    printf("\e[1;1H\e[2J");
  } while(!strcmp(token,"y"));

  return 0;
}
