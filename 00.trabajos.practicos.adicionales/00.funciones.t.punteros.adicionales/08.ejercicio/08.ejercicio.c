/* Dado un parámetro de tipo entero, devolver el resultado de calcular su factorial. Ejemplo:
fact(4) = 4*3*2*1 = 24. */
#include <stdio.h>
int factorial(int numero);
int main(){
  printf("Factorial de 4 = %d", factorial(7));
  return 0;
}
int factorial(int numero){
  int i, resultado = numero;
  for(i = numero - 1; i > 0; i--) resultado = resultado * i;
  return resultado;
}
