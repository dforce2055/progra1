/* 7. Realizar una función que determine si todos los elementos de dos vectores son iguales y
están en el mismo orden. */
#include <stdio.h>
#define SIZE 10
int vectoresIdenticos(int *vector1, int *vector2);
int main(){
  int a[SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
  int b[SIZE] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

  if(vectoresIdenticos(a, b)) printf("Los arreglos son identicos.\n");
  else printf("Los arreglos NO son identicos.\n");

  return 0;
}
int vectoresIdenticos(int *vector1, int *vector2){
  int i, resultado = 1;
  for(i = 0; i < SIZE; i++){
    if(vector1[i] != vector2[i]) resultado = 0;
  }
  return resultado;
}
