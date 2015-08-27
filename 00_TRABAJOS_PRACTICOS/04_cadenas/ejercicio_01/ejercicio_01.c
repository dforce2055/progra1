/*
 * Hacer una funcion que permita invertir una secuencia de caracteres
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void invertir_cadena(char cadena[]);

int main(){
	char cadena[256];
	
	printf("Ingrese una cadena para que sea invertida:\n");
	scanf("%s", cadena);
	invertir_cadena(cadena);
	printf("Su cadena invertida es:\n");
	printf("%s", cadena);
	
	return 0;
	}
//Invertir cadena de caracteres
void invertir_cadena(char cadena[]){
	int i, j, largo;
	char almacen;
	
	largo = strlen(cadena);
	
	for(i = 0, j = largo -1; i < j; i++, j--){
		almacen = cadena[i];
		cadena[i] = cadena[j];
		cadena[j] = almacen;
		}
	}
