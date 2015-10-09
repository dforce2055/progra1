/* Leer 01.ejercicio.consigna.txt */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void grabarArch(FILE *archivo, int entero);
void mostrarArch(FILE *archivo);
void agregarAcumulado(FILE *archivo);
void ordenarArch(FILE *archivo);
  int leerRegistro(FILE *archivo, int numReg);
  void grabarRegistro(FILE *archivo, int numReg, int valor);
int buscarArch(FILE *archivo, int buscado);

int main(){
  FILE *archivo;
  int i = 0, pos = -1;
  srand((int)time(NULL));//numeros aleatorios
  //int enteros = {9,3,2,4,-1,5,0,0,7,6};

  if((archivo = fopen("enteros.dat","wb+")) == NULL){
  puts("Error al intentar abrir el archivo 'enteros.dat'.");
  return 1;
  }

  /*for(i = 0; i < 8; i++)
    grabarArch(archivo, rand()%9);*/
  grabarArch(archivo, 1);
  grabarArch(archivo, 2);
  grabarArch(archivo, 3);
  grabarArch(archivo, 4);
  grabarArch(archivo, 5);

  mostrarArch(archivo);
  //agregarAcumulado(archivo);
  ordenarArch(archivo);
  puts("archivo ordenado");
  mostrarArch(archivo);

  pos = buscarArch(archivo, 4);
  puts("\nNº buscado '4'");
  if(pos != -1) printf("### Encontrado en la posicion: %d###\n", pos);
  else puts("No se encontro el numero.");

  fclose(archivo);
  return 0;
}
void grabarArch(FILE *archivo, int entero){
  fwrite(&entero, sizeof(int), 1, archivo);
}
void mostrarArch(FILE *archivo){
  int enteros = 0;
  int i = 0;

  rewind(archivo);
  fread(&enteros, sizeof(int), 1, archivo);
  while(!feof(archivo)){
    i++;
  printf("%d\t", enteros);
    fread(&enteros, sizeof(enteros), 1, archivo);
  if(0 == i % 8)
    printf("\n");
  }
}
void agregarAcumulado(FILE *archivo){
  //Rebice un archivo de enteros en estructuras, suma el valor de cada entero
  //y agrega el resultado al final
  int enteros = 0;
  int acum = 0, i = 0;
  rewind(archivo);
  fread(&enteros, sizeof(int), 1, archivo);
  while(!feof(archivo)){
    acum = acum + enteros;
  fread(&enteros, sizeof(enteros), 1, archivo);
  }
  //fseek(archivo, 0, SEEK_SET);//necesario para el cambio de actividad de lectura a escritura, no mueve el indicador de reg. activo
  fwrite(&acum, sizeof(enteros), 1, archivo);
  printf("\nEl acumulado es %d\n", acum);
}
void ordenarArch(FILE *archivo){
  int i, j, entero1, entero2, cantReg = 0;

  fseek(archivo,0, SEEK_END);
  cantReg = ftell(archivo) / sizeof(int);

  for(i = 0; i < cantReg - 1; i++){
    for(j = i +1; j < cantReg; j++){
      entero1 = leerRegistro(archivo, i);
      entero2 = leerRegistro(archivo, j);
      if(entero1 > entero2){
        grabarRegistro(archivo, i, entero2);
        grabarRegistro(archivo, j, entero1);
      }
    }
  }
}
int leerRegistro(FILE *archivo, int numReg){
  int dato;
  fseek(archivo, numReg * sizeof(int), SEEK_SET);
  fread(&dato, sizeof(int), 1, archivo);
  return dato;
}
void grabarRegistro(FILE *archivo, int numReg, int valor){
  fseek(archivo, numReg * sizeof(int), SEEK_SET);
  fwrite(&valor, sizeof(int), 1, archivo);
}
int buscarArch(FILE *archivo, int buscado){
  //Búsqueda binaria, mejora notable mente el rendimiento
  //Requisito, archivo con registros ordenados
  //De encontrar a buscado retorna la posición
  //Sino retorna -1
  int inf = 0, sup = 0, centro = 0, cantReg = 0, contCentro = 0;

  fseek(archivo, 0, SEEK_END);
  cantReg = ftell(archivo) / sizeof(int);
  rewind(archivo);

  sup = cantReg - 1;

  printf("CantReg: %d", cantReg);
  while(inf <= sup){
    centro = ((inf + sup) / 2) * 1.5; //
    contCentro = leerRegistro(archivo, centro);//guardo el valor del centro para comparar con buscado
    printf("\ncentro:%d", centro);
    printf("\tcontCentro:%d", contCentro);
    if(contCentro == buscado)                                  return centro;
    else if(contCentro < buscado)                              inf = centro -1;
    else                                                       sup = centro +1;
  }
  return -1;
}
