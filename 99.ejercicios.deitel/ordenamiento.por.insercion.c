/* ordenamiento por inserción */
#include <stdio.h>
void mostrar(int *numeros);
void ordenar1(int *numeros);
void ordenar2(int *numeros);
int main(){
  int num[] = {8,3,5,1,2,7,6,9,4,0};

  puts("Arreglo desordenado:");
  mostrar(num);
  puts("Arreglo ordenado:");
  ordenar1(num);
  mostrar(num);
  return 0;
}
void mostrar(int *numeros){
  int i;
  for(i = 0; i < 10; i++)
    printf("%4d", numeros[i]);
    printf("\n");
}
void ordenar1(int *numeros){
  int i, j, temp1, temp2;

  for(i = 0; i < 10 - 1; i++){
    for(j = i + 1; j < 10; j++){
      temp1 = numeros[i];
      temp2 = numeros[j];
      if(temp1 > temp2){
        numeros[j] = temp1;
        numeros[i] = temp2;
      }
    }
  }
}
void ordenar2(int *numeros){
  int i, j, temp;
  for (i=1; i<10; i++){
    temp = numeros[i];
    j = i - 1;
    while ( (numeros[j] > temp) && (j >= 0) ){
           numeros[j+1] = numeros[j];
           j--;
        }
    numeros[j+1] = temp;
    }
}
