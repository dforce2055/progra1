#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MAX 1000
#pragma warning(disable:4996)

typedef struct{
	int dia, mes, anio;
}sfecha;

typedef struct n{
	char nombre[20];
	float valor;
	int stock;
	sfecha fechaVencimiento;
	struct n *siguiente;
}nodo, *pNodo;

typedef struct
{
	pNodo inicio;
}lista;

void menu(int *opc);
void inicializarLista(lista *pLista);
int alta(lista *pLista);
void imprimirLista(lista pLista);
void bajaProducto(lista *pLista);

int main(void){
	lista dada;
	int opcion;

	inicializarLista(&dada);
	do
	{
		menu(&opcion);
		switch(opcion)
		{
		case 1:
			alta(&dada);
			break;
		case 2:
			bajaProducto(&dada);
			break;
		case 3:
			imprimirLista(dada);
			break;
		}
	}while(opcion!=0);
}

void menu(int *opc)
{
	do
	{
		printf("\nMenu\n");
		printf("1. Alta de producto\n2. Baja de producto\n3. Imprimir Lista\n0. SALIR\nIngrese opcion: ");
		scanf("%d", opc);
	}while(*opc<0 || *opc>3);
}

void inicializarLista(lista *pLista)
{
	pLista->inicio=NULL;
}

int alta(lista *pLista){
	pNodo nuevo, insertar, actual;
	char aux[30];
	int longitud;

	fflush(stdin);
	nuevo=(nodo*)malloc(sizeof(nodo));
	if(nuevo==NULL)
		printf("\nNo hay memoria disponible en el sistema\n");
	else
	{
		fputs("\nIngrese el nombre del producto (vacio=Salir): ", stdout);
		gets(aux);
		longitud=strlen(aux);
		while(longitud!=0)
			{
				strcpy(nuevo->nombre, aux);
				printf("Valor: $");
				scanf("%f", &nuevo->valor);
				printf("Stock: ");
				scanf("%d", &nuevo->stock);
				printf("Fecha de vencimiento (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &nuevo->fechaVencimiento.dia, &nuevo->fechaVencimiento.mes, &nuevo->fechaVencimiento.anio);
				fflush(stdin);
				if(pLista->inicio==NULL)
				{
					pLista->inicio=nuevo;
					nuevo->siguiente=NULL;
					return 0;
				}
				
				if(pLista->inicio->siguiente==NULL)
				{
					if(strcmp(nuevo->nombre, pLista->inicio->nombre)>0)
					{
						pLista->inicio->siguiente=nuevo;
						nuevo->siguiente=NULL;
						return 0;
					}
				}

				if(pLista->inicio->siguiente!=NULL)
				{
					insertar=pLista->inicio;
					while((strcmp(insertar->nombre, nuevo->nombre)<0) && (insertar->siguiente!=NULL))
					{
						actual=insertar;
						insertar=insertar->siguiente;
					}
					actual->siguiente=nuevo;
					nuevo->siguiente=insertar;
					nuevo=(nodo*)malloc(sizeof(nodo));
					return 0;
				}
		}
	}
	fflush(stdin);
	return 0;
}
		

void bajaProducto(lista *pLista){
	char nombre[30];
	pNodo actual, anterior;

	actual=pLista->inicio;

	fflush(stdin);
	printf("Ingrese el nombre del producto a eliminar: ");
	gets(nombre);
	while(actual!=NULL){
		if(strcmp(actual->nombre, nombre)==0)
		{	
			anterior->siguiente=actual->siguiente;
			free(actual);
		}
		else
		{
			anterior=actual;
			actual=actual->siguiente;
		}
	}
}
				
void imprimirLista(lista pLista)
{
	pNodo actual=pLista.inicio;

	if(pLista.inicio==NULL)
		printf("\nLa lista de stock esta vacia, no hay productos para mostrar\n");
	else
	{
		printf("\n%-*s\t%s\t%s\t%s\n", 10, "Nombre", "Precio", "Stock", "Fecha Venc.");
		while(actual!=NULL)
		{
			printf("%-*s\t$%-.2f\t%-d\t%-d/%-d/%-d\n", 10, actual->nombre, actual->valor, actual->stock, actual->fechaVencimiento.dia, actual->fechaVencimiento.mes, actual->fechaVencimiento.anio);
			actual=actual->siguiente;
		}
	}
}