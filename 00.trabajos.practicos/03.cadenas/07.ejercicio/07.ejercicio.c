/* 7.	Hacer una funci�n que permita insertar una sub-cadena en una cadena a partir de una posici�n dada. */
/* tratar de rehacerlo utilizando metodo de corrimientos */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(){
	char cadena[100] = "hola";
	strcat(cadena, " mundo");
	puts(cadena);
	return 0;
}