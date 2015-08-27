#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXPRODUCTOS 1000
#define CODIGOPRODUCTO 15
#define NOMBRE 15
#pragma warning(disable:4996)

typedef struct
{
	int dia, mes, anio;
}sfecha;

typedef struct
{
	char codBarras[CODIGOPRODUCTO];
	char nombre[NOMBRE];
	float precio;
	int stock;
	sfecha fechaActualizacion;
}sproducto;

void menu(int *opc);
int altaProducto(sproducto l[], int cant);
int bajaProducto(sproducto l[], int cant);
void mostrarProductos(sproducto l[], int cant);
void imprimirCadena(char cad[], int n);
void eliminarEnter(char cad[]);

int main(void){
	sproducto lista[MAXPRODUCTOS];
	int cantidad=0, opcion;

	menu(&opcion);
	do{
	switch(opcion)
	{
	case 1:
		cantidad=altaProducto(lista, cantidad);
		break;
	case 2:
		cantidad=bajaProducto(lista, cantidad);
		break;
	case 3:
		mostrarProductos(lista, cantidad);
		break;
	}
	menu(&opcion);
	}while(opcion!=0);
}

void menu(int *opc){
	do{
		printf("\nMenu\n");
		printf("1. Alta de producto\n2. Baja de producto\n3. Mostrar Productos\n4. Cargar Archivo\n5. Guardar Archivo\n0. SALIR\nIngrese opcion: ");
		scanf("%d", opc);
		if(*opc<0 || *opc>5)
			printf("Opcion incorrecta\n");
	}while(*opc<0 || *opc>5);
}

int altaProducto(sproducto l[], int cant){
	char aux[NOMBRE];
	int longitud;

	fflush(stdin);
	printf("\nIngrese el nombre del producto: ");
	fgets(aux, NOMBRE, stdin);
	longitud=strlen(aux)-1;

	while(longitud!=0 && cant<1000)
	{
		strcpy(l[cant].nombre, aux);
		fflush(stdin);
		printf("Ingrese el codigo de barras: ");
		fgets(l[cant].codBarras, CODIGOPRODUCTO, stdin);
		fflush(stdin);
		printf("Ingrese el precio: ");
		scanf("%f", &l[cant].precio);
		printf("Ingrese el stock: ");
		scanf("%d", &l[cant].stock);
		printf("Ingrese la fecha (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &l[cant].fechaActualizacion.dia, &l[cant].fechaActualizacion.mes, &l[cant].fechaActualizacion.anio);
		cant++;
		fflush(stdin);
		printf("Ingrese el nombre del producto: ");
		fgets(aux, NOMBRE, stdin);
		longitud=strlen(aux)-1;
	}
	return cant;
}

int bajaProducto(sproducto l[], int cant){
	char nombre[NOMBRE];
	int i;
	
	printf("Ingrese el nombre del producto a eliminar: ");
	fflush(stdin);
	fgets(nombre, NOMBRE, stdin);
	for(i=0; i<cant; i++){
		if((strcmp(nombre, l[i].nombre))==0){
			for(i; i<cant; i++)
				l[i]=l[i+1];
			cant--;
		}
	}
	return cant;
}

void mostrarProductos(sproducto l[], int cant){
	int i;
	if(cant==0)
		printf("Lista de productos vacia\n");
	else{
	printf("%-*s %-*s\tPrecio\tStock\tFecha\n", NOMBRE, "Nombre", CODIGOPRODUCTO, "Codigo de Barras");
	for(i=0; i<cant; i++){
		eliminarEnter(l[i].nombre);
		imprimirCadena(l[i].nombre, NOMBRE);
		eliminarEnter(l[i].codBarras);
		imprimirCadena(l[i].codBarras, CODIGOPRODUCTO);
		printf("\t%.2f\t", l[i].precio);
		printf("%d\t", l[i].stock);
		printf("%.2d/%.2d/%.2d\n", l[i].fechaActualizacion.dia, l[i].fechaActualizacion.mes, l[i].fechaActualizacion.anio);
	}
	}
}

void imprimirCadena(char cad[], int n){
	//int longitud=strlen(cad)-1, i;
	//for(i=0; i<longitud; i++)
		printf("%-*s ", n, cad);
}

void eliminarEnter(char cad[]){
	int longitud=strlen(cad)-1;
	cad[longitud]='\0';
}
