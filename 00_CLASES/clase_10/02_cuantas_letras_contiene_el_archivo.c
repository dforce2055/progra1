/*
 * Programa para determinar cuantas letras contiene de cada tipo, sin distinguir mayusculas de minusculas
 * */
#include <stdio.h>
#include <ctype.h>
int main(){
	FILE *archivo;
	
	char cadena[256], c;
	int i, v[26] = {0};
	
	archivo = fopen("notas.txt", "rt");
	if(archivo == NULL){
		puts("No se pudo abrir el archivo NOTAS.TX");
		return 1;
		}
	
	fgets(cadena, 256, archivo);
	while(!feof(archivo)){
		//procesar línea
		for(i = 0; cadena[i]; i++){
			c = toupper(cadena[i]);
			if(c >= 'A' && c <= 'Z'){
				v[c - 'A']++;
				}
			}
		fgets(cadena, 256, archivo);
		}
	fclose(archivo);
	//Imprime las letras
	for(i = 0; i < 26; i++){
		printf("\nLa letra %c aparece %d veces.", i + 'A', v[i]);
		}
	
	
	return 0;
	}
