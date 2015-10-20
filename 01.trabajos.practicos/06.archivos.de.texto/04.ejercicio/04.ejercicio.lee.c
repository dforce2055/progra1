/* 4. Hacer un programa que invoque y pruebe las siguientes funciones:
grabarMatriz() permite grabar una matriz, tal que los valores estan separados por comas (,)
leerMatriz() permite cargar una matriz desde el generado por la función anterior */
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
  char cadena[256];
  int *pMatriz = &matriz[0][0];
  int i = 0, j = 0;

  fgets(cadena, 256, in);
  while(!feof(in)){
    for(i = 0; cadena[i]; i++){
      if(isalnum(cadena[i])){
        sscanf(&cadena[i], "%d", pMatriz);
        pMatriz++;
      }
    }
    fgets(cadena, 256, in);
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
