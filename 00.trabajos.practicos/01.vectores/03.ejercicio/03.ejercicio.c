/*3. Realizar una función que devuelva el mínimo elemento de un vector.*/
#include <stdio.h>
#pragma warning(disable:4996)
int minimo(int vector[], int size);
int main(){
  int numeros[10] = {-2, 1, 10, 2, 200, 100, -133, 0, 9, 4};
  printf("El menor número del vector es %d", minimo(numeros, 10));
  return 0;
}

int minimo(int vector[], int size){
  int i, minimo = vector[0];
  for(i = 0; i < size; i++){
    if(vector[i] < minimo) minimo = vector[i];
  }
  return minimo;
}
