#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

typedef struct n{
	int nro;
	struct n *siguiente;
}nodo, *pNodo;

typedef struct{
	pNodo inicio, fin;
}cola;

void menu(int *opc);
void inicializarCola(cola *pDada);
void acolar(cola *pDada, int n);
void imprimirCola(cola pDada);
int colaVacia(cola pDada);
void primero(cola pDada);
void desacolar(cola *pDada);

int main(void){
	cola dada;
	int numero, opcion, senal;
	
	do
	{
		menu(&opcion);
		switch(opcion)
		{
		case 1:
			inicializarCola(&dada);
			break;
		case 2:
			printf("Ingrese el numero a acolar: ");
			scanf("%d", &numero);
			while(numero!=-1)
			{
				acolar(&dada, numero);
				printf("Ingrese el numero a acolar: ");

				scanf("%d", &numero);
			}
			break;
		case 3:
				desacolar(&dada);
				break;
		case 4:
			primero(dada);
			break;
		case 5:
			senal=colaVacia(dada);
			if(senal==1)
				printf("\nLa cola esta vacia\n");
			else
				printf("\nLa cola NO esta vacia\n");
			break;
		case 6:
			imprimirCola(dada);
			break;
		}
	}while(opcion!=0);

}

void menu(int *opc){
	printf("\nIngrese Opcion:\n");
	printf("1. Inicializar Cola\n2. Acolar\n3. Desacolar\n4. Ver Primero\n5. Cola Vacia\n6. Ver Cola\n0. SALIR\n");
	printf("Ingrese opcion: ");
	scanf("%d", opc);
}

void inicializarCola(cola *pDada)
{
	pDada->inicio=pDada->fin=NULL;
}

void acolar(cola *pDada, int n)
{
	pNodo nuevo;
	nuevo=(nodo*)malloc(sizeof(nodo));
	if(nuevo==NULL)
		printf("\nNo hay memoria disponible en el sistema\n");
	else
	{
		nuevo->nro=n;
		nuevo->siguiente=NULL;
		if(pDada->inicio==NULL && pDada->fin==NULL)				//Si inicio y fin son NULL significa que la cola esta vacia
			pDada->inicio=pDada->fin=nuevo;
		else												//Si inicio y fin son iguales, significa que la cola tiene un solo nodo, entonces al nodo nuevo hay que acolarlo al final (del lado del puntero inicio)
		{
			nuevo->siguiente=pDada->inicio;
			pDada->inicio=nuevo;
		}
	}
}
void imprimirCola(cola pDada){
	pNodo aux;
	if(pDada.inicio==NULL && pDada.fin==NULL)
		printf("\nLa cola esta vacia\n");
	else
	{
		aux=pDada.inicio;
		while(aux!=NULL)
		{
			printf("%d\n", aux->nro);
			aux=aux->siguiente;
		}
	}
}

int colaVacia(cola pDada)
{
	if(pDada.inicio==NULL && pDada.fin==NULL)
		return 1;
	else
		return 0;
}

void primero(cola pDada){
	if(pDada.fin==NULL)
		printf("La cola esta vacia\n");
	else
		printf("\nEl primero es: %d", pDada.fin->nro);
}

void desacolar(cola *pDada)
{
	pNodo aux=pDada->inicio, anterior;

	while(aux->siguiente!=NULL)
	{
		anterior=aux;
		aux=aux->siguiente;
	}
		pDada->fin=anterior;
		pDada->fin->siguiente=NULL;
		free(aux);
		
}