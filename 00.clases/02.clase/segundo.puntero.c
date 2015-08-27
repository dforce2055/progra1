/* comentarios */
#include <stdio.h>
int main(){
  int a, *ptr;
  a = 5;
  ptr = &a;
  *ptr = *ptr + 1; // (*ptr)++ suma, es recomendable no utilizar
  printf("%d", a);
  printf("%p", ptr); // %p para direccion de memoria de puntero
	return 0;
}
