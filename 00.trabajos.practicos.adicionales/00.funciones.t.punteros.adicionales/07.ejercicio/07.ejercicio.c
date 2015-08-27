/* Dado un parámetro de tipo entero verificar si el número es par o impar, devolviendo 1
(VERDADERO) o 0 (FALSO). */
#include <stdio.h>
int esPar(int numero);
int main(){
  int numero;
  printf("Introduzca un número, le dire si es par: ");
  scanf("%d", &numero);
  if(esPar(numero)) printf("El número %d es par", numero);
  else printf("El número %d es impar", numero);
  return 0;
}
int esPar(int numero){
  return (numero % 2 == 0)?1:0;
}
