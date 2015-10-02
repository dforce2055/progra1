/* Leer 01.ejercicio.consigna.txt */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  int enteros[10];
}tEnteros;

int grabarArch(tEnteros enteros, char *nombreArch);
int mostrarArch(char *nombreArch);
int agregarAcumulado(tEnteros enteros, char *nombreArch);
int main(){
  tEnteros enteros = {0,1,2,3,4,5,6,7,8,9};



  if(grabarArch(enteros, "enteros.dat")){
    puts("Archivo guadado correctamente.");
    puts("Datos conenidos en el archivo:");
    puts("==============================");
    mostrarArch("enteros.dat");
  }
  agregarAcumulado(enteros, "enteros.dat");






  return 0;
}
int grabarArch(tEnteros enteros, char *nombreArch){
  FILE *archivo;
  archivo = fopen(nombreArch, "wb");

  if(archivo == NULL){
    puts("Error al intentar guardar el archivo");
    return 0;
  }

  fwrite(&enteros, sizeof(enteros), 1, archivo);
  fclose(archivo);
  return 1;
}
int mostrarArch(char *nombreArch){
  FILE *archivo;
  tEnteros enteros;
  int i;
  archivo = fopen(nombreArch,"rb");

  if(archivo == NULL){
    printf("Error al intentar leer el archivo %s\n", nombreArch);
    return 0;
  }

  fread(&enteros, sizeof(enteros), 1, archivo);
  while(!feof(archivo)){
    for(i = 0; i < 10; i++) printf("%2d", enteros.enteros[i]);
    printf("\n");
    fread(&enteros, sizeof(enteros), 1, archivo);
  }
  fclose(archivo);
  return 1;
}
int agregarAcumulado(tEnteros enteros, char *nombreArch){
  FILE *archivo, *archivo2, *archivo3;
  tEnteros aux;
  int i, acumulados = 0;

  archivo = fopen(nombreArch, "rb");
  archivo2 = fopen("acumulados.dat", "wb");
  archivo3 = fopen("acumulados.txt", "at");

  if(archivo == NULL){
    puts("Error al intentar guardar el archivo");
    return 0;
  }
  fread(&aux, sizeof(enteros), 1, archivo);
  while(!feof(archivo)){
    for(i = 0; i < 10; i++){
      acumulados = acumulados + aux.enteros[i];//guardo en acumulados la suma de los enteros guardados en la estructura
    }
    fwrite(&aux, sizeof(aux), 1, archivo2);//voy copiando en "acumulados.dat" lo que habia en "enteros.dat"
    fread(&aux, sizeof(enteros), 1, archivo);
  }
  //copio al final del archivo "enteros.dat" el acumulado
  fwrite(&acumulados, sizeof(acumulados), 1, archivo2);
  //guardo una copia en archivo de texto para control
  fprintf(archivo3,"%d\n", acumulados);
  system("mv acumulados.dat enteros.dat");//renombro acumulados -> enteros.dat
  fclose(archivo);
  fclose(archivo2);
  fclose(archivo3);
  return 1;
}
