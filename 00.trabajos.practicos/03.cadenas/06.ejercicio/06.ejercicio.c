/* 6. Hacer una función strNcpy() que permita extraer una sub-cadena, indicando
la posición inicial y la cantidad de caracteres. Ejemplo, dada la secuencia:
“El número de teléfono es 4356-7890. “ extraer la sub-cadena que comienza en la
posición 26, la cantidad de 9 caracteres. */
#include <stdio.h>
char *strNcpy(char *cadena, int inicio, int cant);
void mostrarArreglo(char *arreglo);
int main(){
  char cadena[] = "El número de teléfono es 4356-7890. ";
  char * pCadena = cadena;
  mostrarArreglo(pCadena);
  pCadena = strNcpy(pCadena, 27, 9);
  mostrarArreglo(pCadena);
  return 0;
}
char *strNcpy(char *cadena, int inicio, int cant){
  int i = 0;
  char *subCadena;
  for(i = 0 ;cadena[inicio] && cant > 0; cant--, i++, inicio++){
    subCadena[i] = cadena[inicio];
  }
  subCadena[i] = '\0';
  return subCadena;
}
void mostrarArreglo(char *arreglo){
  printf("%s\n", arreglo);
}
