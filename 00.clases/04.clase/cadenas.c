/* scanf tiene limitación, guarda caracteres hasta encontrar un espacio
  ¿Cuál es la función correcta que debemos utilizar para almacenar cadenas ?
  */
#include <stdio.h>
int longitud(char *cadena);
int main(){
  char nombre[40];
  printf("Ingrese su nombre: ");
  scanf("%s", nombre);
  printf("Usted se llama %s\n", nombre);
  printf("Y su nombre contiene %d caracteres\n", longitud(nombre));
  return 0;
}
int longitud(char *cadena){
  int i = 0;
  while(cadena[i]) i++; // =>  while(cadena[i] != '\0') i++;
  return i;
}

/* int longitud(char *cadena){
  int i;
  for(i =0; cadena[i]; i++)
        ;
  return i;
}*/
