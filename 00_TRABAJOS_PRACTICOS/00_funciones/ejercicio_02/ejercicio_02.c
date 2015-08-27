/*
 * 2. Hacer una función que reciba tres valores enteros positivos y devuelva el mayor estricto de los tres. En caso de no existir devolver
 * -1. No usar operadores lógicos.
 * */
#include <stdio.h>

/* prototipo */
int mayor_valor(int a, int b, int c);

int main(){
	int a,b,c = 0;
	int valor;
	
	printf("Ingrese 3 valores, le dire cual es el mayor:\n");
	scanf("%d%d%d", &a, &b, &c);
	
	valor = mayor_valor(a, b, c);
	
	if(valor == -1){
		printf("Los valores ingresados son iguales");
	}else{
			printf("El valor mayor es [%d]", valor);
		}
	
	return 0;
}

int mayor_valor(int a, int b, int c)
{
	int mayor = a;
	
	if(b > mayor){
		mayor = b;
	}else if(c > mayor){
		mayor = c;
		}
	if((a == b) && (b == c)){
		return -1;
	}
	
	return mayor;
}
