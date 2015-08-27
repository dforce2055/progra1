#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct elementoLista{
	int numero;
	struct elementoLista *pSiguiente;
}nodo;

typedef struct listaIdentificar{
	nodo *inicio;
	nodo *fin;
	int tamanio;
}Lista;

void inicializarLista(Lista *lista);
int insertarEnListaVacia(Lista *lista, int nro);
int insertarInicioLista(Lista *lista, int nro);
int insertarFinLista(Lista *lista, nodo *actual, int nro);
void imprimirLista(Lista *lista);

int main(void){
	Lista listaEnlazada;
	int numero, resultado;
	
	inicializarLista(&listaEnlazada);
	resultado=insertarEnListaVacia(&listaEnlazada, 5);
	imprimirLista(&listaEnlazada);
	resultado=insertarInicioLista(&listaEnlazada, 3);
	//resultado=insertarFinLista(&listaEnlazada, 8);
	imprimirLista(&listaEnlazada);

	return 0;
}

void inicializarLista(Lista *lista){
	lista->tamanio=0;
	lista->inicio = lista->fin = NULL;
}

int insertarEnListaVacia(Lista *lista, int nro){
	nodo *nuevoNodo;
	nuevoNodo=(nodo *)malloc(sizeof(nodo));
	if(nuevoNodo==NULL)
	{
		printf("No hay memoria para agregar el nodo\n");
		return -1;
	}
	else
	{
		nuevoNodo->numero = nro;
		nuevoNodo->pSiguiente = NULL;
		lista->inicio = lista->fin = nuevoNodo;
		lista->tamanio++;
		return 0;
	}
}

int insertarInicioLista(Lista *lista, int nro){
	nodo *nuevoNodo;
	if((nuevoNodo=(nodo *)malloc(sizeof(nodo)))==NULL)
		return -1;
	else
	{
		nuevoNodo->pSiguiente = lista->inicio;
		lista->inicio = nuevoNodo;
		lista->tamanio++;
		return 0;
	}
}

int insertarFinLista(Lista *lista, nodo *actual, int nro){
	nodo *nuevoNodo;
	nuevoNodo=malloc(sizeof(nodo));
	if(nuevoNodo==NULL){
		printf("No hay espacio en memoria\n");
		return -1;
	}
	else
	{
		actual->pSiguiente = nuevoNodo;
		nuevoNodo->pSiguiente=NULL;

		lista->fin = nuevoNodo;
		lista->tamanio++;
		return 0;
	}
}
		
void imprimirLista(Lista *lista){
	nodo *actual;

	actual = lista->inicio;
	while(actual!=NULL){
		printf("%2d", &actual->numero);
		actual = actual->pSiguiente;
	}
}