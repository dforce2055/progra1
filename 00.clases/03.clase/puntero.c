/* comentarios */
#include <stdio.h>
int main(){
  int a, *ptr;
  a = 3;
  ptr = &a;
  printf("%p\n", ptr);
  ptr = ptr + 1;
  printf("%p\n", ptr);
  return 0;
}
