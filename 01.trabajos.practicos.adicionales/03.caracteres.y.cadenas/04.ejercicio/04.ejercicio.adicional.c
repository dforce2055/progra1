/*Escribir una función strpos(c,s) que devuelva la posición del carácter c dentro de la cadena
s. Si el carácter no se encuentra deberá devolverse -1.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int strpos(char c, char *cadena);
int  main(){
  char cadena[] = "Un mundo de locos";

  printf("Se encontro en la posición %d", strpos('o', cadena));
  return 0;
}
int strpos(char c, char *cadena){
  //Recibe un caracter y una cadena
  //Busca en la cadena el caractere, retorna la posición de la primer coincidencia
  int pos = -1;
  int i;

  for(i = 0; cadena[i]; i++){
    if(cadena[i] == c){
      pos = i;
      break;//finaliza el ciclo al encontrar la 1er coincidencia
    }
  }

  return pos;
}
