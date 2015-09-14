/* 5. Realizar 9 funciones que generen las matrices detalladas a continuación:
1-  4 0 0 0  0 3 0 0  0 0 2 0  0 0 0 1
2-  0 0 0 16  0 0 8 0  0 4 0 0  2 0 0 0
3-  1 2 3 4  0 1 2 3  0 0 1 2  0 0 0 1
4-  4 0 0 0  3 4 0 0  2 3 4 0  1 2 3 4
5-  1 2 3 4  5 6 7 8  9 10 11 12  13 14 15 16
6-  1 1 1 1  2 2 2 2  3 3 3 3  4 4 4 4
7-  1 2 3 4  1 2 3 4  1 2 3 4  1 2 3 4
8-  0 1 0 2  3 0 4 0  0 5 0 6  7 0 8 0
9-  1 2 3 4  12 13 14 5  11 16 15 6  10 9 8 7
 */
#define FIL 4
#define COL 4
#include <stdio.h>
void mostrar(int *matriz);
void ceros(int *matriz);
void uno(int matriz[FIL][COL]);
void dos(int matriz[FIL][COL]);
void tres(int matriz[FIL][COL]);
void cuatro(int matriz[FIL][COL]);
void cinco(int *matriz);
void seis(int *matriz);
void siete(int *matriz);
void ocho(int matriz[FIL][COL]);
void nueve(int matriz[FIL][COL]);
int main(){
  int matriz[FIL][COL];

  printf("1º\n");
  uno(matriz);
  mostrar((int *)matriz);
  printf("2º\n");
  dos(matriz);
  mostrar((int *)matriz);
  printf("3º\n");
  tres(matriz);
  mostrar((int *)matriz);
  printf("4º\n");
  cuatro(matriz);
  mostrar((int *)matriz);
  printf("5º\n");
  cinco((int *)matriz);
  mostrar((int *)matriz);
  printf("6º\n");
  seis((int *)matriz);
  mostrar((int *)matriz);
  printf("7º\n");
  siete((int *)matriz);
  mostrar((int *)matriz);
  printf("8º\n");
  ocho(matriz);
  mostrar((int *)matriz);
  printf("9º\n");
  nueve(matriz);
  mostrar((int *)matriz);

  return 0;
}
void mostrar(int *matriz){
  int *pMatriz = matriz;
  int i;
  for(i = 1; i <= FIL*COL; i++){
    printf("%4d", *pMatriz);
    if(i % COL == 0) printf("\n");
    pMatriz++;
  }
}
void ceros(int *matriz){
  int *pFin = matriz + (FIL*COL);
  for(; matriz != pFin; matriz++) *matriz = 0;
}
//9 funciones para generar matrices
void uno(int matriz[FIL][COL]){
  int p, v;
  ceros((int *)matriz);
  for(p = 0, v = 4; p < FIL; p++, v--){
    matriz[p][p] = v;
  }
}
void dos(int matriz[FIL][COL]){
  int v = 16, f = 0, c = 3, i;
  ceros((int *)matriz);
  for(i = 0; i < FIL; i++){
    matriz[f][c] = v;
    v = v / 2;
    f++;
    c--;
  }
}
void tres(int matriz[FIL][COL]){
  int f, c, v, i = 0;
  ceros((int *)matriz);
  for(f = 0; f < FIL; f++){
    matriz[i][i] =  1;
    for(c = i+1, v = 2; c < COL; c++, v++){
      matriz[f][c] = v;
    }
    i++;
  }
}
void cuatro(int matriz[FIL][COL]){
  int v = 4, i;
  ceros((int *)matriz);
  for(i = 0; i < FIL; i++){
    matriz[i][i] = v;
    if(i > 0) matriz[i][i-1] = v -1;
    if(i > 1) matriz[i][i-2] = v -2;
    if(i > 2) matriz[i][i-3] = v -3;
  }
}
void cinco(int *matriz){
  int *pFin = matriz + (FIL*COL);
  int i;
  ceros((int *)matriz);
  for(i = 1 ;matriz < pFin; i++, matriz++) *matriz = i;
}
void seis(int *matriz){
  int *pFin = matriz + (FIL*COL);
  int i = 1, f;
  ceros((int *)matriz);
  for(f = 1; matriz < pFin; f++, matriz++){
    *matriz = i;
    if(f % COL == 0) i++;
  }
}
void siete(int *matriz){
  int *pFin = matriz + (FIL*COL);
  int i;
  ceros((int *)matriz);
  for(i = 1; matriz < pFin; i++, matriz++){
    *matriz = i;
    if(i == COL) i = 0;
  }
}
void ocho(int matriz[FIL][COL]){
  int i = 1, count = 1, f;
  ceros((int *)matriz);
  for(f = 0; f < FIL; f++){
    if(f % 2 == 0){
      matriz[f][1] = count++;
      matriz[f][3] = count++;
    }else{
      matriz[f][0] = count++;
      matriz[f][2] = count++;
    }
  }
}
void nueve(int matriz[FIL][COL]){
  int c = 0, f = 0, v = 1, pasadas = 7;

  ceros((int *)matriz);
    //derecha
    for( ;c < COL; c++,v++){
      matriz[f][c] = v;
    }
    f++; c--;
    //abajo
    for(;f < FIL; f++, v++){
      matriz[f][c] = v;
    }
    f--; c--;
    //izquierda
    for(;c >= COL -COL; c--, v++){
      matriz[f][c] = v;
    }
    f--;c++;
    //arriba
    for(;f >= COL -3; f--, v++){
      matriz[f][c] = v;
    }

}
