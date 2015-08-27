/* 7. Una editorial determina el precio de un libro según la cantidad de
páginas que contiene. El costo básico del libro es de $5, más el precio
$0,02 por página con encuadernación rústica. Si el número de páginas
supera las 300 la encuadernación debe ser en tela, lo que incrementa el
costo en $3. Además, si el número de páginas sobrepasa las 600 se hace
necesario un procedimiento especial de encuadernación que incrementa el
costo en $8. Realizar una función que devuelva el costo de un libro dado
el número de páginas. */
#include <stdio.h>
#pragma warning(disable:4996)
float costoDeLibro(int cantPaginas);
int main(){
  int cantPaginas = 0;

  printf("¿Cuantas paginas tienen el libro?\n");
  scanf("%d", &cantPaginas);

  printf("El costo del libro es de $%.2f\n", costoDeLibro(cantPaginas));

  return 0;
}

float costoDeLibro(int cantPaginas){
  int costoBasico = 5, costoTela = 3, costoEspecial = 8;
  float encuRustica = 0.02;
  float costoTotal = 0;

  if (cantPaginas >= 600) {
    costoTotal = (costoBasico + (encuRustica * cantPaginas) + costoEspecial);
  }else if (cantPaginas >= 300) {
    costoTotal = (costoBasico + (encuRustica * cantPaginas) + costoTela);
  }else{
    costoTotal = (costoBasico + (encuRustica * cantPaginas));
  }
  return costoTotal;
}
