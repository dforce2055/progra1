/* 8. Hacer una función que permita eliminar una sub-cadena a partir de una
posición y un tamaño dados. */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
void eliminarSub(char *cadena, char *subCadena, int posicion);
int main(){
  char cadena[256] = "Esto es un placer horror!asd";
  char subCadena[] = " horror";
  char subCadena2[] = " placer";
  eliminarSub(cadena, subCadena2, 10);
  puts(cadena);

  return 0;
}
void eliminarSub(char *cadena, char *subCadena, int posicion){
  char *pCadena = cadena + posicion;
  char *pSubCadena = pCadena + strlen(subCadena);
  char buffer[256];
  int i;

  for(i = 0 ; i <= strlen(subCadena)-1; i++){//guardo en buffer la subcadena extraida de cadena
    buffer[i] = *pCadena;
    pCadena++;
  }
  pCadena = cadena + posicion;//puntero retoma posición original
  if(strcmp(buffer, subCadena) == 0){//comparo buffer con subcadena, si strcmp == 0 son cadenas identicas
    for( ; *pSubCadena != '\0'; pCadena++, pSubCadena++) *pCadena = *pSubCadena;
    *pCadena = '\0';
  }
}
