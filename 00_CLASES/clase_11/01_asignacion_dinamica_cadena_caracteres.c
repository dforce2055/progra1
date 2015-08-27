/*
 * Asignacion dinamica de memoria aplicada al manejo de una cadena de caracteres
 * */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main(){
	 char *cad;
	 cad = (char *)malloc(80);
	 
	 strcpy(cad, "Programacion");
	 puts(cad);
	 
	 free(cad);
	 cad = NULL;
	 
	 return 0;
	 }
