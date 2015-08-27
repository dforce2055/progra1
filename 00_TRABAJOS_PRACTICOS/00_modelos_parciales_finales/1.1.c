/* 1er parcial - Punto 1 */
/*
 * 1- Escribir un programa para ingresar por teclado una cadena de caracteres cualquiera. Luego se deberan remover todos 
 * los caracteres repetidos de la misma. Asi "aaabbb" se convienvierte en "ab" y "abcbc" pasa a ser "abc". No utilizar
 * cadenas ni arreglos auxiliares, el tamaño de la cadena se considera suficiente.
*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 256
int main(){
	char cadena[SIZE];
	int i, j, largo;
	

	printf("Ingrese una frase:\n");
	fflush(stdin);
	gets(cadena);


	largo = strlen(cadena);
	
	//elimina repetidos poniendo la marca de *
	for(i = 0; i < largo; i++){
		for(j = i+1;j < largo; j++){
			if(cadena[i] == cadena[j] && cadena[i] != ' '){//respeta los espacios en blanco de la cadena
				cadena[j] = '*';
				} 
			}
		}
	//ordenar eliminando los caracteres *
	for(i = 0; i < largo; i++){
		if(cadena[i] == '*'){
			for(j = i; j < largo; j++){
				cadena[j] = cadena[j+1];
				}
			if(cadena[i] == '*'){
				i--;
				}
			
			}
		}

	printf("\nEL largo de la cadena es %d", largo);
	
	printf("\nSu frase sin repeticiones es:\n'%s'", cadena);
	largo = strlen(cadena);
	printf("\nEl nuevo largo es de %d", largo);

	
	return 0;
	}
