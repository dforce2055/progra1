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
//int agregarAcumulado(tEnteros enteros, char *nombreArch, int numReg);
//int ordenarArch(char *nombreArch);
int main(){
  FILE *archivo;
  int i = 0;
  srand((int)time(NULL));
  //int enteros = {9,3,2,4,-1,5,0,0,7,6};

  if((archivo = fopen("enteros.dat","wb+")) == NULL){
	puts("Error al intentar abrir el archivo 'enteros.dat'.");
	return 1;
  }
  
  for(i = 0; i < 8; i++)
	  grabarArch(archivo, rand()%9);

  mostrarArch(archivo);
  agregarAcumulado(archivo);
  ordenarArch(archivo);
  puts("archivo ordenado");
  mostrarArch(archivo);
  
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
  fseek(archivo, 0, SEEK_CUR);//necesario para el cambio de actividad de lectura a escritura, no mueve el indicador de reg. activo
  fwrite(&enteros, sizeof(enteros), 1, archivo);
  printf("\nEl acumulado es %d\n", acum);
}
void ordenarArch(FILE *archivo){
  int i, j, entero1, entero2, cantReg = 0;
  
  fseek(archivo,0, SEEK_END);
  cantReg = ftell(archivo) / sizeof(int);
  rewind(archivo);
  
  for(i = 0; i < cantReg - 1; i++){
	  for(j = i +1; j < cantReg; j++){
		fread(&entero1,sizeof(int),1,archivo);
		fread(&entero2,sizeof(int),1,archivo);
		if(entero1 > entero2){
			fseek(archivo,-2 * (int)sizeof(int), SEEK_CUR);//CAST de el valor devuelto por sizeof()
			fwrite(&entero2, sizeof(int), 1, archivo);
			fwrite(&entero1, sizeof(int), 1, archivo);
		}
	  }
  }
}
