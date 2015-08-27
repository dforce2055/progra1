#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ZONA 10
#define DOMI 20
#define CATEGORIA 20
#define TELEFONO 15
#pragma warning (disable:4996)

typedef struct n
{
	char zona[ZONA];
	char domicilio[DOMI];
	char telefono[TELEFONO];
	int cantHabitaciones, cantBanios;
	int balcon, cochera;
	int antiguedad;
	float expensas;
	int precio;
	char categoria[CATEGORIA];
	struct n *siguiente, *anterior;
}nodo, *pNodo;

typedef struct
{
	pNodo inicio;
}lista;

void inicializarLista(lista *pList);
int listaVacia(lista pLista);
void altaInmueble(lista *pList);
void eliminarRetorno(char cad[]);
void guardadoArchivo(lista pLista);
void cargadoArchivo(lista *pLista);
void menu(int *opc);
void imprimirLista(lista pLista);
void imprimirCadena(char cad[]);
void imprimirdepto(nodo *depto);
void imprimirZona(lista pLista);

int main (void)
{
	lista dada;
	int opcion;

	inicializarLista(&dada);
	cargadoArchivo(&dada);
	menu(&opcion);
	do
	{
		switch(opcion)
		{
		case 1:
			altaInmueble(&dada);
			break;
		case 2:
			imprimirLista(dada);
			break;
		case 3:
			imprimirZona(dada);
			break;
		}
		menu(&opcion);
	}while(opcion!=0);

	guardadoArchivo(dada);

}

void inicializarLista(lista *pList)
{
	pList->inicio=NULL;
}

int listaVacia(lista pLista)
{
	if(pLista.inicio==NULL)
		return 1;
	else
		return 0;
}

void altaInmueble(lista *pList)
{
	pNodo alta, actual;

	alta=(nodo*)malloc(sizeof(nodo));

	fflush(stdin);
	printf("\nIngrese los datos solicitados:\n");
	printf("Zona: ");
	fgets(alta->zona, ZONA, stdin);
	eliminarRetorno(alta->zona);
	fflush(stdin);
	printf("Domicilio: ");
	fgets(alta->domicilio, DOMI, stdin);
	eliminarRetorno(alta->domicilio);
	fflush(stdin);
	printf("Telefono: ");
	fgets(alta->telefono, TELEFONO, stdin);
	eliminarRetorno(alta->telefono);
	printf("Cantidad de habitaciones: ");
	scanf("%d", &alta->cantHabitaciones);
	printf("Cantidad de Banios: ");
	scanf("%d", &alta->cantBanios);
	printf("Tiene balcon (1=SI, 0=NO): ");
	scanf("%d", &alta->balcon);
	printf("Tiene cochera (1=SI, 0=NO): ");
	scanf("%d", &alta->cochera);
	printf("Antiguedad del edificio: ");
	scanf("%d", &alta->antiguedad);
	printf("Monto de expensas: ");
	scanf("%f", &alta->expensas);
	printf("Precio: ");
	scanf("%d", &alta->precio);
	fflush(stdin);
	printf("Categoria: ");
	fgets(alta->categoria, CATEGORIA, stdin);
	eliminarRetorno(alta->categoria);

	if(pList->inicio==NULL)
	{
		alta->siguiente=NULL;
		alta->anterior=NULL;
		pList->inicio=alta;
	}
	else
	{
		actual=pList->inicio;
		actual->anterior=alta;
		alta->anterior=NULL;
		alta->siguiente=actual;
		pList->inicio=alta;
	}

	
}

void eliminarRetorno(char cad[])
{
	int longitud=strlen(cad)-1;
	cad[longitud]='\0';
}

void guardadoArchivo(lista pLista)
{
	FILE *archivo;
	pNodo actual=pLista.inicio;

	archivo=fopen("Deptos.txt", "wt");
	if(archivo==NULL)
		printf("Error al crear el archivo, se cancela el guardado\n");
	else
	{
		if(pLista.inicio==NULL)
			printf("La lista esta vacia\n");
		else
		{
			while(actual!=NULL)
			{
				fprintf(archivo, "%s\n", actual->zona);
				fprintf(archivo, "%s\n", actual->domicilio);
				fprintf(archivo, "%s\n", actual->telefono);
				fprintf(archivo, "%d\n", actual->cantHabitaciones);
				fprintf(archivo, "%d\n", actual->cantBanios);
				fprintf(archivo,"%d\n", actual->balcon);
				fprintf(archivo,"%d\n", actual->cochera);
				fprintf(archivo,"%d\n", actual->antiguedad);
				fprintf(archivo,"%f\n", actual->expensas);
				fprintf(archivo,"%d\n", actual->precio);
				fprintf(archivo, "%s\n\n", actual->categoria);
				
				actual=actual->siguiente;
			}
		}
	}
	fclose(archivo);
}

