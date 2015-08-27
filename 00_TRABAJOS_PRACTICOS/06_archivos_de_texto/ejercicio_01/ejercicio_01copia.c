/*
 *1.	Hacer una función que permita eliminar todos los comentarios de una o varias líneas de un programa fuente escrito en lenguaje “C”,.
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)
int main(){
	FILE *entrada, *salida;
	char cadena[256];
	int i, j, corte = 0, largo;

	entrada = fopen("entrada.c", "rt");
	salida = fopen("salida.c", "wt");
	
	if(entrada == NULL){
		puts("No se pudo abrir el archivo");
		return 1;
		}
	if(salida == NULL){
		puts("No se pudo abrir el archivo");
		return 1;
		}

	//analiza los tipos de comentario con "//"
	while(!feof(entrada)){
		fgets(cadena, 256, entrada);
		largo = strlen(cadena);
		
		for(i = 0; i < 256; i++){
			if(cadena[i] == '/' && cadena[i+1] == '/'){
				cadena[i] = '\n';
				cadena[i+1] = '\0';				
				}
			}//fin del for
		for(i = 0; i < largo; i++){
			if(cadena[i] == '/' && cadena[i+1] == '*'){
				j = i;
				corte = 1;
				while(cadena[j] != '*' && cadena[j+1] != '/' && i <= largo){
					j++;
					}
				}
			if(cadena[j] == '*' && cadena[j+1] == '/'){
					cadena[i] = '\0';
					corte = 0;
					
				}
			if(corte == 1){
				j++;
				}
			}
		
		fputs(cadena, salida);
		}//fin del while	

	fclose(entrada);
	fclose(salida);

	return 0;
}
