#include <stdio.h>
#define MAX 3
#pragma warning(disable:4996)

void leerMatrizArchivo(FILE *pf, int m[MAX][MAX]);
void imprimirMatriz(int m[MAX][MAX]);

int main(void)
{
	FILE *pMatriz;
	int matriz[MAX][MAX];
	
	pMatriz=fopen("Matriz.txt", "rt");
	if(pMatriz==NULL)
		printf("Error al leer el archivo\n");
	else{
		leerMatrizArchivo(pMatriz, matriz);
		imprimirMatriz(matriz);
	}
}

void leerMatrizArchivo(FILE *pf, int m[MAX][MAX]){
	int i,j;
	char caracter;
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++){
			caracter=fgetc(pf);
			fscanf(pf, "%d", &m[i][j]);
		}
		fgetc(pf);
		fgetc(pf);
	}
}

void imprimirMatriz(int m[MAX][MAX]){
	int i,j;
	printf("\n");
	for(i=0; i<MAX; i++){
		for(j=0; j<MAX; j++)
			printf("%4d", m[i][j]);
		printf("\n");
	}
	printf("\n");
}