/* 2. Hacer una función que permita eliminar todas las directivas para el preprocesador
de un programa fuente escrito en lenguaje “C”.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void eliminarDirectivas(FILE *in, FILE *out);
int main(){
  FILE *in, *out;

  if((in = fopen("directivas.txt","rt")) == NULL){
    puts("Error al intentar leer >'directivas.txt'");
    return 1;
  }

  if((out = fopen("directivas2.txt","wt")) == NULL){
    puts("Error al intentar crear >'directivas2.txt'");
    fclose(in);
    return 1;
  }

  eliminarDirectivas(in, out);

  fclose(in);
  fclose(out);
  return 0;
}
void eliminarDirectivas(FILE *in, FILE *out){
  char cadena[256];
  fgets(cadena, 256, in);
  while(!feof(in)){
    if(cadena[0] == '#'){
      cadena[0] = '\0';
    }
    fputs(cadena, out);
    fgets(cadena, 256, in);
  }
}
