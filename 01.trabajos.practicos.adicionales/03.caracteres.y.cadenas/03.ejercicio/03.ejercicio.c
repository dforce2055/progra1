/* Separar  las  palabras  de  una  cadena  de  caracteres,  imprimiendo  cada
una  en  una  línea  de pantalla.*/
#include <stdio.h>
char *separaPalabras(char *cadena);
void mostrarArreglo(char *arreglo);
int main(){
  char cadena[] = "Aca hay varias palabras";
  int i;

  for(i = 0; cadena[i]; i++){
    if(cadena[i] == ' ') printf("\n");
    else printf("%c", cadena[i]);
  }
  return 0;
}
