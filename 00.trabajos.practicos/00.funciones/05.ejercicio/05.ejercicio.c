/* 5. Realizar una función que reciba como parámetros día, mes, año y una
cantidad de días, y devuelva la fecha resultante de sumar a la fecha recibida
la cantidad de días. La fecha resultante debe ser una fecha gregoriana. */
#include <stdio.h>
int chequearFecha(int dia, int mes, int anio);
int esBisiesto(int anio);
void sumarDias(int *dia, int *mes, int *anio, int diasASumar);
int main(){
  int dia, mes, anio, diasASumar;

  printf("Ingrese una fecha.\n");
  printf("\tDía: ");
  scanf( "%d", &dia);
  printf("\tMes: ");
  scanf( "%d", &mes);
  printf("\tAño: ");
  scanf( "%d", &anio);

  if (chequearFecha(dia, mes, anio)) {
    printf("Ingrese la cantidad de días a sumar:");
    scanf("%d", &diasASumar);
  }else{
    printf("La fecha ingresada es incorrecta.\nFin del Programa.\n");
  }
  sumarDias(&dia, &mes, &anio, diasASumar);
  printf("La fecha final seria %d/%d/%d\n", dia, mes, anio);
  return 0;
}
void sumarDias(int *dia, int *mes, int *anio, int diasASumar){
  for(;diasASumar>0;diasASumar--){
      if(*dia < 30 ){
          *dia = *dia + 1;//suma 1 día
      }else{
          if (*mes == 12){
              *mes = 1;
              *anio = *anio + 1;
          }else{
            *mes = *mes + 1;
          }
          *dia = 1;
      }
  }
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
