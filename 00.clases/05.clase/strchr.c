/* comentarios */
#include <stdio.h>
#include <string.h>
int main(){
  char cad[] = "Programación";
  char *ptr;
  ptr = strchr(cad, 'g');
  if(ptr != NULL) printf("La letra g se encontro en la posición %d\n", ptr - cad); //muesta el numero entero del resultado de restar los punteros
  return 0;
}
