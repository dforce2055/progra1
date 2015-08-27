#include <stdio.h>
#include <string.h>
int main(){
	char cad[80];
	char *ptr;
	
	strcpy(cad, "Programación");
	ptr = strchr(cad, 'g');
	
	if(ptr != NULL){
		printf("La letra g, se encontró en la posición [%d]", ptr - cad);
	}
	
	return 0;
}
