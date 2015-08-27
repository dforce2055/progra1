/*
Desarrollar un programa que genere un archivo binario con números al azar (sin restrigciones de rango), cuya cantidad de registro sera también un número al azar comprendido entre 1 y 30000. Una vez generado se solicita separar los registros en 2 archivos, colocando en uno de ellos los registros cuyo valor contenga por lo menos un digito de valor 5 (en cualquier posición) y en otro archivo los restantes registros
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:4244)

int main(){
	FILE *archivo;
	FILE *resto;
	FILE *concinco;
	FILE *texto;
	int cantreg, i, numero, largo, haycinco = 0;
	char digitos[10] = {' '};
	srand(time(NULL));

	archivo = fopen("c:/datos/2.2/archivo.dat","wb");
	resto = fopen("c:/datos/2.2/resto.txt", "w");
	concinco = fopen("c:/datos/2.2/concinco.txt","w");
	texto = fopen("c:/datos/2.2/texto.txt","w");

	if(archivo == NULL || resto == NULL || concinco == NULL || texto == NULL){
		puts("No pudo crearse el archivo");
		return 1;
		}
	
	cantreg = rand()%30;

	for(i = cantreg; i > 0; i--){
		numero = rand();
		fwrite(&numero, sizeof(int), 1, archivo);
		fprintf(texto, "%d\n", numero);
		}

	printf("Se generaron %d registros\n", cantreg);

	rewind(texto);
	rewind(archivo);
	fseek(archivo, 0, 1, SEEK_SET);
	
	fread(&numero, sizeof(int), 1, texto);
	printf("%d\n", numero);
	fread(&numero, sizeof(int), 1, texto);
	printf("%d\n", numero);
	fread(&numero, sizeof(int), 1, texto);
	printf("%d\n", numero);
	fread(&numero, sizeof(int), 1, texto);
	printf("%d\n", numero);
	getch();
	/*while(!feof(archivo)){
		printf("%d\n", numero);
		fread(&numero, sizeof(int), 1, archivo);
		}
	getch();
	*/
	/*while(!feof(texto)){
		fgets(digitos, 10, texto);
		largo = strlen(digitos);

		for(i = 0; i < largo ; i++){
			if(digitos[i] == 5){
				haycinco = 1;
				}
			}
		digitos[i] = '\0';
		if(haycinco == 1){
			fputs(digitos, concinco);
			haycinco = 0;
			}else{
			
				fputs(digitos, resto);
				haycinco = 0;
			}
		}
	*/


	
	fclose(archivo);
	fclose(texto);
	fclose(resto);
	fclose(concinco);

	return 0;
	}