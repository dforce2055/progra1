/* comentarios */
#include <stdio.h>
int main(){
  int i, *ptr, w[] = {10, 20, 30, 40, 50};
  //ptr = &w[0];
  ptr = w; //EL NOMBRE DE UN ARREGLO ES UN PUNTERO A SU PRIMER ELEMENTO
  for (i = 0; i < 5; i++) {
    printf("%4d", *ptr);
    ptr++;
  }
  printf("\n");
  return 0;
}
