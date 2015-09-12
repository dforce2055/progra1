/* 2. Realizar una función que determine si una matriz cuadrada de dimensión N es simétrica
con respecto a su diagonal principal. */
/* Ej. de matriz simetica en su diagonal principal
  -8  -1  3
  -1   7  4
   3   4  9
*/
#define N 5
int simetria(int matriz[][N]);
int main(){
  int matriz[N][N] = {1, 2, 3, 4, 5,
                      2, 0, 0, 9, 0,
                      3, 6, 6, 1, 0,
                      4, 1, 2, 3, 0,
                      5, 0, 0, 0, 0,
                      };
  int *pMatriz = (int *)matriz;

  if(simetria(matriz)) puts("Es simetrica");
  else puts("No son simetricas");
  return 0;
}
int simetria(int matriz[][N]){
  int i = 0;

  while(matriz[0][i] == matriz[i][0]) i++;
  if(i == N) return 1;
  else return 0;
}
