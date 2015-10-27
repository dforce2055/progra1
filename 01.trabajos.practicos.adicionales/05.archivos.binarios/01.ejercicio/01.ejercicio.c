/* Codificar una función int buscarArch(char nombre[], int valor) que reciba el nombre
de un archivo de enteros y un número e indique en que posición del archivo se encuentra ese
número. En caso de no encontrarlo devolver -1. El archivo no está ordenado. */
#include <stdio.h>
#include <time.h>
int buscarArch(char *nombre, int valor);
int grabarArch(char *nombre);
int main(){
  srand(time(NULL));
  int pos = 0;

  grabarArch("enteros.dat");
  pos = buscarArch("enteros.dat", 2);
  if(pos == -1) puts("No se encontro el valor");
  else printf("El valor se encontro en la posicion: %d", pos);



  return 0;
}
int buscarArch(char *nombre, int valor){
  FILE *in;
  int posicion = -1, aux = 0, i = 0;

  if((in = fopen(nombre,"rb")) == NULL){
    printf("No pudo leerse > \'%s\'", nombre);
    return 0;
  }

  fread(&aux, sizeof(int), 1, in);
  while(!feof(in)) {
    if(valor == aux){
      posicion = i;
      i++;
    }
    fread(&aux, sizeof(int), 1, in);
  }

  fclose(in);
  return posicion;
}
int grabarArch(char *nombre){
  FILE *out;
  int numeros[10];
  int i;

  if((out = fopen(nombre,"wb")) == NULL){
    printf("No pudo crearse > \'%s\'", nombre);
    return 0;
  }

  for(i = 0; i < 10; i++){
    numeros[i] = rand()% 10;
  }

  for(i = 0; i < 10; i++){
    fwrite(&numeros[i], sizeof(int), 1, out);
  }

  fclose(out);
  return 1;
}
