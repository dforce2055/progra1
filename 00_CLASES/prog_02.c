#include <stdio.h>
int main(){
	char dias[80];
	char dia1[] = "Lunes";
	char dia2[] = "Martes";
	char dia3[] = "Miércoles";
	
	sprintf(dias,"%s,%s,%s",dia1,dia2,dia3);
	
	return 0;
	}
