/* 6. Realizar una función que permita eliminar un valor de un arreglo. Se sabe que todos
los elementos válidos del vector se almacenan en forma consecutiva, y que los elementos no
utilizados se inicializan con -1. */
#include <stdio.h>
#define SIZE 10
void ordenarVector(int *vector);
void eliminarValor(int *vector, int eliminar);
void printVector(int *vector);
int main(){
  int vector[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("Vector en estado iniciar:\n");
  printVector(vector);
  eliminarValor(vector, 4);
  printf("Vector ordenado:\n");
  printVector(vector);

  return 0;
}
void ordenarVector(int *vector){
  int i, j, buffer;
  for(i = 0; i < SIZE -1; i++){
    for(j = i +1; j < SIZE; j++){
      if(vector[i] < vector[j]){
        buffer = vector[i];
        vector[i] = vector[j];
        vector[j] = buffer;
      }
    }
  }
}
void eliminarValor(int *vector, int eliminar){
  int i;
  ordenarVector(vector);
  for(i = 0; i < SIZE; i++){
    if(vector[i] == eliminar) vector[i] = -1;
  }
  ordenarVector(vector);
}

void printVector(int *vector){
  int i;
  for(i = 0; i < SIZE;i++){
    printf("%4d", vector[i]);
  }
  printf("\n");
}
