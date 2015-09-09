/* 7. Hacer una función que permita insertar una sub-cadena en una cadena a
partir de una posición dada. */
/* tratar de rehacerlo utilizando metodo de corrimientos */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int insertSubCadena(char *destino, char *origen, int posicion);
int main(){
  char cadena[100] = "hola";
  char sub[] = " mundo";

  if(insertSubCadena(cadena, sub, 2+2)) puts(cadena);
  else puts("error, la posicion excede el limite del arreglo");

  return 0;
}
int insertSubCadena(char *destino, char *origen, int posicion){
  char *pDestino = destino;
  int resultado = 1;
  if((int)strlen(destino) >= posicion) {
    pDestino = pDestino + posicion;
    strcpy(pDestino, origen);
  }else resultado = 0;
  return resultado;
}
