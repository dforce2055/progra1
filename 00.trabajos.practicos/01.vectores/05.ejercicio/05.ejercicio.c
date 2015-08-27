/*5. Realizar una función que permita determinar la cantidad de veces que se repite
un valor en un vector dado.*/
#include <stdio.h>
#define SIZE 10
int repeticiones(int *vector, int valor);
int main(){
  int vector[SIZE] = {1, 2, 2, 33, 3, 4, 1, 1, 10, 9};
  int valor = 33, repetido = 0;
  repetido = repeticiones(vector, valor);
  printf("El valor %d, se repite %d en el vector", valor, repetido);
  return 0;
}
int repeticiones(int *vector, int valor){
  int i, repeticiones = 0;
  for(i = 0; i < SIZE; i++){
    if(vector[i] == valor) repeticiones++;
  }
  return repeticiones;
}
