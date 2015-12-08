/* Hacer una función que permita reemplazar todas las secuencias de más de un espacio por
uno solo en una cadena de caracteres cualquiera.*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void espaciosDeMas(char *cadena);
void eliminarEsp(char *cadena);

int main(){
  char cadena[] = "     Esto  tiene  varios    espacios       de más     ";

  espaciosDeMas(cadena);
  puts(cadena);

  return 0;
}
void espaciosDeMas(char *cadena){
  //Recibe una cadena
  //Determina si tiene espacios uno al lado del otro y los elimina
  //Pasa a la funcion eliminarEsp la cadena, para eliminar los espacios de más al principio
  //y al final
  char aux[256];
  char *pAux = aux;
  char *pCadena = cadena;

  while(*pCadena){
    if(isspace(*pCadena)){
      while(isspace(*pCadena)){
        pCadena++;
      }
      *pAux = ' ';
      pAux++;
      *pAux = *pCadena;
    }else{
      *pAux = *pCadena;
      pAux++;
      pCadena++;
      }
  }
  strcpy(cadena, aux);
  eliminarEsp(cadena);
}
void eliminarEsp(char *cadena){
  //Recibe una cadena con espacios al principio y al final
  //Elimina todos los espacios al principio y al final
  char aux[256];
  char *pCadena = cadena;

  while(isspace(*pCadena))//corro el puntero hacia la der. hasta no encontrar espacios al principio
    pCadena++;

  strcpy(aux, pCadena);
  pCadena = aux + strlen(aux)-1;

  while(isspace(*pCadena))//Corro el puntero hacia la izq. hasta no encontrar espacios al final
    pCadena--;

  pCadena++;//dejo puntero apuntando al ultimo espacio
  *pCadena = '\0';
  strcpy(cadena, aux);
}
