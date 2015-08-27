/*
 * Programa para utilizar una lista
 * 
 * */
 #include <stdio.h>
 #include <stdlib.h>
 
 //definicion de estructuras
 typedef struct snodo{ //estructura autoreferenciada 
	 int valor;
	 struct snodo *sig;
	 }Tnodo;
	 
 typedef Tnodo * Tpuntero; // sirve para esconder un * y que no sea tan engorroso trabajar con listas
 
 // prototipo de las funciones
 void insertaralprincipio(Tpuntero *cabeza, int dato);// pasado por referencia
 void imprimirlista(Tpuntero cabeza);// pasado por valor, para no modificar el original
 void borrarlista(Tpuntero *cabeza);// pasado por referencia
 
 int main(){
	 Tpuntero cabeza;
	 int e;
	 cabeza = NULL;// FUNDAMENTAL, sin eso no funciona el programa
	 
	 printf("Ingrese elementos, -1 para terminar");
	 scanf("%d", &e);
	 
	 while(e != -1){
		 insertaralprincipio(&cabeza, e);//cabeza por referencia y el valor
		 scanf("%d", &e);
		 }
	
	imprimirlista(cabeza);
	borrarlista(&cabeza); // cabeza por refernecia
	
	return 0;
	 }

 void insertaralprincipio(Tpuntero *cabeza, int dato){
	 Tpuntero nuevo;
	 nuevo = (Tpuntero)malloc(sizeof(Tnodo));
	 nuevo->valor = dato;
	 nuevo->sig = *cabeza;
	 *cabeza = nuevo;
	 }
	 
 void imprimirlista(Tpuntero cabeza){
	 while(cabeza != NULL){
		 printf("%4d", cabeza->valor);
		 cabeza = cabeza->sig;
		 }
	 }
	 
 void borrarlista(Tpuntero *cabeza){
	 Tpuntero actual;
	 while(*cabeza != NULL){
		 actual = *cabeza;
		 *cabeza = (*cabeza)->sig;
		 free(actual);
		 }
	 }
