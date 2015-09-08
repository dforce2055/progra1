/* 8. Un banco necesita para sus cajeros automáticos un programa que lea una
cantidad de dinero e informe la cantidad mínima de billetes a entregar,
considerando que existen billetes de $100, $50, $10, $5 y $1.
Realizar una función que calcule dichas cantidades. */
#include <stdio.h>
#pragma warning(disable:4996)
void billetes(int *dCien, int *dCincuenta, int *dDiez, int *dCinco, int *dUno, int cantidad);
int main(){
  int dCien = 0, dCincuenta = 0, dDiez = 0, dCinco = 0, dUno = 0, cantidad = 0;
  printf("¿Cantidad? ");
  scanf("%d", &cantidad);
  billetes(&dCien, &dCincuenta, &dDiez, &dCinco, &dUno, cantidad);
  if (dCien >= 1)     printf("Billestes de \t$100\t%d\n", dCien);
  if (dCincuenta >= 1)printf("Billestes de \t$50\t%d\n", dCincuenta);
  if (dDiez >= 1)     printf("Billestes de \t$10\t%d\n", dDiez);
  if (dCinco >= 1)    printf("Billestes de \t$5\t%d\n", dCinco);
  if (dUno >= 1)      printf("Billestes de \t$1\t%d\n", dUno);

  return 0;
}

void billetes(int *dCien, int *dCincuenta, int *dDiez, int *dCinco, int *dUno, int cantidad){
  while (cantidad > 0) {
    if (cantidad >= 100) {
      *dCien = *dCien + 1;
      cantidad = cantidad - 100;
    }else if (cantidad >= 50) {
      *dCincuenta = *dCincuenta + 1;
      cantidad = cantidad - 50;
    }else if (cantidad >= 10) {
      *dDiez = *dDiez + 1;
      cantidad = cantidad - 10;
    }else if (cantidad >= 5) {
      *dCinco = *dCinco + 1;
      cantidad = cantidad - 5;
    }else{
      *dUno = *dUno + 1;
      cantidad = cantidad - 1;
    }
  }
}
