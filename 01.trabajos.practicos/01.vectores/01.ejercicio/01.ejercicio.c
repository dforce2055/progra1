/* Realizar una función que imprima los valores de un vector de N
posiciones, desde la posición máxima a la posición mínima.
*/
#include <stdio.h>
#pragma warning(disable:4996)
void imprimeVector(int vector[], int size);
int main(){
  int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  imprimeVector(numeros, 10);
  return 0;
}

void imprimeVector(int vector[], int size){
  int i;
  for(i = size - 1; i >= 0; i--){
    printf("%d\n", vector[i]);
  }
}
