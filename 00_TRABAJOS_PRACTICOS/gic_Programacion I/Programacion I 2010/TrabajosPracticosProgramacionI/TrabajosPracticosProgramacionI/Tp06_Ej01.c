#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#pragma warning(disable:4996)

void menu(int *opc);
void grabarArch();
void mostrarArchivo();
void agregarAcumulado();
void ordenarArchivo();
long int sizeFile(FILE *pf);
long int buscarArch(FILE *ptr, int v);

int main(void)
{
	FILE *archivo;
	int opcion, nro;
	long int posicion;

	srand((unsigned int)time(NULL));
	
	do{
		menu(&opcion);
		switch(opcion){
			case 1:
				grabarArch();
				break;
			case 2:
				mostrarArchivo();
				break;
			case 3:
				agregarAcumulado();
				break;
			case 4:
				ordenarArchivo();
				break;
			case 5:
				archivo=fopen("Enteros.dat", "rb");
				if(archivo==NULL)
					printf("Error al leer el archivo\n");
				else{
					printf("Ingrese el numero a buscar: ");
					scanf("%d", &nro);
					posicion=buscarArch(archivo, nro);
					if(posicion==-1)
						printf("No se encontro el valor en el archivo\n");
					else
						printf("%d\n", posicion);
					fclose(archivo);
				}
				break;
		}
	}while(opcion!=0);
}

void menu(int *opc){
	do{
		printf("\nMenu\n");
		printf("1. Grabar Archivo Azar\n2. Mostrar Archivo Azar\n3. Agregar Acumulado\n4. Ordenar Archivo\n5. Buscar Archivo\n0. SALIR\nIngrese opcion: ");
		scanf("%d", opc);
		if(*opc<0 || *opc>5)
			printf("Opcion incorrecta\n");
	}while(*opc<0 || *opc>5);
}

void grabarArch(){
	FILE *ptr;
	int i, nro;

	ptr=fopen("Enteros.dat", "wb");
	if(ptr==NULL)
		printf("Error al crear el archivo\n");
	else
	{
		for(i=0; i<MAX; i++){
			nro=rand()%(99-1-1)+1;
			printf("%4d", nro);
			fwrite(&nro, sizeof(nro), 1, ptr);
		}
		printf("\n");
	}
	fclose(ptr);
}

void mostrarArchivo(){
	FILE *ptr;
	int nro;
	
	ptr=fopen("Enteros.dat", "rb");
	if(ptr==NULL)
		printf("Error al leer los datos desde el archivo\n");
	else
	{
		fread(&nro, sizeof(int), 1, ptr);
		while(!feof(ptr)){
			printf("%4d", nro);
			fread(&nro, sizeof(int), 1, ptr);
		}
	}
	printf("\n");
}

void agregarAcumulado(){
	FILE *ptr;
	int total=0, nro;
	
	ptr=fopen("Enteros.dat", "rb");
	if(ptr==NULL)
		printf("Error al leer el archivo\n");
	else{
	fread(&nro, sizeof(nro), 1, ptr);
	while(!feof(ptr)){
		total+=nro;
		fread(&nro, sizeof(nro), 1, ptr);
	}
	fclose(ptr);
	ptr=fopen("Enteros.dat", "ab");
	if(ptr==NULL)
		printf("Error al abrir el archivo\n");
	else{
		fwrite(&total, sizeof(total), 1, ptr);
		printf("Agregado acumulado correctamente\n");
	}

	fclose(ptr);
	}
}

void ordenarArchivo(){
	FILE *ptr;
	long int i, j, tamanio;
	int nro1, nro2, rc;

	ptr=fopen("Enteros.dat", "r+b");
	if(ptr==NULL)
		printf("Error al leer el archivo\n");
	else
	{
		tamanio=sizeFile(ptr)/sizeof(int);
		for(i=1; i<tamanio; i++){
			for(j=0; j<tamanio-i; j++)
			{
				rc=fseek(ptr, j*sizeof(int), SEEK_SET);
				fread(&nro1, sizeof(int), 1, ptr);
				fread(&nro2, sizeof(int), 1, ptr);
				if(nro1>nro2){
					rc=fseek(ptr, j*sizeof(int), SEEK_SET);
					fwrite(&nro2, sizeof(int), 1, ptr);
					fwrite(&nro1, sizeof(int), 1, ptr);
				}
			}
		}
	}
	fclose(ptr);

}

long int sizeFile(FILE *pf){
	long int actual, total;

	actual=ftell(pf);
	fseek(pf, 0L, SEEK_END);
	total=ftell(pf);
	fseek(pf, actual, SEEK_SET);
	return total;
}

long int buscarArch(FILE *ptr, int v)
{
	long int tamanio, i;
	int numero;
	tamanio=sizeFile(ptr)/sizeof(int);

	for(i=0; i<tamanio-1; i++){
		fread(&numero, sizeof(int), 1, ptr);
		if(numero==v)
			return ftell(ptr);
	}
	return -1;
}