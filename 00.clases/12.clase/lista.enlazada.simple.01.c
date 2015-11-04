#include <stdio.h>
#include <stdlib.h>
typedef struct sNodo{
  int valor;
  struct sNodo *sig;//puntero a una estructura del proximo nodo (estructura autoreferenciada
}tNodo;

typedef tNodo *tPuntero;//sinonimo tPuntero, puntero a tNodo

void insertarAlPrincipio(tPuntero *cabeza, int dato);
void imprimirLista(tPuntero cabeza);
void borrarLista(tPuntero *cabeza);

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
