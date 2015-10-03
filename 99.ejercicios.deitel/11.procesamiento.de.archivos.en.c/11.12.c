/* Carga infomacion de clientes en los registros dentro del archivo */
#include <stdio.h>
typedef struct{
  int numCta;
  char apellido[15];
  char nombre[10];
  float saldo;
}tDatosCliente;

void limpiarBuffer(void);
int main(){
  tDatosCliente cliente = {0, "", "", 0.0};
  FILE *archivo;
  int i;

  if((archivo = fopen("credito.dat","rb+")) == NULL){
    printf("Error al intentar crear '%s'", "credito.dat");
    return 1;
  }

  printf("Introduzca nro. de cuenta(1 a 100, 0 para terminar): ");
  scanf("%d", &cliente.numCta);
  limpiarBuffer();
  while(cliente.numCta != 0){
    printf("Ingreso Apellido, Nombre y saldo\n");
    fscanf(stdin, "%s%s%f", cliente.apellido, cliente.nombre, &cliente.saldo);

    //Establece la posición del registro en el archivo
    fseek(archivo, (cliente.numCta -1) * sizeof(cliente), SEEK_SET);
    fwrite(&cliente, sizeof(cliente), 1, archivo);

    printf("Introduzca nro. de cuenta(1 a 100, 0 para terminar): ");
    scanf("%d", &cliente.numCta);
    limpiarBuffer();
  }

  fclose(archivo);
  return 0;
}
void limpiarBuffer(void){
  while(fgetc(stdin) != '\n');
}
