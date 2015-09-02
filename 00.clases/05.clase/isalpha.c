/* comentarios */
#include <stdio.h>
#include <ctype.h>
int main(){
  int i;
  char cad[80];
  printf("Ingrese una cadena de caracteres: ");
  scanf("%s", cad);
  for(i = 0; cad[i]; i++){
    if(isalpha(cad[i])) printf("%c es un caracter alfabetico\n", cad[i]);
  }
  return 0;
}
