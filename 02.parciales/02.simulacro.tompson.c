/* Escribir un programa que lea una cadena de numeros enteros cualquiera y lo convierta a un
número entero. No utilice ninguna función de biblioteca para la conversión, desarrolle la
estrategia desde cero.
Imprimir por pantalla la cadena obtenida. Tener en cuenta que el numero puede ser
negativo. No confundir convertir a cadena con convertir a palabras. */
/* Números positivos y negativos desde -1000000000 hasta +1000000000*/
#include <stdio.h>
#include <string.h>
int cadenaAEntero(char *cadena);
int main(){
  char cadena[] = "-999999";
  int numero = cadenaAEntero(cadena);

  printf("%d", numero);

  return 0;
}
int cadenaAEntero(char *cadena){
  //Calcula la cantidad de digitos que tiene la cadena y los convierte a numero entero
  int largo = strlen(cadena);
  int numero = 0, i;
  char *pCadena = cadena + largo -1;

  for(i = 1; largo > 1; largo--){
    numero = numero + (*pCadena - 48) * i;//el valor de*pCadena -48 convierte el ascii a entero
    i = i * 10;                           //i representa la unidad 1 = u, 10 = d, 100 = c, 1000 = uDM
    pCadena--;
  }
  if(*pCadena == '-') numero = numero * (-1);//si el primer caracter es "-" multiplico numero -1 para hacerlo negativo
  else numero = numero + (*pCadena - 48) * i;//caso contrario agrego a numero el primer digito

  return numero;
}
