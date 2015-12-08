/* Separar las palabras de una cadena de caracteres, imprimiendo cada una en una línea de
pantalla.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void separarPalabras(char *cadena);

int main(){
  char frase[] = "El mundo esta hecho para los audaces, no para los cobardes.";

  separarPalabras(frase);
  return 0;
}
void separarPalabras(char *cadena){
  //Recibe una cadena con varias palabras
  //Separa las palabras con ' ' y las imprime por pantalla.
  char *pPalabra = NULL;
  pPalabra = strtok(cadena, " ");

  while(pPalabra != NULL){
    puts(pPalabra);
    pPalabra = strtok(NULL, " ");
  }
}
