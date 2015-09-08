/*2. Realizar una función que devuelva la suma de todos los elementos
de un vector de N elementos.*/
#include <stdio.h>
#pragma warning(disable:4996)
int sumaVector(int numeros[], int size);
int main(){
  int numeros[10] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 100};
  printf("La suma del vector es %d",sumaVector(numeros, 10));
  return 0;
}
int sumaVector(int numeros[], int size){
  int i, total;
  for(i = 0; i < size; i++){
    total += numeros[i];
  }
  return total;
}
