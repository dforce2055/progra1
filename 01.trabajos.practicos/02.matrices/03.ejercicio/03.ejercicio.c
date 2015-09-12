/* 3. Realice una función devuelva verdadero si todas sus columnas de una matriz son palíndromos.
Ejemplos:
  1221233423341221 -> Para esta matriz la función devuelve verdadero
  1221233233331111 -> Para esta matriz la función devuelve falso

*/
#include <stdio.h>
#define FIL 2
#define COL 6
int palindromo(int matriz[][COL]);
int comparar(int *fila);
int main(){
  int matriz[FIL][COL] = { 1, 2, 0, 0, 2, 1,
                           2, 1, 0, 0, 1, 2 };

  if(palindromo(matriz)) puts("Todas las filas son palindromos");
  else puts("No son todas palindromos");

  return 0;
}
int palindromo(int matriz[][COL]){
  //compara que todas las filas sean palindromos
  int f, c, contador = 0;

  for(f = 0; f < FIL; f++){
    if(comparar(matriz[f])) contador++;
  }
  return (contador == FIL)?1:0;
}
int comparar(int *fila){
  //compara los elementos de un arreglo y determina si es palindromo
  int *ini = fila;
  int *fin = fila + COL -1;
  int contador; int testigo = 1;

  for(contador = 0; contador < COL/2; contador++){
    printf("%d : %d\n", *ini, *fin);
    if(*ini != *fin) testigo = 0;
    ini++;
    fin--;
  }
  printf("\n");

  return testigo;
}
