/* 4. Realizar una función que reciba como parámetros día, mes y año indique si
la fecha es un fecha gregoriana válida. */
/* SE PUEDE MEJORAR CON LA BIBLIOTECA TIME.H UTILIZANDO ESTRUCTURAS, VOLVER A HACER*/
#include <stdio.h>
int chequearFecha(int dia, int mes, int anio);
int esBisiesto(int anio);
int main(){
  int dia, mes, anio;
  printf("Ingrese una fecha para saber si es correcta.\n");
  printf("\tDía: ");
  scanf( "%d", &dia);
  printf("\tMes: ");
  scanf( "%d", &mes);
  printf("\tAño: ");
  scanf( "%d", &anio);

  if (chequearFecha(dia, mes, anio) == 0) {
    printf ("La fecha es incorrecta\n");;
  }else{
    printf ("La fecha es correcta\n");
  }
  return 0;
}

int chequearFecha(int dia, int mes, int anio){
  int resultado = 0;
  if ((dia > 1 || dia < 31) && (mes > 1 || mes < 12) && (anio > 0 || anio <= 2015 )){
    switch (mes) {
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (dia <= 31) resultado = 1;
        break;

      case 4: case 6: case 9: case 11:
        if (dia <= 30) resultado = 1;
        break;

      case 2:
        if (esBisiesto(anio) && dia == 29) resultado = 1;
        else if(dia <= 28) resultado = 1;
        break;
    }
  }else{
    resultado = 0;
  }
  return resultado;
}
int esBisiesto(int anio){
  if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
    return 1;
  }else{
    return 0;
  }
}
