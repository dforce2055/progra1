/* copiar valores de un vector a otro, cada 4 elementos agregar un espacio en blanco */
#include <stdio.h>
#define SIZE 20
void mostrarArreglo(char *arreglo);
char * agregarGuiones(char *arreglo, int largo);
int main(){
  char a[SIZE] = "123456789";
  char *b;
  int i, j, contador = 1;
  //mostrarArreglo(a);

  /* FUNCIONA
  for(i = 0, j = 0; i < SIZE; i++, j++, contador++){
    if(contador % 3 == 0){
      b[j] = a[i];
      j++;
      b[j] = ' ';
    }else b[j] = a[i];
  }*/
  b = agregarGuiones(a, SIZE);
  mostrarArreglo(b);
  //printf("Contador:%d\ni:%d\nj:%d\n", contador, i,j);

  return 0;
}
void mostrarArreglo(char *arreglo){
  /*  int i;
  for(i = 0; arreglo[i]; i++){
    printf("%c", arreglo[i]);
  }
  printf("\n");*/
  printf("%s \n", arreglo);
}

char * agregarGuiones(char *arreglo, int largo){
  char nuevoArreglo[largo+1];
  int i = 0, j = 0, contador;
  mostrarArreglo(arreglo);
  for(contador = 1; arreglo[i]; i++, j++, contador++){
    if(contador % 4 == 0){
      nuevoArreglo[j] = arreglo[i];
      j++;
      nuevoArreglo[j] = '-';
    }else nuevoArreglo[j] = arreglo[i];
  }
  nuevoArreglo[j] = '\0';
  arreglo = nuevoArreglo; //el puntero de arreglo ahora apunta al nuevo arreglo
  return arreglo;
}
