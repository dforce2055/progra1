#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(){
	FILE *ptrentrada, *ptrsalida;
	char cadena[256];
	int largo, i;
	
	ptrentrada = fopen("entrada.c", "r");
	ptrsalida = fopen("salida.c", "w");
	
	if(ptrentrada == NULL){
		printf("No se puede abrir el archivo de entrada");
		return 1;
		}
	if(ptrsalida == NULL){
		printf("No se puede crear el archivo de salida");
		return 1;
		}
	while(!feof(ptrentrada)){
		fgets(cadena, 256, ptrentrada);
		largo = strlen(cadena);
		
		for(i = 0; i < largo; i++){
			if(cadena[i] == '#'){
				cadena[i] = '\0';
				}
			}
		fputs(cadena, ptrsalida);
		}
	fclose(ptrentrada);
	fclose(ptrsalida);
	return 0;
	}
