/* 9. Dada una matriz de dimension NxN. realizar las siguientes operaciones:
    a) Intercambiar dos filas cualquiera.
    b) Intercambiar dos columnas cualesquiera.
    c) Intercambiar una fila y una columna dada
*/
#include <stdio.h>
#define FIL 4
#define COL 4
void mostrar(int *matriz);
void swapFilas(int matriz[FIL][COL], int fDest, int fOrig);
void swapColumnas(int matriz[FIL][COL], int cDest, int cOrig);
void swapFilCol(int matriz[FIL][COL], int fil, int col);
int main(){
  int matriz[FIL][COL] = {  1, 2, 3, 4,
                            2, 0, 0, 2,
                            1, 0, 1, 0};

  mostrar((int *)matriz);
  swapFilas(matriz, 0, 1);
  mostrar((int *)matriz);
  swapColumnas(matriz, 0, 1);
  mostrar((int *)matriz);
  swapFilCol(matriz, 1, 0);
  mostrar((int *)matriz);

  return 0;
}
void mostrar(int *matriz){
  int *pFin = matriz + FIL*COL;
  int i;
  printf("\n");
  for(i = 1; matriz < pFin; i++, matriz++){
    printf("%4d", *matriz);
    if(i % COL == 0) printf("\n");
  }
}
void swapFilas(int matriz[FIL][COL], int fDest, int fOrig){
  int buffer, col;
  for(col = 0; col < COL; col++){
    buffer = matriz[fDest][col];
    matriz[fDest][col] = matriz[fOrig][col];
    matriz[fOrig][col] = buffer;
  }
}
void swapColumnas(int matriz[FIL][COL], int cDest, int cOrig){
  int buffer, fil;
  for(fil = 0; fil < FIL; fil++){
    buffer = matriz[fil][cDest];
    matriz[fil][cDest] = matriz[fil][cOrig];
    matriz[fil][cOrig] = buffer;
  }
}
void swapFilCol(int matriz[FIL][COL], int fil, int col){
  int fila[FIL];
  int columna[COL];
  int i;
  //copiar fila
  for(i = 0; i < FIL; i++) fila[i] = matriz[fil][i];
  //copiar columna
  for(i = 0; i < COL; i++) columna[i] = matriz[i][col];

  for(i = 0; i < FIL; i++){
    matriz[fil][i] = columna[i];
  }

  for(i = 0; i < COL; i++){
    matriz[col][i] = fila[i];
  }

}
