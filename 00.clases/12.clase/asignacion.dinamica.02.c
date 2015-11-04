#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
  char *cad;
  cad = (char *)malloc(80);
  strcpy(cad, "Programación");
  puts(cad);
  free(cad);
  cad = NULL;

  return 0;
}
