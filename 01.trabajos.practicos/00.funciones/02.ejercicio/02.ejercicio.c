/* 2. Hacer una función que reciba tres valores enteros positivos y devuelva el
mayor estricto de los tres. En caso de no existir devolver -1.
No usar operadores lógicos.
[NO CONTEMPLA LOS Nº NEGATIVOS CONSULTAR]
*/
#include <stdio.h>
#pragma warning(disable:4996)
/* prototipo */
int mayorValor(int a, int b, int c);

int main(){
  //system("clear");
  //system("cls");
  int a, b, c, valor;

  printf("Ingrese 3 valores, le dire cual es el mayor:\n");
  scanf("%d%d%d", &a, &b, &c);

  valor = mayorValor(a, b, c);

  if(valor == -1){
    printf("Los valores ingresados son iguales\n");
  }else{
      printf("El mayor valor es [%d]\n", valor);
    }
  return 0;
}

int mayorValor(int a, int b, int c)
{
  int mayor = a;

  if(b > mayor){
    mayor = b;
  }
  if(c > mayor){
    mayor = c;
    }
  if((a == b) && (b == c)){
    mayor = -1;
  }
  return mayor;
}
