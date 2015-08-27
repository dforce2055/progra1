/* comentarios */
#include <stdio.h>
#define MAXF 4
#define MAXC 3
void imprimirMatriz(int m[][MAXC]);
int main(){
  int f, c, mat[MAXF][MAXC];
  for(f = 0; f < MAXF; f++){
    for(c = 0; c < MAXC; c++){
      printf("Ingrese un número entero: ");
      scanf("%d", &mat[f][c]);
    }
  }
  imprimirMatriz(mat);

  return 0;
}
void imprimirMatriz(int m[][MAXC]){
  int f,c;
  for(f = 0; f < MAXF; f++){
    for(c = 0; c < MAXC; c++){
      printf("%4d", m[f][c]);
    }
    printf("\n");
  }
}
