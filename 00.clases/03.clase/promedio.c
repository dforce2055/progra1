/*Ingresar desde el teclado 50 números enteros, calcular su promedio e
imprimir aquellos valores leidos, que sean mayores que el promedio */
/* comentarios */
#include <stdio.h>
#define SIZE 50

int main(){
  int i, suma = 0, numeros[SIZE];
  float promedio;
  for (i = 0; i < SIZE; i++) {
    printf("Ingrese número entero:");
    scanf("%d", &numeros[i]);
    suma = suma + numeros[i];
  }
  promedio = (float) suma / SIZE;
  printf("El promedio de los números ingresados es %.2f\n", promedio);
  for (i = 0; i < SIZE; i++) {
    if(numeros[i] > promedio) printf("%4d", numeros[i]);
  }
  printf("\n");

  return 0;
}
