/*
 * Hacer una funcion que permita reemplazar en una secuencia de caracteres 
 * todos los guiones(-) y reemplazarlos por el caracter numeral (#)
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cadena_reemplazar_guiones(char cadena[]);

int main(){
	char cadena[256];
	
	
	printf("Ingrese una cadena\n");
	gets(cadena);
	cadena_reemplazar_guiones(cadena);
	printf("\n%s", cadena);
	
	
	return 0;
	}
//Invertir cadena de caracteres
void cadena_reemplazar_guiones(char cadena[]){
	int i, largo;
	
	largo = strlen(cadena);
	
	for(i = 0; i < largo; i++){
		if(cadena[i] == '-'){
			cadena[i] = '#';
			}
		}
	}
