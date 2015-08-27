/*
 * Primer programa que utilizaremos variables dinamicas
 * 
 * */
 #include <stdio.h>
 #include <stdlib.h>
 
 int main(){
	 int *ptr;
	 ptr = (int *)malloc(sizeof(int)); //memory allocation pide al SO reserve un bloque de memoria del tamaño a un entero | castea el puntero a entero
	 *ptr = 3;
	 *ptr = *ptr+1;
	 
	 printf("%d", *ptr);
	 free(ptr); // destruye y/o libera el bloque de memoria previamente reservado por malloc
	 ptr = NULL; // logramos que no apunte a nada, evitando futuros errores al tratar de usar ese puntero
	 return 0;
	 }
