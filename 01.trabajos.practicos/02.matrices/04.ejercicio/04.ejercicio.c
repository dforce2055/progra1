/* 4. Dada una matriz de 5x5 de números enteros, ordenar en forma ascendente cada una
de sus filas. */
#include <stdio.h>
#define FIL 5
#define COL 5
void ordenar(int matriz[FIL][COL]);
void swap(int *a, int *b);
void mostrar(int *matriz);
int main(){
  int matriz[FIL][COL] = {1,2,3,4,5,
                          5,4,3,2,1,
                          0,3,1,9,-1,
                          1,2,0,1,0};
  mostrar((int *)matriz);
  ordenar(matriz);
  puts("\nOrdenada:");
  puts("========\n");
  mostrar((int *)matriz);

  return 0;
}
void ordenar(int matriz[FIL][COL]){
  int f, v, c;
  for(f = 0; f < FIL; f++){ //recorre las filas(vectores)
    for(v = 0; v < COL; v++){ //recorre cada posición
      for(c = 0; c < COL-1; c++){ //compara las posiciones y realiza el swap
        if(matriz[f][c] > matriz[f][c+1]) swap(&matriz[f][c], &matriz[f][c+1]);
      }
    }
  }
}
void swap(int *a, int *b){
  int buffer = *a;
  *a = *b;
  *b = buffer;
}
void mostrar(int *matriz){
  int *ini = matriz;
  int *fin = matriz + FIL*COL;
  int i;
  for(i = 1; ini != fin; i++, ini++){
    printf("%4d", *ini);
    if(i % COL == 0) printf("\n");
  }
}
