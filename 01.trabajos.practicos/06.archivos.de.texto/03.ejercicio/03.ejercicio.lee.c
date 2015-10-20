/* 3. Hacer un programa que invoque y pruebe las siguientes funciones:
grabarMatriz() permite grabar una matriz, tal que en un renglón se encuentren los valores
reales de toda una fila
leerMatriz() permite cargar una matriz desde el archivo generado por la función anterior*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define FIL 4
#define COL 4
int leerMatriz(FILE *in, int matriz[FIL][COL]);
void mostrarMatriz(int matriz[FIL][COL]);
int main(){
  FILE *in;
  int matriz2[FIL][COL] = {0};

  if((in = fopen("matriz.txt","rt")) == NULL){
    puts("Error al intentar leer >'matriz.txt'");
    return 1;
  }

  leerMatriz(in, matriz2);
  mostrarMatriz(matriz2);

  fclose(in);
  return 0;
}
int leerMatriz(FILE *in, int matriz[FIL][COL]){
  char cadena[COL];
  int i = 0;

  fgets(cadena, 256, in);
  while(!feof(in)){
    sscanf(cadena, "%1d%1d%1d%1d", &matriz[i][0],&matriz[i][1],&matriz[i][2],&matriz[i][3]);
    fgets(cadena, 256, in);
    i++;
  }
}
void mostrarMatriz(int matriz[FIL][COL]){
  int i,j;
  for(i = 0; i < FIL; i++){
    for(j = 0; j < COL; j++){
      printf("%d", matriz[i][j]);
    }
    printf("\n");
  }

}
