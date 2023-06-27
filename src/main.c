#include <stdio.h>
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
  } while(!strcmp(token,"y"));

  return 0;
}
