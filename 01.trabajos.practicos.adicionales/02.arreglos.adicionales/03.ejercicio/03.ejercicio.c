/* Escribir una función para invertir un arreglo. */
#include <stdio.h>
#define SIZE 10
void invertirArreglo(int *arreglo);
void mostrarArreglo(int *arreglo);
int main(){
  int arreglo[SIZE] = {1,2,3,4,5,6,7,8,9,10};
  mostrarArreglo(arreglo);
  invertirArreglo(arreglo);
  mostrarArreglo(arreglo);

  return 0;
}

void invertirArreglo(int *arreglo){
  int i, end, buffer;
  for(i = 0, end = SIZE - 1; i < SIZE / 2; i++, end--) {
    buffer = arreglo[i];
    arreglo[i] = arreglo[end];
    arreglo[end] = buffer;
  }
}
void mostrarArreglo(int *arreglo){
  int i;
  for(i = 0; i < SIZE; i++) printf("%4d", arreglo[i]);
  printf("\n");
}
