/* comentarios */
#include <stdio.h>
int main(){
  char cad[] = "3.1416";
  float pi;
  sscanf(cad, "%f", &pi);
  printf("%f\n", pi);
  return 0;
}
