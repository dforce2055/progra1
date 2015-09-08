/* Realizar una función para determinar si un arreglo de números enteros es capicúa. La
cantidad de elementos está declarada mediante una directiva #define. */
#include <stdio.h>
#define SIZE 5
int capicua(int *vector);
int main(){
  int arreglo[SIZE] = {1,1,0,1,1};
  if(capicua(arreglo)) printf("El vector es Capicua!");
  else printf("No es capicua.");
  return 0;
}
int capicua(int *vector){
  int i, end, resultado = 1;
  for(i = 0, end = SIZE -1; i < SIZE; i++, end--){
    if(vector[i] != vector[end]) resultado = 0;
  }
  return resultado;
}
