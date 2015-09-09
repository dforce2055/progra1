/* 8. Hacer una función que permita eliminar una sub-cadena a partir de una
posición y un tamaño dados. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void eliminarSub(char *cadena, char *subCadena, int posicion);
int main(){
  char cadena[100] = "Esto es un placer horror!";
  char subCadena[] = " horror";
  char subCadena2[] = "placer";
  eliminarSub(cadena, subCadena, 17);
  puts(cadena);

  return 0;
}
void eliminarSub(char *cadena, char *subCadena, int posicion){
  char *pCadena = cadena + posicion;
  char *pSubCadena = pCadena + strlen(subCadena);

  if(strcmp(pCadena, subCadena))
    for( ; *pSubCadena != '\0'; pCadena++, pSubCadena++) *pCadena = *pSubCadena;
    *pCadena = '\0';
}
//MAL REHACER NO SE COMPARA LA CADENA CORRECTAMENTE
