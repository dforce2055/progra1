/* Leer por teclado una serie de números enteros -de no más de 50 elementos- y guardarlos en
un arreglo, finalizando la lectura al ingresar un valor -1 o cuando se hayan ingresado los 50
valores. Luego escribir una función para calcular la suma de los elementos del vector. Los
parámetros que recibe la función son el arreglo y la cantidad de elementos que contiene. */
#include <stdio.h>
int sumaVector(int *vector, int size);
int main(){
  int arreglo[50] = {0};
  int numero, i = 0;

  printf("Ingrese numeros enteros (-1 fin): ");
  scanf("%d", &numero);
  while(numero != -1 && i < 50){
    arreglo[i] = numero;
    printf("Ingrese numeros enteros: ");
    scanf("%d", &numero);
    i++;
  }
  printf("La suma del vector es %d", sumaVector(arreglo, 50));

  return 0;
}

int sumaVector(int *vector, int size){
  int i, suma = 0;
  for(i = 0; i < size - 1; i++) suma += vector[i];
  return suma;
}
