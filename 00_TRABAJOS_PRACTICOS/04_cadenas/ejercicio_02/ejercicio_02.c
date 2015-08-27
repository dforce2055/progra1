/*
 * Hacer una funcion que Determine si una secuencia de caracteres es capicua
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cadena_capicua(char cadena[]);

int main(){
	char cadena[256];
	
	printf("Ingrese una cadena para determinar si es capicua\n");
	scanf("%s", cadena);
	cadena_capicua(cadena);
	
	
	return 0;
	}
//Invertir cadena de caracteres
void cadena_capicua(char cadena[]){
	int i, j, largo, resultado;
	
	largo = strlen(cadena);
	
	for(i = 0, j = largo -1; i < j; i++, j--){
		if(cadena[i] != cadena[j]){
			resultado = 0;
			}
		}
	if(resultado != 0){
		printf("\nLa cadena es CAPICUA!");
		}else{
			printf("\nLa cadena NO ES CAPICUA!");
			}
	}
