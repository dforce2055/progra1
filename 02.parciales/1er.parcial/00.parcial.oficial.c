/* Ingresar a través del teclado una frase cualquiera, la que podrá tener hasta 
un máximo de 100 palabras. Luego se solicita desarrollar un programa que 
realice las siguientes tareas.

  1. Mostrar la frase por pantalla, paro encerrado entre paréntesis aquellas 
  palabras donde la cantidad de vocales supere el 50% del total de los 
  caracteres de la misma. 

  2. Imprimir por pantalla las palabras que cumplan con la condición indicada 
  en el punto anterior, mostrándolas en orden alfabético y sin paréntesis.

Nota:
  # Se considera palabra a un conjunto de uno o más caracteres seguidos de uno o 
    más espacios al principio o al final.
    
  # Las vocales con tilde no se consideran.
*/
#pragma warning(disable:4996)
#pragma warning(disable:638)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int leerCadena(char *cadena, int n);
int main(){
  char frase[1000];

  
  if(leerCadena(frase,1000)){
    puts("Usted dijo:");
    puts(frase);
  }else puts("error al leer la cadena");

  return 0;
}
int leerCadena(char *cadena, int n) {
    int i, c;

    c = getchar();
    if (c == EOF) {
        cadena[0] = '\0';
        return 0;
    }

    if (c == '\n')
        i = 0;
    else {
        cadena[0] = c;
        i = 1;
    }

    for (; i < n-1 && (c=getchar())!=EOF && c!='\n'; i++)
       cadena[i] = c;

    cadena[i] = '\0';

    if (c != '\n' && c != EOF)
        while ((c = getchar()) != '\n' && c != EOF);

    return 1;
}