/* Ejemplo de strchr #02*/
#include <stdio.h>
#include <string.h>
int main(){
	char cad[80];
	int i;
	
	puts("Ingrese una frase");
	gets(cad);
	
	for(i = 0; cad[i]; i++){
		if(strchr("aeiou", cad[i]) != NULL){
			printf("\nHay una vocal en la posición %d\n", i);
		}
	}
	
	return 0;
}
