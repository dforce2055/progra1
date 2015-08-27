#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable:4996)

typedef struct n{
	int nro;
	struct n *siguiente;
}nodo, *pNodo;

void menu(int *opc);
void inicializarPila(pNodo *ini);
void apilar(pNodo *ini, int n);
void tope(pNodo ini);
void desapilar(pNodo *ini);
void imprimirPila(pNodo ini);
int pilaVacia(pNodo ini);

int main(void){
	pNodo dada;
	int numero, opcion, senal;
	
	do
	{
		menu(&opcion);
		switch(opcion)
		{
		case 1:
			inicializarPila(&dada);
			break;
		case 2:
			printf("Ingrese el numero a apilar: ");
			scanf("%d", &numero);
			while(numero!=-1)
			{
				apilar(&dada, numero);
				printf("Ingrese el numero a apilar: ");

				scanf("%d", &numero);
			}
			break;
		case 3:
				desapilar(&dada);
				break;
		case 4:
			tope(dada);
			break;
		case 5:
			senal=pilaVacia(dada);
			if(senal==1)
				printf("\nLa pila esta vacia\n");
			else
				printf("\nLa pila NO esta vacia\n");
			break;
		case 6:
			imprimirPila(dada);
			break;
		}
	}while(opcion!=0);

}

void menu(int *opc){
	printf("\nIngrese Opcion:\n");
	printf("1. Inicializar Pila\n2. Apilar\n3. Desapilar\n4. Ver Tope\n5. Pila Vacia\n6. Ver Pila\n0. SALIR\n");
	printf("Ingrese opcion: ");
	scanf("%d", opc);
}

void inicializarPila(pNodo *ini){
	*ini=NULL;
	printf("La pila se inicializo OK\n");
}

void apilar(pNodo *ini, int n){
	pNodo nuevo;
	nuevo=(nodo*)malloc(sizeof(nodo));
	if(nuevo==NULL)
		printf("No hay memoria disponible\n");
	else
	{
		nuevo->nro=n;
		nuevo->siguiente=*ini;
		*ini=nuevo;
	}

}

int pilaVacia(pNodo ini){
	if(ini==NULL)
		return 1;
	else
		return 0;
}

void tope(pNodo ini){
	printf("\nTpe de pila: %d", ini->nro);
}

void desapilar(pNodo *ini){
	pNodo aux=*ini;
	*ini=aux->siguiente;
	free(aux);
}

void imprimirPila(pNodo ini){
	if(ini==NULL)
		printf("La pila esta vacia\n");
	else
	{
		printf("%d\n", ini->nro);
		while(ini!=NULL){
		ini=ini->siguiente;
		if(ini!=NULL)
		printf("%d\n", ini->nro);
		}
	}
}