#include <stdio.h>
#include <stdlib.h>
int main(){
  int *ptr;
  ptr = (int *) malloc(sizeof(int));
  *ptr = 3;
  *ptr = *ptr + 1;
  printf("%d\n", *ptr);
  free(ptr);
  ptr = NULL;

  return 0;
}
