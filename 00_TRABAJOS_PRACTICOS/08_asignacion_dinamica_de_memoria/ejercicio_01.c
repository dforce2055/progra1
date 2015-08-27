/*
 * Asignacion dinamica de memoria - Ejercicio 01
 * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 1000

//estructuras
struct nodoProducto{
	char descripcion[20];
	int cantidad;
	struct nodoProducto *ptrSiguiente;
	};

typedef struct nodoProducto NodoProducto;
typedef NodoProducto *ptrNodoProducto;

//prototipos de las funciones
void menu(void);
void mostrarProductos(ptrNodoProducto * vector[]);
void altaProd(ptrNodoProducto vector[], int cargados, char descripcion[], int cantidad);
void bajaProd(ptrNodoProducto vector[], int cargados, char descripcion[]);



int main(){
	ptrNodoProducto vector[SIZE] ;
	int opcion, cantidad, cargados = 0;
	char descripcion[20];
	
	menu();
	scanf("%d", &opcion);
	while(opcion != 4){
		switch(opcion){
			//Alta de producto
			case 1:
				printf("Ingrese la descripcion del producto: ");
				scanf("\n%s", descripcion);
				printf("\nIngrese la cantidad: ");
				scanf("%d", &cantidad);
				altaProd(vector, cargados, descripcion, cantidad);
				mostrarProductos(vector);
				break;
			//Baja del producto
			case 2:
				printf("Ingrese el Producto que desea dar de baja\n");
				scanf("\n%s", descripcion);
				bajaProd(vector, cargados, descripcion);
				break;
			//Mostrar Listado de Productos
			case 3:
				printf("Listado de Productos:\n"
						"***********************\n");
				mostrarProductos(vector);
				break;
			default:
				printf("Opcion invalida\n");
				break;
			}
		menu();
		scanf("%d", &opcion);
		}
	printf("Fin del programa\n");
	
	return 0;
	}
//Mostrar Menu de opciones
void menu(void){
	printf("Elija una de las opciones:\n"
			"1- Alta de Producto\n"
			"2- Baja de Producto\n"
			"3- Mostrar Productos\n"
			"4- Salir del programa\n");
	}

//mostrar lista de productos
void mostrarProductos(ptrNodoProducto vector[]){
	int i ;
	if(vector[0] == '\0'){
		printf("Hasta el momento no hay ningun producto cargado\n");
		}
	for(i = 0; i < SIZE && vector[i] != '\0'; i++){
		printf("\nDescripcion: %s Cantidad: %4d", (vector[i])->descripcion, (vector[i])->cantidad);
		}
	
	}

//Alta de productos
void altaProd(ptrNodoProducto vector[], int cargados, char descripcion[], int cantidad){
	ptrNodoProducto ptrNuevo;											//apuntador a un nuevo nodo
	
	ptrNuevo = malloc(sizeof(NodoProducto));							//crea nuevo nodo
	
	if(ptrNuevo != NULL){
		strcpy(ptrNuevo->descripcion, descripcion);
		ptrNuevo->cantidad = cantidad;
		ptrNuevo->ptrSiguiente = NULL;									//el nodo no se liga a ningun nodo
		cantidad++;														//sumo 1 para correr el apuntador a estructura
		
		if(cantidad < SIZE && descripcion != '\0'){						//si no llego al final del vec y la cadena no esta vacia
			vector[cantidad] = ptrNuevo;
			}
		if(cantidad > SIZE){
			printf("Se alcanzo el maximo de productos");
			}
		if(descripcion == '\0'){
			printf("Ingreso una cadena vacia. Fin de la carga");
			}
	}else{
		printf("No existe memoria suficiente");
		}
	
	}

//Baja de producto
void bajaProd(ptrNodoProducto vector[], int cargados, char descripcion[]){
	int i = 0;															//variable para recorrer el vector
	
	if((vector[0] != '\0')){
		while(i < cargados && (vector[i])->descripcion != descripcion){	//reccorre todo el vector hasta encontrar el producto o hasta llegar al final
			i++;
			}
		
		if(i >= cargados){													//si el vector llego al final sin encontrar el producto
			printf("Producto no encontrado\n");
			}
		if((vector[i])->descripcion == descripcion){						//si encontro el producto, lo elimina del vector
			free(vector[i]);
			printf("Producto: %s, eliminado\n", descripcion);
			
			while(i < cargados && i < SIZE-1){								//reacomoda el vector, trayendo los valores , hasta llegar al ultimo cargado
				vector[i] = vector[i+1];
				}
			}
		}else{
			printf("La lista de productos esta vacia\n");
			}
	}
