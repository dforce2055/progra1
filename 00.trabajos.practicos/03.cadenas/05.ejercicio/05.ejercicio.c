/* 5. Hacer una función que permita insertar en una secuencia de dígitos los caracteres
guión cada 8 dígitos a partir del cuarto dígito, y un espacio cada 8 dígitos a partir
del octavo dígito. Si la cantidad de dígitos no es múltiplo de ocho agregar delante de
la cadena caracteres ‘0’ hasta que la misma sea múltiplo de 8.
  Ejemplos: 472348237388539055823012   ->    4723-4823 7388-5390 5582-3012
            8237388539055823012        ->    0000-0823 7388-5390 5582-3012

 */
#include <stdio.h>
char * formateaArreglo(char *arreglo);
void mostrarArreglo(char *arreglo);

int main(){
  char arreglo[]  = "8237388539055823012";
  char *pArreglo = arreglo;
  mostrarArreglo(pArreglo);
  pArreglo = formateaArreglo(pArreglo);
  mostrarArreglo(pArreglo);

  return 0;
}
char * formateaArreglo(char *arreglo){
  char * agregarCeros(char *arreglo, int largo, int cantCeros);
  char * agregarGuiones(char *arreglo, int largo);
  char * agregarEspacios(char *arreglo, int largo);

  int i, largo, agregar = 0;
  for(largo = 0; arreglo[largo]; largo++);
  if(largo % 8 != 0){
    agregar = 8 - (largo % 8);
    arreglo = agregarCeros(arreglo, largo, agregar);
  }
  for(i = 0; arreglo[i]; i++);
  largo = i + (i / 4);//le agrego a largo la cantidad de 0 y de espacios a agregar
  //printf("LARGO: %d", largo);

  arreglo = agregarGuiones(arreglo, largo);
  for(largo = 0; arreglo[largo]; largo++);
  //printf("LARGO:[%d]\n", largo);
  arreglo = agregarEspacios(arreglo, largo);

  return arreglo;
}
char * agregarCeros(char *arreglo, int largo, int cantCeros){
  int i, j, size = largo + cantCeros +1;
  char nuevoArreglo[size];

  for(i = 0; i < size-1; i++) nuevoArreglo[i] = '0';
  for(i = largo -1, j = size -2; arreglo[i]; i--, j--) nuevoArreglo[j] = arreglo[i];

  arreglo = nuevoArreglo;
  return arreglo;
}
char * agregarGuiones(char *arreglo, int largo){
  char nuevoArreglo[largo*2];
  int i = 0, j = 0, contador;
  mostrarArreglo(arreglo);
  for(contador = 1; arreglo[i]; i++, j++, contador++){
    if(contador % 4 == 0 && contador %8 != 0){
      nuevoArreglo[j] = arreglo[i];
      j++;
      nuevoArreglo[j] = '-';
    }else nuevoArreglo[j] = arreglo[i];
  }
  nuevoArreglo[j] = '\0';
  arreglo = nuevoArreglo; //el puntero de arreglo ahora apunta al nuevo arreglo
  return arreglo;
}
char * agregarEspacios(char *arreglo, int largo){
  char nuevoArreglo[largo+100];
  int i = 0, j = 0, contador;
  mostrarArreglo(arreglo);
  for(contador = 1; arreglo[i]; i++, j++, contador++){
    if(contador % 9 == 0){
      nuevoArreglo[j] = arreglo[i];
      j++;
      nuevoArreglo[j] = ' ';
    }else nuevoArreglo[j] = arreglo[i];
  }
  nuevoArreglo[j] = '\0';
  arreglo = nuevoArreglo; //el puntero de arreglo ahora apunta al nuevo arreglo
  //printf("LARGO:[%d]\n", largo);
  return arreglo;
}
void mostrarArreglo(char *arreglo){
  printf("%s\n", arreglo);
}
