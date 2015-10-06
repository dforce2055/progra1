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
int ordenarArch(char *nombreArch);
int main(){
  tEnteros enteros = {9,3,2,4,-1,5,0,0,7,6};



  if(grabarArch(enteros, "enteros.dat")){
    puts("Archivo guadado correctamente.");
    puts("Datos contenidos en el archivo:");
    puts("==============================");
    //mostrarArch("enteros.dat");
    puts("Ordenado:");
    ordenarArch("enteros.dat");
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

  if(archivo == NULL || archivo2 == NULL || archivo3 == NULL){
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
  //fwrite(&acumulados, sizeof(int), 1, archivo3);
  system("mv acumulados.dat enteros.dat");//renombro acumulados -> enteros.dat
  fclose(archivo);
  fclose(archivo2);
  fclose(archivo3);
  return 1;
}
int ordenarArch(char *nombreArch){
  FILE *archivo;
  int reg1, reg2, j, i, cantReg = 0;

  if((archivo = fopen(nombreArch, "rb+")) == NULL)
    puts("Error al ordenar archivo");
    return 0;
  rewind(archivo);
  fseek(archivo, 0, SEEK_END);
  cantReg = ftell(archivo) / sizeof(int);
  for(i = 0; i < cantReg; i++){
    for(j = i +1; j < cantReg -1; j++){
      fread(&reg1, sizeof(int) * i, 1, archivo);
      fread(&reg2, sizeof(int) * j, 1, archivo);
      if(reg1 > reg2){
        fseek(archivo, sizeof(int) * i, SEEK_SET);
        fwrite(&reg1, sizeof(int), 1, archivo);
        fwrite(&reg2, sizeof(int), 1, archivo);
      }
    }
  }
  return 1;
}
