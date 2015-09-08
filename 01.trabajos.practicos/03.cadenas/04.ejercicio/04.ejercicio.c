/* 4. Hacer una función que permita reemplazar en una secuencia de caracteres todos los guiones
(-) por el carácter numeral (#) */
#include <stdio.h>
void reemplazar(char *cadena, char *buscado, char *c);
int main(){
  char cadena[] = "sos-re-bigote";
  reemplazar(cadena, "-", "#");
  printf("Cadena modificada: \"%s\"", cadena);
  return 0;
}
void reemplazar(char *cadena, char *buscado, char *c){
  int i;
  for(i = 0;cadena[i]; i++){
    if(cadena[i] == *buscado) cadena[i] = *c;
  }
}
