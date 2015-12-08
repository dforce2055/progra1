/* Generar e imprimir la siguiente matriz de orden N x N(solo para valores impares de N y
mayores que 3). El valor de N se declara con #define.
Ejemplo: con N = 7:
                    0 0 0 0 0 0 0
                    1 0 0 0 0 0 7
                    1 2 0 0 0 6 7
                    1 2 3 0 5 6 7
                    1 2 3 4 5 6 7
                    1 2 3 4 5 6 7
                    1 2 3 4 5 6 7
*/
#include <stdio.h>
#define N 7
void generar(int matriz[N][N]);
void mostrar(int *matriz);
int main(){
  int matriz[N][N] = {0};

  puts("Vacia:");
  mostrar((int *)matriz);
  generar(matriz);
  puts("\nGenerar:");
  mostrar((int *)matriz);

}
void mostrar(int *matriz){
  int *pFin = matriz + N * N;
  int i;
  for(i = 1; matriz < pFin; i++, matriz++){
    printf("%4d", *matriz);
    if(i % N == 0) printf("\n");
  }
}
void generar(int matriz[N][N]){
  int i, fil, col, ceros = N;
  //1234567...N
  for(fil = 0; fil < N; fil++){
    for(i = 1,col = 0; col < N; i++, col++){
      matriz[fil][col] = i;
    }
  }

  for(fil = 0, i = 0; fil < ceros+3; fil++, ceros -=2, i++){
    for(col = 0; col < ceros; col++){
      matriz[fil][col+i] = 0;
    }
  }
}
