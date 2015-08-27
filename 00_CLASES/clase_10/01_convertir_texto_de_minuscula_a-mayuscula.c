/*
 * Programa para leer un archivo de texto y grabarlo en otro dentino
 * */
#include <stdio.h>
#include <ctype.h>

int main(){
	FILE *entrada, *salida;
	char c;
	
	entrada = fopen("notas.txt", "rt");
	if(entrada == NULL){
		puts("No se puede abrir NOTAS.TXT");
		return 1;
		}
	
	salida = fopen("notas2.txt", "wt");
	if(salida == NULL){
		puts("No se puede crear NOTAS2.TXT");
		fclose(entrada);
		return 1;
		}
	
	c = fgetc(entrada);
	while(!feof(entrada)){
		fputc(toupper(c), salida);
		c = fgetc(entrada);
		}
	
	fclose(entrada);
	fclose(salida);
	
	return 0;
	}
