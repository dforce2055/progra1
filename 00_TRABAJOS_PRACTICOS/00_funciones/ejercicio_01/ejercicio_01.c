/*
 * 1. Realizar una función que reciba tres números y devuelva “N” si estos no corresponden a las medidas de los lados de un triángulo, “E”
 * si corresponden a un triángulo equilátero, “I” si corresponden a un triángulo isósceles y “S” si corresponde a un triángulo escaleno. No
 * usar operadores lógicos.
 * */
#include <stdio.h>
/* prototipo */
char triangulo(int a, int b, int c);

int main(){
	int a, b, c;
	char resultado = 'x';
	
	printf("Ingrese 3 valores para determinar el tipo de triangulo\n");
	printf("Lado a: ");
	scanf("%d" , &a);
	printf("Lado b: ");
	scanf("%d" , &b);
	printf("Lado c: ");
	scanf("%d" , &c);
	
	if(a <= 0 || b <= 0 || c <= 0){
		printf("Valores mal ingresados");
	}
	resultado = triangulo(a, b, c);
	
	switch(resultado){
		case 'n':	case 'N':
			printf("\nLos datos ingresados no corresponden a un triangulo.");
			break;
		
		case 'e':	case 'E':
			printf("\nTriangulo Equilatero.");
			break;
		
		case 'i':	case 'I':
			printf("\ntriangulo Isósceles.");
			break;
			
		case 's':	case 'S':
			printf("\ntriangulo Escaleno.");
			break;
	}
	
	return 0;
}
char triangulo(int a, int b, int c)
{
	
	/* triangulo Equilatero "E"  tres lados iguales */
	if((a == b) && (a == c)){
		return 'E' ;
	}
	/* triangulo isósceles "I" dos lados iguales */
	if(((a == b) && (a != c)) || ((a == c) && (a != b)) || ((b == c) && (a != b))){
		return 'I';
	}
	/* triangulo escaleno "S" ningún lado igual */
	if((a != b) && (a != c)){
		return 'S';
	}
	else{/* no es un triangulo "N" */
			return 'N';
		}
	
}
