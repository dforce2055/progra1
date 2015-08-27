#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000
#pragma warning(disable:4996)

typedef struct{
	int dia, mes, anio;
}sfecha;

typedef struct{
	char nombre[20];
	float valor;
	int stock;
	sfecha fechaVencimiento;
}sproducto;

int alta(sproducto *l[], int cant);
int bajaProducto(sproducto *l[], int cant);
void imprimirLista(sproducto *l[], int cant);
void menu(int *opc);

int main(void){
	sproducto *lista[MAX];
	int cantidad=0, opcion;

	do
	{
		menu(&opcion);
		switch(opcion)
		{
		case 1:
			cantidad=alta(lista, cantidad);
			break;
		case 2:
			cantidad=bajaProducto(lista, cantidad);
			break;
		case 3:
			imprimirLista(lista, cantidad);
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

int alta(sproducto *l[], int cant){
	char aux[30];
	int longitud;

	fflush(stdin);
	fputs("\nIngrese el nombre del producto (vacio=Salir): ", stdout);
	gets(aux);
	longitud=strlen(aux);
	while(longitud!=0)
		{
			l[cant]=(sproducto *)malloc(sizeof(sproducto));
			if(l[cant]==NULL)
				printf("No hay memoria disponible\n");
			else{
				strcpy(l[cant]->nombre, aux);
				printf("Valor: $");
				scanf("%f", &l[cant]->valor);
				printf("Stock: ");
				scanf("%d", &l[cant]->stock);
				printf("Fecha de vencimiento (dd/mm/aaaa): ");
				scanf("%d/%d/%d", &l[cant]->fechaVencimiento.dia, &l[cant]->fechaVencimiento.mes, &l[cant]->fechaVencimiento.anio);
				cant++;
				fflush(stdin);
				fputs("Ingrese el nombre del producto: ", stdout);
				gets(aux);
				longitud=strlen(aux);
			}
	}
	return cant;
}

int bajaProducto(sproducto *l[], int cant){
	char nombre[30];
	int i;

	fflush(stdin);
	printf("Ingrese el nombre del producto a eliminar: ");
	gets(nombre);
	for(i=0; i<cant; i++){
		if(strcmp(l[i]->nombre, nombre)==0)
		{	
			free(l[i]);
			for(i; i<cant-1; i++)
				l[i]=l[i+1];
			cant--;
		}
	}

	return cant;
}
				
void imprimirLista(sproducto *l[], int cant)
{
	int i;
	if(cant==0)
		printf("\nLa lista de stock esta vacia, no hay productos para mostrar\n");
	else
		{
		printf("\n%-*s\t%s\t%s\t%s\n", 10, "Nombre", "Precio", "Stock", "Fecha Venc.");
		for(i=0; i<cant; i++){
			printf("%-*s\t$%-.2f\t%-d\t%-d/%-d/%-d\n", 10, l[i]->nombre, l[i]->valor, l[i]->stock, l[i]->fechaVencimiento.dia, l[i]->fechaVencimiento.mes, l[i]->fechaVencimiento.anio);
		}
	}
}


