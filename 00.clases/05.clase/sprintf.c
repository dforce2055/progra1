/* comentarios */
#include <stdio.h>
int main(){
  char cad[20];
  float pi = 3.1416;
  sprintf(cad, "%f", pi);
  cad[1] = ',';
  puts(cad);
  return 0;
}
