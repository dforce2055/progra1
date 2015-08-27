/*
 * 
 * */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ANCHO 10

void grabarMatriz(FILE *archivoSalida, char matriz[][ANCHO], int alto);
void leerMatriz(FILE *archivoEntrada, char matriz[][ANCHO], int alto);
void inicializarMatriz(char matriz[][ANCHO], int alto);
void mostrarMatriz(char matriz[][ANCHO], int alto);
void cargarMatriz(char matriz[][ANCHO], int alto);

int main(){
	char matriz[10][ANCHO], matrizbackup[10][ANCHO] = {'\0'};
	
	FILE *ptrsalida, *ptrentrada;
	
	ptrsalida = fopen("salida.txt", "w");
	ptrentrada = fopen("entrada.txt", "r");
	
	if(ptrsalida == NULL){
		printf("No se pudo crear el archivo\n");
		return 1;
		}
	if(ptrentrada == NULL){
		printf("No se puede lee el archivo\n");
		return 1;
		}
	
	leerMatriz(ptrentrada, matrizbackup, 10);
	mostrarMatriz(matrizbackup, 10);
	
	
	
	
	return 0;
	}
//Inicializar Matriz con valores
void inicializarMatriz(char matriz[][ANCHO], int alto){
	int i, j;
	char caracter = 'A';
	for(i = 0; i < alto; i++){
		for(j = 0; j < ANCHO; j++){
			matriz[i][j] = caracter+j;
			}
		}
	}
//muestra la matriz por pantalla
void mostrarMatriz(char matriz[][ANCHO], int alto){
	int i, j;
	for(i = 0; i < alto; i++){
			for(j = 0; j < ANCHO; j++){
				printf("%3c", matriz[i][j]);
				}
			printf("\n");
			}
	}
//Cargar matriz
void cargarMatriz(char matriz[][ANCHO], int alto){
	int i, j;
	
	printf("Ingrese valores para la Matriz:\n"
			"********************************\n");
	for(i = 0; i < alto; i++){
		for(j = 0; j < ANCHO; j++){
			printf("Ingrese el valor [%d][%d]: ", i, j);
			scanf("\n%c", &matriz[i][j]);
			}
		}
	
	}
//Graba una matriz en un archivo de texto
void grabarMatriz(FILE *archivoSalida, char matriz[][ANCHO], int alto){
	int i,j;
	
	for(i = 0; i < alto; i++){
		for(j = 0; j < ANCHO; j++){
			fprintf(archivoSalida, "%3c", matriz[i][j]);
			}
		fprintf(archivoSalida, "\n");
		}
	}
//Lee una matriz desde un arhivo de texto
void leerMatriz(FILE *archivoEntrada, char matriz[][ANCHO], int alto){
	int i;
	
	while(!feof(archivoEntrada)){
		for(i = 0; i < alto; i++){
			fgets(matriz[i], ANCHO, archivoEntrada);
			
			}
		}
	}
