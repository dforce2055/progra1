/* leer consiga.txt */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define FIL 3
#define COL 3
void cargarMatriz(int matriz[][COL], FILE *in);
void mostrarMatriz(int matriz[][COL]);
int main(){
  FILE *in;
  int matriz[FIL][COL] = {0};

  if((in = fopen("matriz.txt","rt")) == NULL){
    puts("Error al intentar leer >'matriz.txt'");
    return 1;
  }

  cargarMatriz(matriz, in);
  puts("Matriz Cargada:");
  mostrarMatriz(matriz);

  fclose(in);
  return 0;
}
void cargarMatriz(int matriz[][COL], FILE *in){
  char cadena[256];
  char *pCadena = cadena;
  int f = 0, c = 0, valor = 0, i = 0;

  fgets(cadena, 256, in);
  while(!feof(in)){
    for(i = 0, pCadena = cadena; i < 3; pCadena++){
      if(isalnum(*pCadena)){
        switch(i){
          case 0: sscanf(pCadena, "%d", &f); break;
          case 1: sscanf(pCadena, "%d", &c); break;
          case 2: sscanf(pCadena, "%d", &valor); break;
        }
        i++;
      }
    }
    matriz[f][c] = valor;
    fgets(cadena, 256, in);
  }
}
void mostrarMatriz(int matriz[][COL]){
  int i = 0, j = 0;
  for(i = 0; i < FIL; i++){
    for(j = 0; j < COL; j++){
      printf("%4d", matriz[i][j]);
    }
    printf("\n");
  }
}
