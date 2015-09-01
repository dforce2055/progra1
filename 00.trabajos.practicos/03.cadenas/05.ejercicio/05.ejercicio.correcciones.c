#define _CRT_SECURE_NO_WARNINGS
/* 5. Hacer una función que permita insertar en una secuencia de dígitos los caracteres
guión cada 8 dígitos a partir del cuarto dígito, y un espacio cada 8 dígitos a partir
del octavo dígito. Si la cantidad de dígitos no es múltiplo de ocho agregar delante de
la cadena caracteres '0' hasta que la misma sea múltiplo de 8.
  Ejemplos: 472348237388539055823012    ->    4723-4823 7388-5390 5582-3012
            8237388539055823012         ->    0000-0823 7388-5390 5582-3012

 */
#include <stdio.h>
//todas los propotipos de las funciones deben estar en la cabecera. Normativa 
// de Programación estructurada.
void formateaArreglo(char *arreglo);
void agregarCeros(char *arreglo, int cantCeros);
void agregarGuiones(char *arreglo);
void agregarEspacios(char *arreglo);

void mostrarArreglo(char *arreglo);
void concatArreglo(char *destino, char *origen);
void copiarArreglo(char *destino, char *origen);
void concatCaracter(char *destino, char caracter);

#define SIZE 50
int main(){
  char arreglo[SIZE]  = "472348237388539055823012";

  printf("Arreglo Original:\n====================\n");
  mostrarArreglo(arreglo);
  formateaArreglo(arreglo);
  printf("\nArreglo Formateado:\n=====================\n");
  mostrarArreglo(arreglo);

  return 0;
}
void formateaArreglo(char *arreglo){
  int i, largo, agregar = 0;
  for(largo = 0; arreglo[largo]; largo++)
        ;
  if(largo % 8 != 0){
    agregar = 8 - (largo % 8);
    agregarCeros(arreglo, agregar);
  }
  agregarGuiones(arreglo);
  agregarEspacios(arreglo);
}
void agregarCeros(char *arreglo, int cantCeros){
  int i;
  char nuevoArreglo[SIZE];
  for(i = 0; i < cantCeros; i++) nuevoArreglo[i] = '0';
  nuevoArreglo[i] = '\0';
  concatArreglo(nuevoArreglo, arreglo);
  copiarArreglo(arreglo, nuevoArreglo);

}
void agregarGuiones(char *arreglo){
  char newArreglo[SIZE] = {'\0'};
  char *pArreglo = arreglo;
  int contador;
  for(contador = 1; *pArreglo != '\0'; pArreglo++, contador++){
    if(contador % 4 == 0 && contador % 8 != 0){
      concatCaracter(newArreglo, *pArreglo);
      concatCaracter(newArreglo, '-');
    }else concatCaracter(newArreglo, *pArreglo);
  }
  copiarArreglo(arreglo, newArreglo);
}
void agregarEspacios(char *arreglo){
  char newArreglo[SIZE] = {'\0'};
  char *pArreglo = arreglo;
  int contador;
  for(contador = 1; *pArreglo != '\0'; pArreglo++, contador++){
    if(contador % 9 == 0){
      concatCaracter(newArreglo, *pArreglo);
      concatCaracter(newArreglo, ' ');
    }else concatCaracter(newArreglo, *pArreglo);
  }
  copiarArreglo(arreglo, newArreglo);
}
void mostrarArreglo(char *arreglo){
  printf("%s\n", arreglo);
}
void concatArreglo(char *destino, char *origen){
  for( ; *destino != '\0'; destino++);//corro el puntero hasta encontrar el ultimo caracter
  for( ; *origen != '\0'; origen++, destino++) *destino = *origen;//copio en destino lo de origen y corro el puntero
  *destino = '\0';
}
void concatCaracter(char *destino, char caracter){
  for( ; *destino != '\0'; destino++);//corro el puntero hasta encontrar el ultimo caracter
  *destino = caracter;

}
void copiarArreglo(char *destino, char *origen){
  for( ; *origen != '\0'; destino++, origen++) *destino = *origen;
  destino = '\0';
}