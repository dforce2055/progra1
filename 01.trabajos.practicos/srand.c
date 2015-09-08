/* */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  int i, auxI;
  char auxC;
  srand(time(NULL));
  printf("Numeros aleatorios:\n");
  for(i = 0; i <10; i++){
    auxI = rand() % 10 + 1; // (vFinal -vInicial +1 ) + vInicial
    printf("%4d", auxI);
  }
  printf("\n");
  printf("Letras aleatorias:\n");
  for(i = 0; i <10; i++){
    auxC = 'A' + ( rand() % ('Z' - 'A')); // (vFinal -vInicial +1 ) + vInicial
    printf("%4c", auxC);
  }
  printf("\n");
  return 0;
}
