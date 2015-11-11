//d alfinal de cada structura para identificar que se trata de una lista
//doblomente enlazada
#include <stdio.h>
#include <stdlib.h>
typedef struct sNodoD{
  int valor;
  struct sNodoD *ant, *sig;
}tNodoD;
typedef tNodoD * tPunteroD;

void insertarAlPrincipioD(tPunteroD *cabeza, int dato);
void insertarAlFinalD(tPunteroD *cabeza, int dato);
void insertarOrdenadoD(tPunteroD *cabeza, int dato);
void imprimirListaD(tPunteroD cabeza);

int main(){

  return 0;
}

void insertarAlPrincipioD(tPunteroD *cabeza, int dato){
  tPunteroD nuevo;
  nuevo = (tPunteroD)malloc(sizeof(tNodoD));
  nuevo->valor = dato;
  nuevo->ant = NULL;
  nuevo->sig = *cabeza;
  if(*cabeza != NULL)
    (*cabeza)->ant = nuevo;
  *cabeza = nuevo;
}
void insertarAlFinalD(tPunteroD *cabeza, int dato){
  tPunteroD actual, anterior, nuevo;
  actual = *cabeza;
  anterior = NULL;
  while(actual != NULL){
    anterior = actual;
    actual = actual->sig;
  }
  nuevo = (tPunteroD)malloc(sizeof(tNodoD));
  nuevo->ant = anterior;
  nuevo->sig = NULL;
  if(anterior != NULL)
    anterior->sig = nuevo;
  else
    *cabeza = nuevo;
}
void insertarOrdenadoD(tPunteroD *cabeza, int dato){
  tPunteroD actual, anterior, nuevo;
  actual = *cabeza;
  anterior = NULL;
  while(actual != NULL && actual->valor < dato){
    anterior = actual;
    actual = actual->sig;
  }
  nuevo = malloc(sizeof(tNodoD));
  nuevo->valor = dato;
  nuevo->ant = anterior;
  nuevo->sig = actual;
  if(anterior != NULL)
    anterior->sig = nuevo;
  else
    *cabeza = nuevo;
  if(actual != NULL)
    actual->ant = nuevo;
}
void imprimirListaD(tPunteroD cabeza){
  tPunteroD anterior = NULL;
  puts("Ida");
  while(cabeza != NULL){
    printf("%4d", cabeza->valor);
    anterior = cabeza;
    cabeza = cabeza->sig;
  }
  puts("Vuelta");
  while(anterior != NULL){
    printf("%4d", anterior->valor);
    anterior = anterior->ant;
  }
}
