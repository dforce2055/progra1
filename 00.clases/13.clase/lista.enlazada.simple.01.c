#include <stdio.h>
#include <stdlib.h>
typedef struct sNodo{
  int valor;
  struct sNodo *sig;//puntero a una estructura del proximo nodo (estructura autoreferenciada
}tNodo;

typedef tNodo *tPuntero;//sinonimo tPuntero, puntero a tNodo

void insertarAlPrincipio(tPuntero *cabeza, int dato);
void insertarAlFinal(tPuntero *cabeza, int dato);
void insertarOrdenado(tPuntero *cabeza, int dato);
void imprimirLista(tPuntero cabeza);
void borrarLista(tPuntero *cabeza);
void borrarPrimerNodo(tPuntero *cabeza);
void borrarUltimoNodo(tPuntero *cabeza);

int main(){
  tPuntero cabeza;//ya se implica un * puntero, debido al sinonimo
  int e;
  cabeza = NULL;//Inicializar cabeza es FUNDAMENTAL
  printf("Ingrese elementos, -1 para finalizar: ");
  scanf("%d", &e);
  while(e != -1){
    insertarAlPrincipio(&cabeza, e);
    scanf("%d", &e);
  }
  imprimirLista(cabeza);
  borrarLista(&cabeza);

  return 0;
}
void insertarAlPrincipio(tPuntero *cabeza, int dato){
  tPuntero nuevo;
  nuevo = (tPuntero)malloc(sizeof(tNodo));//
  nuevo->valor = dato;
  nuevo->sig = *cabeza;
  *cabeza = nuevo;
}
void imprimirLista(tPuntero cabeza){
  while(cabeza != NULL){
    printf("%4d", cabeza->valor);
    cabeza = cabeza->sig;
  }
}
void borrarLista(tPuntero *cabeza){
  tPuntero actual;
  while(*cabeza != NULL){
    actual = *cabeza;
    *cabeza = (*cabeza)->sig;
    free(actual);
  }
}
//Nuevas funciones
void borrarPrimerNodo(tPuntero *cabeza){
  tPuntero actual;
  if(*cabeza != NULL){
    actual = *cabeza;
    *cabeza = (*cabeza)->sig;
    free(actual);
  }
}
void insertarAlFinal(tPuntero *cabeza, int dato){
  tPuntero actual, anterior, nuevo;
  actual = *cabeza;
  anterior = NULL;
  while(actual != NULL){
    anterior = actual;
    actual = actual->sig;
  }
  nuevo = (tPuntero)malloc(sizeof(tNodo));
  nuevo->valor = dato;
  nuevo->sig = NULL;
  if(anterior != NULL)//valdria NULL solo si la lista esta vacia, si no existe el nodo
    anterior->sig = nuevo;
  else
    *cabeza = nuevo;
}
void borrarUltimoNodo(tPuntero *cabeza){
  tPuntero actual, anterior, anteAnterior;
  actual = *cabeza;
  anterior = NULL;
  anteAnterior = NULL;
  while(actual != NULL){
    anteAnterior = anterior;
    anterior = actual;
    actual = actual->sig;
  }
  if(anteAnterior != NULL){//verdadero para 2 o más nodos
    free(anterior);//elimina último nodo
    anteAnterior->sig = NULL;//pasa a ser el último nodo de la lista
  }else if(anterior != NULL){//en caso de lista vacia o 1 solo nodo
    free(anterior);
    *cabeza = NULL;
  }
}
void insertarOrdenado(tPuntero *cabeza, int dato){
  tPuntero actual, anterior, nuevo;
  actual = *cabeza;
  anterior = NULL;
  while(actual != NULL && actual->valor < dato){
    anterior = actual;
    actual = actual->sig;
  }
  nuevo = (tPuntero)malloc(sizeof(tNodo));
  nuevo->valor = dato;
  nuevo->sig = actual;
  if(anterior != NULL)
    anterior->sig = nuevo;
  else
    *cabeza = nuevo;
}
