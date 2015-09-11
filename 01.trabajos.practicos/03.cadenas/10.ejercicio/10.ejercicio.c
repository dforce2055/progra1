/* 10. Escribir una función strright(<cadena>,<n>) que permita obtener una subcadena
de caracteres con los últimos <n> caracteres de la cadena pasada como parámetro. La
función no hará nada si el parámetro <n> es menor que cero o mayor que la longitud
de la cadena. */
/* la resolución es correcta, siempre y cuando se pase como parametro la cadena
 al pasar la cadena se puede declarar en al función localmente un puntero y devolver
 ese puntero. */
#include <stdio.h>
#include <string.h>
char *strright(char *cadena, int n);
int main(){
  char cadena[] = "Hola mundo!";
  char *subCadena;

  subCadena = strright(cadena, 7);
  puts(subCadena);

  return 0;
}
char *strright(char *cadena, int n){
  char *pCadena = cadena + strlen(cadena);//puntero al final de la cadena
  char *pError = "No se admiten numeros menores a 0 o mayores a cadena";
  if(n > strlen(cadena) || n < 0) return pError;
  else{
    for( ; n > 0; n--, pCadena--)
      ;
    return pCadena;
  }
}
