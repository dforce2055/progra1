#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(){
	FILE *imput;
	int i;
	char cadena[] = "33HOLA";
	int cadena2[5] ;
	
	/*imput = fopen("imput.txt", "r");
	
	fgets(cadena2, 10, imput);
	printf("Esta es la cadena leida %s", cadena2);
	
	
	i = atoi(&cadena2[0]);
	*/
	cadena2[0] = 99;
	
	cadena[0] = cadena2[0];
	printf("%d%c", cadena[0], cadena[4]);
	
	return 0;
	}
/*
int main ()
{
  int i;
  char buffer[256];
  printf ("Enter a number: ");
  fgets (buffer, 256, stdin);
  i = atoi (buffer);
  printf ("The value entered is %d. Its double is %d.\n",i,i*2);
  return 0;
}
*/
