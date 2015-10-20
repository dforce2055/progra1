/* 3. Hacer un programa que invoque y pruebe las siguientes funciones:
grabarMatriz() permite grabar una matriz, tal que en un renglón se encuentren los valores
reales de toda una fila
leerMatriz() permite cargar una matriz desde el archivo generado por la función anterior*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FIL 4
#define COL 4
void grabarMatriz(FILE *out, int matriz[FIL][COL]);
void mostrarMatriz(int matriz[FIL][COL]);
int main(){
  FILE *out;
  int matriz[FIL][COL] = {1,2,3,4,
                          1,2,3,4,
                          1,2,3,4,
                          1,2,3,4 };

  if((out = fopen("matriz.txt","wt")) == NULL){
    puts("Error al intentar crear >'matriz.txt'");
    return 1;
  }

  grabarMatriz(out, matriz);

  fclose(out);
  return 0;
}
void grabarMatriz(FILE *out, int matriz[FIL][COL]){
  int i, j;
  char c;
  for(i = 0; i < FIL; i++){
    for(j = 0; j < COL; j++){
      fprintf(out,"%d",matriz[i][j]);
    }
    fputc('\n', out);
  }
}
