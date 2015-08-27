/*
 * Asignacion dinamica de memoria aplicada al manejo de una vector de enteros
 * */
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 int main(){
	 int *vec, i;
	 srand(time(NULL));
	 vec = (int *)malloc(100*sizeof(int));// reserva en memoria 100 lugares del tamanio de int vector[100]
	 
	 for(i = 0; i < 100; i++){
		 vec[i] = rand()%100;
		 }
	
	for(i = 0; i < 100; i++){
		printf("%4d", vec[i]);
		}
	
	free(vec);
	vec = NULL;
	 
	 return 0;
	 }