void cargadoArchivo(lista *pLista)
{
	pNodo nuevo, actual;
	
	FILE *archivo;

	archivo=fopen("Deptos.txt", "rb");
	if(archivo==NULL)
		printf("No se pudo cargar el archivo desde el disco\n");
	else
	{
		while(!feof(archivo))
		{
			nuevo=(nodo*)malloc(sizeof(nodo));
			if(nuevo==NULL)
				printf("No hay memoria disponible\n");
			else
			{
				fscanf(archivo, "%s\n", &nuevo->zona);
				fgets(nuevo->domicilio,DOMI, archivo);
				fscanf(archivo, "%s\n", &nuevo->telefono);
				fscanf(archivo, "%d\n", &nuevo->cantHabitaciones);
				fscanf(archivo, "%d\n", &nuevo->cantBanios);
				fscanf(archivo,"%d\n", &nuevo->balcon);
				fscanf(archivo,"%d\n", &nuevo->cochera);
				fscanf(archivo,"%d\n", &nuevo->antiguedad);
				fscanf(archivo,"%f\n", &nuevo->expensas);
				fscanf(archivo,"%d\n", &nuevo->precio);
				fscanf(archivo, "%s\n\n", &nuevo->categoria);
				if(pLista->inicio==NULL)
				{
					nuevo->siguiente=NULL;
					nuevo->anterior=NULL;
					pLista->inicio=nuevo;
				}
				else
				{
					actual=pLista->inicio;
					actual->anterior=nuevo;
					nuevo->anterior=NULL;
					nuevo->siguiente=actual;
					pLista->inicio=nuevo;
				}
			}
		}
		fclose(archivo);
	}
}

void menu(int *opc)
{
	printf("\nMENU\n");
	printf("1. Alta depto\n2. Imprimir deptos\n3. Imprimir Zona\nIngrese opcion (0=SALIR): ");
	scanf("%d", opc);
}

void imprimirLista(lista pLista)
{
	if(pLista.inicio==NULL)
		printf("No hay departamentos para mostrar\n");
	else
	{
		printf("\nLista de departamentos Completa\n");
		while(pLista.inicio!=NULL)
		{
			printf("\nZona: ");
			imprimirCadena(pLista.inicio->zona);

			printf("\nDomicilio: ");
			imprimirCadena(pLista.inicio->domicilio);

			printf("Telefono: ");
			imprimirCadena(pLista.inicio->telefono);
			printf("\nHabitaciones: %d\tBanios: %d", pLista.inicio->cantHabitaciones, pLista.inicio->cantBanios);
			printf("\nBalcon: ");
			if(pLista.inicio->balcon==1)
				printf("Si");
			else
				printf("No");
			printf("\tCochera: ");
			if(pLista.inicio->cochera==1)
				printf("Si");
			else
				printf("No");
			printf("\nAntiguedad: %d", pLista.inicio->antiguedad);
			printf("\nExpensas: $%.2f\tValor Inmueble: $%d", pLista.inicio->expensas, pLista.inicio->precio);
			printf("\nCategoria: ");
			imprimirCadena(pLista.inicio->categoria);
			printf("\n");
			pLista.inicio=pLista.inicio->siguiente;
		}
	}
}

void imprimirCadena(char cad[])
{
	int longitud=strlen(cad), i;

	for(i=0; i<longitud; i++)
		putc(cad[i], stdout);
}

void imprimirdepto(nodo *depto)
{
			printf("\nZona: ");
			imprimirCadena(depto->zona);

			printf("\nDomicilio: ");
			imprimirCadena(depto->domicilio);

			printf("Telefono: ");
			imprimirCadena(depto->telefono);
			printf("\nHabitaciones: %d\tBanios: %d", depto->cantHabitaciones, depto->cantBanios);
			printf("\nBalcon: ");
			if(depto->balcon==1)
				printf("Si");
			else
				printf("No");
			printf("\tCochera: ");
			if(depto->cochera==1)
				printf("Si");
			else
				printf("No");
			printf("\nAntiguedad: %d", depto->antiguedad);
			printf("\nExpensas: $%.2f\tValor Inmueble: $%d", depto->expensas, depto->precio);
			printf("\nCategoria: ");
			imprimirCadena(depto->categoria);
			printf("\n");
			depto=depto->siguiente;
}

void imprimirZona(lista pLista)
{
	char zona[ZONA];
	pNodo imprimir;
	imprimir=pLista.inicio;

	fflush(stdin);
	printf("Ingrese la zona de los deptos que desea ver: ");
	fgets(zona, ZONA, stdin);
	while(imprimir!=NULL)
	{
		if(strcmp(imprimir->zona, zona)==0)
		{
			imprimirdepto(imprimir);
			imprimir=imprimir->siguiente;
		}
		imprimir=imprimir->siguiente;
	}
}
