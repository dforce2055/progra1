/* leer consiga.txt */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct{
  char descripcion[256];
  int precioDesde, precioHasta;
}tProducto;
int grabarPrecios(tProducto producto);
int main(){

  return 0;
}
int grabarPrecios(tProducto producto){
  FILE *archivo;

  if((archivo = fopen("precios.txt","wt")) == NULL){
    puts("Error al intentar grabar >'precios.txt'");
    return 0;
  }


}
