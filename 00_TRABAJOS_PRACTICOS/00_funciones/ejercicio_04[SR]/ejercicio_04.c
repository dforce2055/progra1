/*
 * 4. Realizar una función que reciba como parámetros día, mes y año indique si la fecha es un fecha gregoriana válida.
 * */
#include <stdio.h>

int fecha_valida(int dia, int mes, int anio);
int main(){
	int dia, mes ,anio = 0;
	int resultado;
	
	printf("Ingrese una fecha dd-mm-aaaa\n");
	printf("\nDía: ");
	scanf("%d", &dia);
	printf("\nMes: ");
	scanf("%d", &mes);
	printf("\nAño: ");
	scanf("%d", &anio);
	
	resultado = fecha_valida(dia, mes, anio);
	if(resultado == 0){
		printf("\nLa fecha ingresadas, es una fecha gregoriana valida.");
	}else{
			printf("\nLa fecha ingresada no es validad.");
		}
	
	
	return 0;
}

int fecha_valida(int dia, int mes, int anio)
{
	int resultado = 0;
	
	if(anio > 2013 || anio < 1){
		resultado = 1; 
	}
	if(dia > 31){
		resultado = 1;
	}
	
			switch (mes){
				case '1':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '2':
					if(dia > 28 || dia < 1){
						resultado = 1;
					}else if((dia == 29) && ((anio % 4 != 0 && anio % 100 != 0) || (anio % 400 != 0))){
							resultado = 1;
						}
				break;
				
				case '3':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '4':
					if(dia > 30 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '5':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '6':
					if(dia > 30 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '7':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '8':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '9':
					if(dia > 30 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '10':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '11':
					if(dia > 30 || dia < 1){
						resultado = 1;
					}
				break;
				
				case '12':
					if(dia > 31 || dia < 1){
						resultado = 1;
					}
				break;
			}
		
	
	return resultado;
}
