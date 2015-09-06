/* Codificar una función que devuelva la cantidad de palabras (separadas por uno o más
espacios) que tiene una frase. */
#include <stdio.h>
#include <string.h>
int cuentaPalabras(char *cadena);
int main(){
  char cadena[] = "Esto tiene   5 +       palabras";
  int i = cuentaPalabras(cadena);

  printf("La cadena \"%s\" \n tiene %d palabras",cadena, i);
  return 0;
}
int cuentaPalabras(char *cadena){
  int contador;
  for(contador = 0; *cadena != '\0'; cadena++)
    if(*cadena == ' '){
      while(*cadena == ' ') cadena++;
      contador++;
    }
  return contador+1;
}
