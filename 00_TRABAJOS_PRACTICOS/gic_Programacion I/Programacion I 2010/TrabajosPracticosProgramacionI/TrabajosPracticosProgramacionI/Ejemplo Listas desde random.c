/*HACER UN PROGRAMA QUE GENERE NUMEROS AL AZAR HASTA QUE APAREZCA UN NUMERO DADO, CADA NUMERO DEBE CARGARLO EN UN NODO DE UNA LISTA ENLAZADA, LUEGO ESA LISTA SE DEBE GUARDAR EN
ARCHIVO DE FORMA ORDENADA, Y TAMBIEN LEERLA DESDE EL ARCHIVO*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)

typedef struct n
{
	int nro;
	struct n *siguiente, *anterior;
}nodo, *pNodo;

typedef struct
{
	pNodo inicio;
}lista;

void inicializarLista(lista *pLista);
void agregarElementoLista(lista *pLista, int e);
void guardarArchivo(lista pLista);
void imprimirLista(lista pLista);
void cargadoArchivo(lista *pLista);
void ordenarLista(lista *pLista);

int main(void)
{
	lista dada;
	int nro, centinela;

	srand((unsigned int)time(NULL));

	inicializarLista(&dada);
	cargadoArchivo(&dada);
	imprimirLista(dada);
	//ordenarLista(&dada);
	printf("Ingrese el numero en donde parar: ");
	scanf("%d", &centinela);
	nro=rand()%(99-1+1)+1;
	while(nro!=centinela)
	{
		agregarElementoLista(&dada, nro);
		nro=rand()%(99-1+1)+1;
	}
	
	guardarArchivo(dada);
	imprimirLista(dada);


}

void inicializarLista(lista *pLista)
{
	pLista->inicio=NULL;
}

void agregarElementoLista(lista *pLista, int e)
{
	pNodo nuevo=(nodo *)malloc(sizeof(nodo));
	pNodo actual;

	nuevo->nro=e;

	if(nuevo==NULL)
		printf("No hay memoria disponible para crear un nodo\n");
	else
	{
		if(pLista->inicio==NULL)
		{
			pLista->inicio=nuevo;
			nuevo->anterior=NULL;
			nuevo->siguiente=NULL;
		}
		else
		{
			actual=pLista->inicio;
			if(actual->anterior==NULL && actual->siguiente==NULL)
			{
				if(nuevo->nro<actual->nro)
				{
					pLista->inicio=nuevo;
					nuevo->anterior=NULL;
					nuevo->siguiente=actual;
					actual->anterior=nuevo;
				}
				else
				{
					actual->siguiente=nuevo;
					nuevo->anterior=actual;
					nuevo->siguiente=NULL;
				}
			}
			else
			{
				while(actual!=NULL && actual->nro<nuevo->nro)
					actual=actual->siguiente;

				nuevo->anterior=actual->anterior;
				nuevo->siguiente=actual;
				actual->anterior=nuevo;
				nuevo->anterior->siguiente=nuevo;
				if(nuevo->anterior==NULL)
					pLista->inicio=nuevo;
			}
		}
	}
}

void guardarArchivo(lista pLista)
{
	FILE *pArch;
	pNodo elemento=pLista.inicio;
	
	pArch=fopen("ListaEnteros.txt", "wt");
	if(pArch==NULL)
		printf("No se pudo crear el archivo\n");
	else
	{
		while(elemento!=NULL)
		{
			fprintf(pArch, "%d\n", elemento->nro);
			elemento=elemento->siguiente;
		}
	}
}

void cargadoArchivo(lista *pLista)
{
	FILE *pArch;
	pNodo nuevo, actual;
	pArch=fopen("ListaEnteros.txt", "rt");
	if(pArch==NULL)
		printf("Error al leer el archivo\n");
	else
	{
		nuevo=(nodo*)malloc(sizeof(nodo));
		
		while(!feof(pArch))
		{
			fscanf(pArch, "%d\n", &nuevo->nro);
			if(pLista->inicio==NULL)
			{

				pLista->inicio=nuevo;
				nuevo->anterior=NULL;
				nuevo->siguiente=NULL;
				nuevo=(nodo*)malloc(sizeof(nodo));
			}
			else
			{
				actual=pLista->inicio;
				pLista->inicio=nuevo;
				nuevo->anterior=NULL;
				nuevo->siguiente=actual;
				actual->anterior=nuevo;
				nuevo=(nodo*)malloc(sizeof(nodo));
			}
		}
	}
}

void imprimirLista(lista pLista)
{
	/*pNodo actual=pLista.inicio;
	while(actual!=NULL)
	{
		printf("%4d", actual->nro);
		actual=actual->siguiente;
	}
	printf("\n");
	*/
	if(pLista.inicio!=NULL)
	{
		printf("%4d", pLista.inicio->nro);
		pLista.inicio=pLista.inicio->siguiente;
			imprimirLista(pLista);
	}

}

void ordenarLista(lista *pLista)
{
	pNodo actual=pLista->inicio;


	if(pLista->inicio!=NULL)
	{
		if(pLista->inicio->siguiente!=NULL)
		{
			while(actual->siguiente!=NULL)
			{
				if(actual->nro<actual->siguiente->nro)
				{
					actual->anterior=actual->siguiente;
					actual->siguiente=actual->siguiente->siguiente;
					actual->anterior->anterior=NULL;
					actual->anterior->siguiente=actual;
				}
				actual=actual->siguiente;
			}
		}
	}
}

