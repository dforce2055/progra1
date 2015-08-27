/* Duplicar el valor de un numero recibido como parametro.
Hay que utilizar punteros para poder pasar una variable simple por referencia
y no por valor como lo hace normalmente C. */
#include <stdio.h>
void duplicar(int *valor);
int main(){
  int valor;
  printf("Ingrese un entero: ");
  scanf("%d", &valor);
  duplicar(&valor); // paso la variable a por referencia
  printf("El doble del valor ingresado es %d\n", valor);
	return 0;
}

void duplicar(int *valor) {
  *valor = *valor * 2;
}
