/* 6. La tarifa de un videoclub  para el alquiler de sus videos es:
Dibujos = $2; Estrenos = $3; Otros = $2.5.
Además cobra por devolución tardía $1 por el primer día y $0.5 por cada no de
los días siguientes. Realizar una función que devuelva el alquiler a pagar por
un cliente, sabiendo que recibe como parámetros el tipo de video y la cantidad
de días desfasados en devolución. Si la devolución es anterior al día de
devolución recibirá un entero negativo. */
/*¿SE PUEDE UTILIZAR PRINFT EN UNA FUNCIÓN QUE IMPRIME UN MENU? */
#include <stdio.h>
#pragma warning(disable:4996)
float devolucion(int tipoDeVideo, int diasDeAtraso);
int opcionValida(int opcion);
void imprimirMenu(int *opcion);
int main(){
  //system("clear");
  //system("cls");
  int opcion, tipoDeVideo, diasDeAtraso = 0;
  float tarifa = 0;

  imprimirMenu(&opcion);

  if (opcionValida(opcion)) {
    tipoDeVideo = opcion;
    printf("¿Cuantos días tiene de atraso?(-1 devolución en termino)\n");
    scanf("%d", &diasDeAtraso);
    tarifa = devolucion(tipoDeVideo, diasDeAtraso);
    printf("El costo a pagar es: $%.2f\n", tarifa);
  }else if (opcion != 0) {
    printf("La opción seleccionada es invalida\n");
  }else{
    printf("\nFin del programa");
    printf("\n================\n");
  }

	return 0;
}

float devolucion(int tipoDeVideo, int diasDeAtraso){
  float tarifa = 0, otros = 2.5;
  int dibujos = 2, estrenos = 3;
  for(; diasDeAtraso > 0; diasDeAtraso--){
    if (diasDeAtraso == 1) {
      tarifa = tarifa + 1;
    }else tarifa = tarifa + 0.5;
  }
  switch (tipoDeVideo) {
    case 1:
      tarifa = tarifa + dibujos;
      break;
    case 2:
      tarifa = tarifa + estrenos;
      break;
    case 3:
      tarifa = tarifa + otros;
      break;
  }
  return tarifa;
}
void imprimirMenu(int *opcion){
  printf("\nElija un tipo de Video:");
  printf("\n======================\n");
  printf("\t1. Dibujos\n");
  printf("\t2. Estrenos\n");
  printf("\t3. Otros\n");
  printf("\t0. Salir\n");
  scanf("%d", opcion );//opcion ya es un puntero a la dirección de memoria
}
int opcionValida(int opcion){
  int resultado;
  switch (opcion) {
    case 1: case 2: case 3:
      resultado = 1;
      break;
    default:
      resultado = 0;
      break;
  }
  return resultado;
}
