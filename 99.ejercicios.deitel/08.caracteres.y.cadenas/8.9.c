/* Escriba un programa que utilice la función strcmp para comparar dos cadenas
introducidas por el usuario. El programa debe establecer si la primera cadena es menor,
igual o mayor que la segunda cadena. */
#include <stdio.h>
#include <string.h>
int main(){
  char s1[] = "hola";
  char s2[] = "hola";
  int i;

  i = strcmp(s1, s2);
  if(i == 0) puts("Son iguales");
  if(i > 0) puts("s1 es mayor que s2");
  if(i < 0) puts("s2 es mayor que s1");

  return 0;
}
