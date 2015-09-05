/* 10. Escribir una función strright(<cadena>,<n>) que permita obtener una subcadena
de caracteres con los últimos <n> caracteres de la cadena pasada como parámetro. La
función no hará nada si el parámetro <n> es menor que cero o mayor que la longitud
de la cadena. */
#include <stdio.h>
#include <string.h>
char *strright(char *cadena, int n);
int main(){
  char cadena[] = "Hola mundo!";
  char *subCadena;

  subCadena = strright(cadena, -2);
  puts(subCadena);

  return 0;
}
char *strright(char *cadena, int n){
  char *pCadena = cadena + strlen(cadena);//puntero al final de la cadena
  char *pError = "No se admiten numeros menores a 0";
  if(n > strlen(cadena) || n < 0) return pError;
  else{
    for( ; n > 0; n--, pCadena--)
      ;
    return pCadena;
  }
}
