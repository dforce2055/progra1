/* Hacer  una  función  que  permita  reemplazar  todas  las  secuencias  de  
más  de  un  espacio  por uno solo en una cadena de caracteres cualquiera. */
#include <stdio.h>
char  *unSoloEspacio(char *cadena);
void mostrarArreglo(char *arreglo);
int main(){
  char cadena[] = "esto tiene       2         espacios";
  char *pCadena;
  
  mostrarArreglo(cadena);
  pCadena = unSoloEspacio(cadena);
  mostrarArreglo(pCadena);
  return 0;
}
char *unSoloEspacio(char *cadena){
  int i, j, largo;
  char *pNuevaCadena;
  
  for(largo = 0; cadena[largo]; largo++);
  //mientras cadena[j] tenga caracteres
  for(i = 0, j = 0; cadena[j]; i++, j++){
    if(cadena[i] == ' ' && cadena[i+1] == ' '){//si encuento un ' ' 
      while(cadena[i] == ' ') i++;//corro la posición del vector original hasta que no se encuentren más ' '
      pNuevaCadena[j] = ' ';//copio en el nuevo vector un ' '
      i--;//le resto un lugar al vector original
    }else pNuevaCadena[j] = cadena[i];//copio en el nuevo vector el caracter del primer vector
  }
  pNuevaCadena[largo] = '\0';
  return pNuevaCadena;
}

void mostrarArreglo(char *arreglo){
  printf("%s\n", arreglo);
}