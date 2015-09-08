/* Dados dos parámetros de tipo entero, calcular el valor de la multiplicación de los mismos
usando sólo sumas. */
#include <stdio.h>
int multiplicar(int numero, int multiplo);
int main(){
  printf("2 x 2 = %d", multiplicar(2,2));
  return 0;
}
int multiplicar(int numero, int multiplo){
  int i, resultado = 0;
  for(i = multiplo; i > 0; i--) resultado = numero * multiplo;
  return resultado;
}
