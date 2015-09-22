/* Escriba un programa que utilice la función strncmp para comparar dos cadenas introducidas
por el usuario. El programa debe introducir el número de caracteres a comparar. El programa
debe establecer si la primera cadena es menor, igual o mayor que la segunda cadena. */
#include <stdio.h>
#include <string.h>
int main(){
  char s1[100];
  char s2[100];
  int i;

  puts("Ingrese 1ra cadena: ");
  fgets(s1,100,stdin);
  puts("Ingrese 2da cadena: ");
  fgets(s2,100,stdin);

  i = strncmp(s1,s2, 5);
  if(i == 0) puts("Hasta el caracter 5 son iguales");
  if(i > 0) puts("s1 es mayor que s2");
  if(i < 0) puts("s2 es mayor que s1");

  return 0;
}
