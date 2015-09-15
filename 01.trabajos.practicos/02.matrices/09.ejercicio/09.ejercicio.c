/* 9. Dada una matriz de dimension NxN. realizar las siguientes operaciones:
    a) Intercambiar dos filas cualquiera.
    b) Intercambiar dos columnas cualesquiera.
    c) Intercambiar una fila y una columna dada
    d) Transponer la matriz sobre si misma
*/
#include <stdio.h>
#define FIL 3
#define COL 3
void mostrar(int *matriz);
void swapFilas(int matriz[FIL][COL], int fDest, int fOrig);
void swapColumnas(int matriz[FIL][COL], int cDest, int cOrig);
void swapFilCol(int matriz[FIL][COL], int fil, int col);
void transponer(int matriz[FIL][COL]);
int main(){
  int matriz[FIL][COL] = {  1, 2, 3,
                            4, 5, 6,
                            7, 8, 9};

  puts("Matriz original:");
  mostrar((int *)matriz);
  swapFilas(matriz, 0, 1);
  puts("\nCambio de filas");
  mostrar((int *)matriz);
  swapColumnas(matriz, 0, 1);
  puts("\nCambio de columnas");
  mostrar((int *)matriz);
  swapFilCol(matriz, 1, 0);
  puts("\nCambio de columnas por filas:");
  mostrar((int *)matriz);
  transponer(matriz);
  puts("\nMatriz transpuesta:");
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
  //copio columna a fil
  for(i = 0; i < FIL; i++) matriz[fil][i] = columna[i];
  //copi fila a columna
  for(i = 0; i < COL; i++) matriz[col][i] = fila[i];
  //se sobreescriben en la intersección
}
void transponer(int matriz[FIL][COL]){
  int aux[FIL][COL];
  int fil, col;
  //copia de matrices
  for(fil = 0; fil < FIL; fil++){
    for(col = 0; col < COL; col++){
      aux[fil][col] = matriz[fil][col];
    }
  }
  //transponer
  for(col = 0; col < COL; col++){
    for(fil = 0; fil < FIL; fil++){
      matriz[fil][col] = aux[col][fil];
    }
  }
}
