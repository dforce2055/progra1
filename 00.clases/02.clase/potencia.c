/* escribir un programa que utilice una funcion para elevar un numero entero a una potencia que sea un numero natural.
(una potencia es un conjunto de multiplicaciones sucesivas) */
#include <stdio.h>
int potencia(int base, int exponente);
int main(){
  int base, exponente;

  printf("Base? ");
  scanf("%d", &base);
  printf("Expontente? ");
  scanf("%d", &exponente);
  printf("El resultado es %d\n", potencia(base, exponente));

	return 0;
}

int potencia(int base, int exponente){
  int i, res = 1;

  for(i = 0; i < exponente; i++){
    res = res * base;
  }
  return res;
}
