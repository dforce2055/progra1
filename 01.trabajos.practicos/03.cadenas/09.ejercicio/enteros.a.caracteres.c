/*
   nombre: wiki20.c
   fecha: 21/10/2009
   autor: carlos miguel gascon
   descripción:  programa que visualiza los caracteres alfabeticos de la tabla 
		 ascii y su posicion decimal.
*/

#include <stdio.h>
int main(){
  int contador;
  
  puts("");
  for(contador = 65;contador <= 90;contador++) printf("%d: %c\t", contador, contador);
  for(contador = 97;contador <=122;contador++) printf("%d: %c\t", contador, contador);
  puts("");
  
  return 0;
}