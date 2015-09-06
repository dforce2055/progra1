/* Escribir una función strpos(c,s) que devuelva la posición del carácter c dentro de la cadena
s. Si el carácter no se encuentra deberá devolverse -1. */
#include <stdio.h>
#include <string.h>
int strpos(char c, char *cadena);
int main(){
  char cadena[] = "Diegote";
  char caracter = 'D';
  int pos = strpos(caracter, cadena);

  if(pos != -1) printf("El caracter \'%c\' se encontro en la posicion %d", caracter, pos);
  else puts("No se encontro el caracter");
  return 0;
}
int strpos(char c, char *cadena){
  int i, posicion = -1;
  for(i = 0;cadena[i]; i++) if(cadena[i] == c) posicion = i;

  return posicion +1;
}
