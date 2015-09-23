/* 1. Definir estructuras para almacenar los siguientes tipos de datos:
a)  fecha
b)  hora
c)  Datos de un producto
código de barras (21 dígitos)
nombre  (cadena de caracteres)
precio unitario (número real)
stock (número entero)
fecha de actualización de stock (día, mes, año)
*/
#include <stdio.h>
#include <string.h>
typedef struct{
  int dia, mes, anio;
}tFecha;
typedef struct{
  int hora, minuto, segundo;
}tHora;
typedef struct{
  int codBar[22];
  char nombre[80];
  float precio;
  int stock;
  tFecha fechaStock;
}tProducto;
int main(){
  
  return 0;
}