/*
 * Hacer una funcion que devuelva la cantidad de palabras (separadas por uno o mas espacios) que tiene una frase
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void cadena_cant_palabras(char cadena[]);

int main(){
	char cadena[256];
	
	
	printf("Ingrese una cadena para determinar la cantidad de palabras\n");
	gets(cadena);
	cadena_cant_palabras(cadena);
	
	
	return 0;
	}
//Invertir cadena de caracteres
void cadena_cant_palabras(char cadena[]){
	int i, largo, espacios = 0, palabras = 0;
	
	largo = strlen(cadena);
	

	for(i = 0; i < largo; i++){
		if(isspace(cadena[i])){
			espacios++;
			}
		if(!isspace(cadena[i])){
				while(!isspace(cadena[i])){
					i++;
					}
				palabras++;
				i--;
				}
			}
	printf("\nLa cadena Tiene %d espacios y %d palabras:\n", espacios, palabras);
	
	for(i = 0; i < largo; i++){
		if(!isspace(cadena[i])){
			printf("%c", cadena[i]);
			}else{
				printf("\n");
				}
		}
	}
