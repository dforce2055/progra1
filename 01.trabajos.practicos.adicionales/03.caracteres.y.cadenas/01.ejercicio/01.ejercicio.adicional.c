/*Desarrollar una función para eliminar los espacios en blanco ubicados al principio y al final de
una cadena de caracteres. Los espacios intermedios no deben alterarse.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void eliminarEsp(char *cadena);

int main(){
  char cadena[] = "    Este tiene espacios al principio y al final ";

  eliminarEsp(cadena);
  puts(cadena);

  return 0;
}
void eliminarEsp(char *cadena){
  //Recibe una cadena con espacios al principio y al final
  //Elimina todos los espacios al principio y al final
  char aux[256];
  char *pCadena = cadena;}

  while(isspace(*pCadena))//corro el puntero hacia la der. hasta no encontrar espacios al principio
    pCadena++;

  strcpy(aux, pCadena);
  pCadena = aux + strlen(aux)-1;

  while(isspace(*pCadena))//Corro el puntero hacia la izq. hasta no encontrar espacios al final
    pCadena--;

  pCadena++;//dejo puntero apuntando al ultimo espacio
  *pCadena = '\0';
  strcpy(cadena, aux);
}
