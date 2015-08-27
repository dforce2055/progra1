#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LOTE 5
#define CODIGOBARRAS 21
#define NOMBRE 40
#pragma warning (disable:4996)

typedef struct{
	int mes, anio;
}sfecha;

typedef struct{
	char lote[LOTE];
	char codigoBarras[CODIGOBARRAS];
	char nombre[NOMBRE];
	float costo;
	int stock;
	sfecha vencimiento;
}smedicamento;

int altaLote(smedicamento l[], int cant);
void eliminarRetorno(char cad[]);
void cargaFecha(sfecha fec);

int main(void)
{




	return 0;
}

void eliminarRetorno(char cad[]){
	int longitud=strlen(cad)-1;
	cad[longitud]='\n';
}

void cargaFecha(sfecha fec){
	printf("Mes y anio (mm/aaaa): ");
	scanf("%d/%d", &fec.mes, &fec.anio);
}

int altaLote(smedicamento l[], int cant){
	printf("Ingrese los siguientes datos:\n");
	printf("Lote: ");
	fgets(l[cant].lote, LOTE, stdin);
	eliminarRetorno(l[cant].lote);
	printf("Codigo de barras: ");
	fgets(l[cant].codigoBarras, CODIGOBARRAS, stdin);
	eliminarRetorno(l[cant].codigoBarras);
	printf("Nombre: ");
	fgets(l[cant].nombre, NOMBRE, stdin);
	eliminarRetorno(l[cant].nombre);
	printf("Costo: ");
	scanf("%f", &l[cant].costo);
	printf("Stock: ");
	scanf("%d", &l[cant].stock);
	cargaFecha(l[cant].vencimiento);
	cant++;
	return 0;
}