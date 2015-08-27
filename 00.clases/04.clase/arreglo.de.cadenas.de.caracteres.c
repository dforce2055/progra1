/* Arreglo de cadenas de caracteres */
#include <stdio.h>
int main(){
  char datos[2][40];
  printf("Nombre? ");
  scanf("%s", datos[0]);
  printf("Apellido? ");
  scanf("%s", datos[1]);
  printf("Bienvenido %s %s\n", datos[0], datos[1]);

  return 0;
}
