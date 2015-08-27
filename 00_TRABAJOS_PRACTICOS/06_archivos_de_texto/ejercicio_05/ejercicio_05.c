/*
 * 
 * */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define ANCHO 3

void grabarMatriz(FILE *archivoSalida, char matriz[][ANCHO], int alto);
void leerMatriz(FILE *archivoEntrada, char matriz[][ANCHO], int alto);
void inicializarMatriz(char matriz[][ANCHO], int alto);
void mostrarMatriz(char matriz[][ANCHO], int alto);
void cargarMatriz(char matriz[][ANCHO], int alto);

int main(){
	char matriz[3][3] = {{'\0'}, {'\0'}};
	
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
	
	inicializarMatriz(matriz, 3);
	leerMatriz(ptrentrada, matriz, 3);
	mostrarMatriz(matriz, 3);
	
	
	
	
	return 0;
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

//Lee una matriz desde un arhivo de texto
void leerMatriz(FILE *archivoEntrada, char matriz[][ANCHO], int alto){
	int i = 0, j = 0, largo, linea[ANCHO];
	char cadena[10];
	
	while(!feof(archivoEntrada) && alto > 0){
		fgets(cadena, 10,archivoEntrada);
		largo = strlen(cadena);
		for(i = 0, j = 0; j < largo ||  i < ANCHO; j++){
			if(isdigit(cadena[j])){
				linea[i] = atoi(&cadena[j]);
				i++;
				}
			}
		/*if(alto != 0){
			matriz[linea[0]][linea[1]] = linea[2];
			alto--;
			}
		printf("\nL[%d]	C[%d]	Valor[%d]",linea[0], linea[1], linea[2] );
		printf("\nContenido de la matriz [%d]", matriz[linea[0]][linea[1]]);
		*/
		matriz[0][0] = linea[2];
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
			fprintf(archivoSalida, "%c,", matriz[i][j]);
			}
		fprintf(archivoSalida, "\n");
		}
	}


//Inicializar Matriz con valores
void inicializarMatriz(char matriz[][ANCHO], int alto){
	int i, j;
	char caracter = 'A';
	for(i = 0; i < alto; i++){
		for(j = 0; j < ANCHO; j++){
			//matriz[i][j] = caracter+j;
			matriz[i][j] = '.';
			}
		}
	}
