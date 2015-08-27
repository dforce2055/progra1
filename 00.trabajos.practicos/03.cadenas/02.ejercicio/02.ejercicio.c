/* 2. Hacer una función que determine si una secuencia de caracteres es capicúa. */
#include <stdio.h>
int capicua(char * cadena);
int main(){
  char cadena[] = "asa";
  if(capicua(cadena)) printf("La cadena \"%s\" es capicua", cadena);
  else printf("La cadena \"%s\" no es capicua", cadena);
  return 0;
}
int capicua(char * cadena){
  int i, fin, resultado = 1;
  for(fin = 0; cadena[fin]; fin++);
  //fin--;
  for(i = 0, fin--; i < fin; i++, fin--){
    if(cadena[i] != cadena[fin]) resultado = 0;
  }

  return resultado;
}
