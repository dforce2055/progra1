/* comentarios */
#include <stdio.h>
void intercambiar(int *a, int *b);
int main(){
	int x, y;
  x = 3;
  y = 5;
  intercambiar(&x, &y);
  printf("%d - %d\n", x, y);
  return 0;
}
void intercambiar(int *a, int *b){
  int buffer;
  buffer = *a;
  *a = *b;
  *b = buffer;
}
