/* MATRIZ Patricia
  LOS PUNTEROS PASAN POR COPIA NO POR REFERENCIA Ej.
  pMatriz;
*/
#include <stdio.h>
#define FILAS 2
#define COLS 3
void cargar(int matriz[FILAS][COLS]);
void mostrar(int * pMatriz);
int main(){
  int matriz[FILAS][COLS];
  cargar(matriz);
  mostrar(matriz);
  return 0;
}
void cargar(int matriz[FILAS][COLS]){
  int f, c;
  for(f = 0; f < FILAS; f++){
    for(c = 0; c < COLS; c++){
      printf("[%d][%d]: ", f+1, c+1);
      scanf("%d", &matriz[f][c]);
    }
  }
}
void mostrar(int *pMatriz){
  int f, c;
  for(f = 0; f < FILAS; f++){
    for(c = 0; c < COLS; c++){
      printf("%4d", *pMatriz);
      pMatriz++;
    }
    printf("\n");
  }
}
