/* 1. Hacer una función que permita invertir una secuencia de caracteres.
  Para invertir un arreglo es necesario saber el largo.
  Invertir los caracteres hasta la mitad de ese largo.
*/
#include <stdio.h>
void invertirCadena(char *cadena);
int main(){
  char nombre[] = "Diego Perez";
  printf("%s\n", nombre);
  invertirCadena(nombre);
  printf("%s\n", nombre);
  return 0;
}
void invertirCadena(char *cadena){
  int i, fin, size; //size = sizeof(cadena) / sizeof(char); cuenta solo hasta encontrar el 1er espacio
  char c;
  for(fin = 0; cadena[fin]; fin++) size = fin;
  fin--;

  for(i = 0; i <= size / 2; i++, fin--){
    c = cadena[i];
    cadena[i] = cadena[fin];
    cadena[fin] = c;
  }
}
