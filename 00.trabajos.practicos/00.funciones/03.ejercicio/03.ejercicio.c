/* 3. Realizar una función que reciba el año como parámetro y devuelva verdadero
 si el año es bisiesto o falso si no lo es.
 Se recuerda que un año es bisiesto cuando es divisible por 4.
 Sin embargo aquellos años que sean divisibles por 4 y también por 100 no son
 bisiestos, a menos que también sean divisibles por 400.
 Por ejemplo, 1900 no fue bisiesto pero sí lo fueron el 2000 y 2004.*/
 /* imprimir en una función es una mala practica de programación.
    ¿Como devolver un string? */
#include <stdio.h>
#pragma warning(disable:4996)
/* prototipo */
int esBisiesto(int anio);// puntero a cadena, pasa por referencia

int main(){
  //system("clear");
  int anio;

  printf("Ingrese el año, para saber si es biciesto: ");
  scanf( "%d", &anio);
  if (esBisiesto(anio) == 1) {
    printf("El año es biciesto\n");
  }else{
    printf("No es biciesto\n");
  }

  return 0;
}

int esBisiesto(int anio){
  if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)){
    return 1;
  }else{
    return 0;
  }
}
