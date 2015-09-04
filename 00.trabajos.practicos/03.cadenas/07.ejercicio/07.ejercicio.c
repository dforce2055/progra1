/* 7. Hacer una función que permita insertar una sub-cadena en una cadena a 
partir de una posición dada. */
/* tratar de rehacerlo utilizando metodo de corrimientos */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char *insertSubCadena(char *destino, char *origen, int posicion);
int main(){
  char cadena[100] = "hola";
  char sub[] = " mundo";
  char *pCadena = insertSubCadena(cadena, sub, 31);
  
  if(pCadena) puts(pCadena);
  else puts("error, la posicion excede el limite del arreglo");

  return 0;
}
char *insertSubCadena(char *destino, char *origen, int posicion){
  char *pDestino = destino;
  if((int)strlen(destino) >= posicion) {
    pDestino = pDestino + posicion;
    strcpy(pDestino, origen);
  }else destino = '\0';
  return destino;
}