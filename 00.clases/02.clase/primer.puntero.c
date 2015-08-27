/* Primer programa para ma nipular punteros */
#include <stdio.h>
int main(){
  int a, b;
  int *ptr; // declaro un puntero a un entero, leer de derecha a izquierda para entender mejor <-
  a = 3;
  ptr = &a;
  b = *ptr;
  printf("%d\n", b);
	return 0;
}
