/* 1. Definir estructuras para almacenar los siguientes tipos de datos:
a)  fecha
b)  hora
c)  Datos de un producto
c�digo de barras (21 d�gitos)
nombre  (cadena de caracteres)
precio unitario (n�mero real)
stock (n�mero entero)
fecha de actualizaci�n de stock (d�a, mes, a�o)
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