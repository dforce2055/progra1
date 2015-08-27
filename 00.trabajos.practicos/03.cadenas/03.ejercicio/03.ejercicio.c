/* 3. Hacer una función que devuelva la cantidad de palabras (separados por uno o más espacios) que tiene una frase. */
#include <stdio.h>
int cuentaPalabras(char *cadena);
int main(){
  char frase[] = "un    texto        con       muchos          espacios     entre           medio";
  printf("La frase \"%s\" tiene %d palabra/s",frase, cuentaPalabras(frase));
  return 0;
}
int cuentaPalabras(char *cadena){
  int i, cantidadPalabras = (cadena[0])?1:0;//si cadena tiene algo, el contador se inicializa en 1
  for(i = 0; cadena[i]; i++){
    if(cadena[i] == ' '){
      while(cadena[i] == ' ') i++;
      if(cadena[i] != ' '&& cadena[i]) cantidadPalabras++;
    }
  }
  return cantidadPalabras;
}
