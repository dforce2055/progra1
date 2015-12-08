/*Codificar una función que devuelva la cantidad de palabras (separadas por uno o más
espacios) que tiene una frase.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int cantPalabras(char *cadena);

int main(){
  char frase[] = "    Este tiene    espacios al   principio y al   final";

  printf("Cantidad de palabras: %d\n", cantPalabras(frase));
  return 0;
}
int cantPalabras(char *cadena){
  //Recibe una cadena, retorna la cantidad de palabras separadas por 1 espacio o más
  char *pPalabra = NULL;
  int cantPalabras = 0;

  pPalabra = strtok(cadena, " ");
  while(pPalabra != NULL){
    cantPalabras++;
    pPalabra = strtok(NULL, " ");
  }

  return cantPalabras;
}
