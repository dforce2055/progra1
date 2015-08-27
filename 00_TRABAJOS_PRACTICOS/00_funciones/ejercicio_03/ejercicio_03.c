/*
 * 3. Realizar una función que reciba el año como parámetro y devuelva verdadero si el año es bisiesto o falso si no lo es. Se recuerda que
 * un año es bisiesto cuando es divisible por 4. Sin embargo aquellos años que sean divisibles por 4 y también por 100 no son bisiestos, a
 * menos que también sean divisibles por 400. Por ejemplo, 1900 no fue bisiesto pero sí lo fueron el 2000 y 2004.
 * */
#include <stdio.h>
int main(){
	int anio = 0;
	
	printf("Ingrese un año, para saber si es bisiesto:");
	scanf("%d", &anio);
	
	if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
		printf("\nEl año es bisiesto\n");
	}else{
			printf("\nEl año no es bisiesto\n");
		}
	
	return 0;
}
