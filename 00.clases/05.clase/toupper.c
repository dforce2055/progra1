/* comentarios */
#include <stdio.h>
#include <ctype.h>
int main(){
  int i;
  char cad[80];
  printf("Ingrese una cadena de caracteres: ");
  scanf("%s", cad);
  for(i = 0; cad[i]; i++) cad[i] = toupper(cad[i]);

  printf("%s\n", cad);
  return 0;
}
