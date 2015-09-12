/* 1. Realizar una función que permita cargar con números enteros, una matriz de 5x5,
ingresando los datos desde teclado. ¿En qué cambiaría la función si la matriz
contuviera otro tipo de datos y/o tuviese otras dimensiones? */
/*
  Si contuviera otro tipo de datos, deberia cambiar la forma que guarda e
  imprime cada elemento de la matriz.
  Si la matriz cambia de dimensiones se define en FIL y COL adaptandose dentro de
  main.*/
#include <stdio.h>
#define FIL 5
#define COL 5
void cargar(int *pMatriz);
void mostrar(int *pMatriz);
int main(){
  int matriz[FIL][COL];
  int *pMatriz = (int*)matriz;

  puts("Ingrese numeros a la matriz:");
  cargar(pMatriz);
  mostrar(pMatriz);
  return 0;
}
void cargar(int *pMatriz){
  int *pFinMatriz = pMatriz + FIL*COL;
  for(; pMatriz != pFinMatriz; pMatriz++) scanf("%d", pMatriz);
}
void mostrar(int *pMatriz){
  int f,c;
  for(f = 0; f < FIL; f++){
    for(c = 0; c < COL; c++){
      printf("%4d", *pMatriz);
      pMatriz++;
    }
    printf("\n");
  }
}
