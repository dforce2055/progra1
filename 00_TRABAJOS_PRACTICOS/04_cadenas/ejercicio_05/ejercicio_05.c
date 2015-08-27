/*
 * Hacer una funcion que permita reemplazar en una secuencia de caracteres 
 * todos los guiones(-) y reemplazarlos por el caracter numeral (#)
 * */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void separar_telefonos(char cadena[]);

int main(){
	char cadena[256];
	
	
	printf("Ingrese una cadena de digitos\n");
	gets(cadena);
	separar_telefonos(cadena);
	printf("\n%s", cadena);
	
	return 0;
	}
//Invertir cadena de caracteres
void separar_telefonos(char cadena[]){
	int i, j, largo, ceros = 0, contador = 0;
	char cadenaaux[256] = {'\0'};
	
	largo = strlen(cadena);//largo de la cadena
	for(i = 0; largo % 8 != 0; i++){//calculo cuantos 0 agregar si no es divisible x 8
		largo++;
		ceros++;
		}
	
	for(i = 0; ceros > 0; i++, ceros--){
		cadenaaux[i] = '0';//agrego en cadena aux la cantidad de 0 necesarios
		}
	strcat(cadenaaux, cadena);//concateno a cadena aux, cadenaorig
	strcpy(cadena, cadenaaux);//copio cadenaaux a cadenaorig
	
	
	cadenaaux[0] = '\0';//inicializo cadenaaux para poder reutilizarla
	largo = strlen(cadena);
	//Agrega un (-) cada 4 caracteres y un ( ) cada 8
	for(i = 0, j = 0; cadena[i] != '\0'; i++){
		contador++;
		if(contador != 4 && contador != 8){
			cadenaaux[j] = cadena[i];
			}
		if(contador == 4){
			cadenaaux[j+1] = '-';
			cadenaaux[j] = cadena[i];
			j++;
			}
		if(contador == 8){
			cadenaaux[j+1] = ' ';
			cadenaaux[j] = cadena[i];
			j++;
			contador = 0;
			}
		j++;
		}
	
	strcpy(cadena, cadenaaux);
	}
