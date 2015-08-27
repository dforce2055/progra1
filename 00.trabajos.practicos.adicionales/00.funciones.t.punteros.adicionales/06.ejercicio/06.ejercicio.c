/* Dados dos parámetros A y B de tipo entero, devolver A B utilizando la función realizada en el
ejercicio anterior. */
/* potencia de un número es = a multiplicar base x resultado tantas veces como dice el exponente
    2 ^ 3 =>
              2 * 1  =  2;
              2 * 2  =  4;
              2 * 4  = 16;
              2 * 16 = 32;

*/

#include <stdio.h>
#include <math.h>
int potencia(int base, int exponente);
int main(){
  printf("%d", potencia(2,4));
  return 0;
}
int potencia(int base, int exponente){
  int multiplicar(int numero, int multiplo);
  int i, resultado = 1;
  for( ; exponente > 0; exponente--) resultado = multiplicar(base, resultado);

  return resultado;
}
int multiplicar(int numero, int multiplo){
  int i, resultado = 0;
  for(i = multiplo; i > 0; i--) resultado = numero * multiplo;
  return resultado;
}
