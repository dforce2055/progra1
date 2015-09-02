/* comentarios */
#include <stdio.h>
int main(){
  char cad[] = "Lima 717";
  int altura;
  //sscanf(&cad[5], "%d", &altura);//pasamos la dirección de memoria de donde empiezan los números enteros
  sscanf(cad+5, "%d", &altura);//pasamos la dirección de memoria de donde empiezan los números enteros
  printf("%d\n", altura);
  return 0;
}
