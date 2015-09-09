/*
 1. ingresar una frase cualquiera. y segun la opcion modificar la frase.
  0 cambiarlo a mayuscula.
  1 cambiarlo a minuscula.
  2 Tipo oracion. La primera letra en Mayuscula lo que sigue en minuscula.
  3 Tipo titulo en todas las palabras la primera letra a mayuscula.
  4 Intercambiar, si esta en minuscula pasarlo a mayuscula y viceversa

Todavia no me puse a ver como puedo obtener la palabra mas larga de una frase, 
porque tambien habria que filtrar lo que es una palabra.
En la frase "Y todo fue como el dijo o no, ganaron 10 pesos?", 'o','y' y '10' no
son palabras. (en el caso que pida contar cuantas palabras hay) tambien habria 
que tener en cuenta si hay espacios dobles.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *modFrase(char *frase, int opcion);
int main(){
  char cadena[256] = "Hola";
  char *pCadena = modFrase(cadena, 0);
  //char *puntero = modFrase(cadena, 0);
  //for( ; *pCadena != '\0'; pCadena++)
  //  *pCadena = toupper(*pCadena);
  
  puts(cadena);
  puts(pCadena);
  
  return 0;
}
char *modFrase(char *frase, int opcion){
  char cadena[256];
  char *pFrase = frase, *pCadena = cadena;
  int i;
  for(i = 0 ; *pFrase != '\0'; pFrase++, i++)
    cadena[i] = toupper(*pFrase);
  cadena[i] = '\0';
  /*switch(opcion){
    case 0: 
      for( ; *pFrase != '\0'; pFrase++) 
        *pFrase = toupper(*pFrase);
      pFrase = frase;
      break;
  }*/
  //puts(cadena);
  return pCadena;
}