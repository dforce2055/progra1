/* Separar  las  palabras  de  una  cadena  de  caracteres,  imprimiendo  cada  
una  en  una  línea  de pantalla.*/
#include <stdio.h>
char *separaPalabras(char *cadena);
void mostrarArreglo(char *arreglo);
int main(){
  char cadena[] = "Aca hay varias palabras";
  char *pCadena;
  pCadena = separaPalabras(cadena);
  
  mostrarArreglo(pCadena);
  return 0;
}
char *separaPalabras(char *cadena){
  char *pNuevaCadena, *pCadenas;
  int i;
  for(i = 0; cadena[i]; i++) printf("%c", cadena[i]);
  pNuevaCadena = "literal de cadena\0";
  pCadenas[i] = '\0';
  
  //return pCadenas;
}

void mostrarArreglo(char *arreglo){
  printf("%s\n", arreglo);
}