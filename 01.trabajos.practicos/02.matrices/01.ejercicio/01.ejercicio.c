/* 1. Realizar una función que permita cargar con números enteros, una matriz de 5x5,
ingresando los datos desde teclado. ¿En qué cambiaría la función si la matriz
contuviera otro tipo de datos y/o tuviese otras dimensiones? */
/* BUSCAR PUNTEROS A MATRIZ EN C*/
#include <stdio.h>
#define FIL 5
#define COL 5
#define SIZE 25
void cargarMatriz(int matriz[][COL]);
int matrizLLena(void);
void printMatriz(int matriz[][COL]);

int valor;
int matriz[5][5];
int f = 0, c = 0, contador = 0;

int main(){

  printf("ingrese un número distinto a 0: ");
  scanf("%d",&valor);
  while(valor != 0 && !matrizLLena()){
    cargarMatriz(matriz);
    printf("ingrese un número distinto a 0: ");
    scanf("%d",&valor);
  }
  printMatriz(matriz);

  return;
}
void cargarMatriz(int matriz[][COL]){
  matriz[f][c] = valor;
  if(c != 0 && c % 4 == 0){
    f++;
    c = 0;
  }else c++;
  contador++;
}
int matrizLLena(void){
  return (contador == (FIL * COL))?1:0;
}
void printMatriz(int matriz[][COL]){
  int i, j;
  for(i = 0; i < FIL; i++){
    for(j = 0; j < COL; j++){
      printf("%d", matriz[i][j]);
    }
    printf("\n");
  }
}
