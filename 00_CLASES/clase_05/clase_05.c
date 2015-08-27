/*
 * Clase #05
 * Martes 3 de Septiembre de 2013
 * Funciones de biblioteca para el manejo de caracteres y cadenas.
 * ***************************************************************
 * 
 * Funciones de la biblioteca para el tratamiento de caracteres y cadenas
 * 
 * Funciones de la Biblioteca ctype
 * isalpha(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * isdigit(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * isalnum(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * isspace(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * isupper(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * islower(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.
 * toupper(<char>) --- char, devuelve el carecter en minuscula.
 * tolower(<char>) --- char, devuelve el caracter en mayúscila.
 * 
 * Programa ejemplo:
 * */
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isalpha(cad[i])){
				printf("%c es un carácter alfabético\n", cad[i]);
			}
		}
	 return 0;
 }
/* isalpha(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isdigit(cad[i])){
				printf("%c es un digito\n", cad[i]);
			}
		}
	 return 0;
 }
/* isalnum(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isalnum(cad[i])){
				printf("%c es un digito alfanumerico\n", cad[i]);
			}
		}
	 return 0;
 }
/* isspace(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isspace(cad[i])){
				printf("%c es un espacio\n", cad[i]);
			}
		}
	 return 0;
 }
/* isupper(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isdigit(cad[i])){
				printf("%c es un caracter en mayuscula\n", cad[i]);
			}
		}
	 return 0;
 }
/* islower(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(islower(cad[i])){
				printf("%c es un caracter en minuscula\n", cad[i]);
			}
		}
	 return 0;
 }
/* toupper(<char>) --- Devuelve verdadero o Falso, 0 falso, !0 verdadero.*/
 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			cad[i] = toupper(cad[i]);
		}
	printf("%s", cad);
	 return 0;
 }

/*
 * Biblioteca stdio
 * ****************
 * 
 * gets(<cadena>);	Recibe una cadena de caracteres mediante teclado
 * puts(<cadena>);	Imprime por pantalla una cadena + un salto de línea «=» printf("%s\n", cadena);
 * sprintf(<cadena> , <cadena de control> , <datos>);
 * sscanf(<cadena> , <cadena de control> , <dirección de variables>);
 * */
/* Ejemplo de sprintf #01*/
#include <stdio.h>
int main(){
	char cad[80];
	float pi = 3.1416;
	
	sprintf(cad,%f,pi);
	cad[1]=','; /* reemplaza el . ubicado en cad[1] por una coma, queda 3,1416000*/
	puts(cad);
	return 0;
}
/* Ejemplo de sprintf #02 */
#include <stdio.h>
int main(){
	char dias[80];
	char dia1[] = "Lunes";
	char dia2[] = "Martes";
	char dia3[] = "Miércoles";
	
	sprintf(dias,"%s,%s,%s",dia1,dia2,dia3);
	
	return 0;
}
/* Ejemplo de sscanf #01*/
#include <stdio.h>
int main(){
	char cad[80] = "3.1416";/* se ingresa ".", ya que es un caracter valido, sino con "," seria invalido, y sscanf solo convierte hasta el caracter 3 a float*/
	float pi;
	
	sscanf(cad,"%f", &pi);
	printf("%f", pi);
	
	return 0;
}
/* Ejemplo de sscanf #01*/
#include <stdio.h>
int main(){
	char cad[] = "Lima 717";
	int altura;
	
	sscanf(&cad[5],"%d", &altura);/* le indicamos a sscanf que lee a partir del lugar cad[5], para evitar enviar caracteres invalidos*/
		 /* cad+5,*/
	return 0;
}
/* Bibliotecas string
 * ******************
 * #include <string.h>
 * Todas las funciones de la biblioteca string.h comienzan con "str", la segunda parte del nombre de la función hace alusión al
 * proposito de la función
 * 
 * strlen(<cadena>);	int, devuelve la cantidad de caracteres de esta cadena. Da un warning, para lo cual debemos "castear" el
 * resultado de strlen.
 * a = strlen(cad); 	NO
 * a = (int)strlen(cad);	SI
 * 
 * strcpy(<destino>,<origen>);	Copia, a destino la cadena origen, destruyendo el contenido de destino.
 * strcat(<destino>,<origen>);	Concatena cadenas;
 * strchr(<cadena>,<char>);		Busca un caracter dentro de la cadena, si lo encuentra devuelve un puntero a la posicion donde
 * encontro el caracter char *, sino lo encuentra devuelve un puntero a NULL
 * 
 * strstr(<cadena1>,<cadena2>);	Similar a la anterior, pero busca una cadena, dentro de una cadena mayor, devuelve un puntero a donde
 * se encuentra, si no la encuentra, puntero !NULL
 * 
 * strcmp(<cadena1>,<cadena2>);	Compara el contenido de 2 cadenas de caracteres, devuelve un int
 * < 0 (-1)	si cad1 < cad2
 * == 0 (0)	si cad1 == cad2
 * > 0 (1)	si cad1 > cad2
 * */
/* Ejemplo de strchr #01*/
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
/* Ejemplo de strchr #02*/
#include <stdio.h>
#include <string.h>
int main(){
	char cad[80];
	int i;
	
	puts("Ingrese una frase");
	gets(cad);
	
	for(i = 0; cad[i]; i++){
		if(strchr("aeiou", cad[i]) !NULL){
			printf("\nHay una vocal en la posición %d\n", i);
		}
	}
	
	return 0;
}
