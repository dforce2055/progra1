/* Crea archivo binario con 100 registros de estructuras vacias*/
#include <stdio.h>
typedef struct{
  int numCta;
  char apellido[15];
  char nombre[10];
  double saldo;
}tDatosCliente;

int main(){
  tDatosCliente clienteEnBlanco = {0, "", "", 0.0};
  FILE *archivo;
  int i;

  if((archivo = fopen("credito.dat","wb")) == NULL){
    printf("Error al intentar crear '%s'", "credito.dat");
    return 1;
  }
  for(i = 0; i < 100; i++){//guardo 100 registros en blanco en archivo
    fwrite(&clienteEnBlanco, sizeof(clienteEnBlanco), 1, archivo);
  }

  fclose(archivo);
  return 0;
}
