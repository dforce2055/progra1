/* Lee todos los registros del archivo credito.dat e imprime por pantalla
con formato los registros que no estan vacios*/
#include <stdio.h>
typedef struct{
  int numCta;
  char apellido[15];
  char nombre[10];
  float saldo;
}tDatosCliente;

int main(){
  tDatosCliente cliente = {0, "", "", 0.0};
  FILE *archivo;
  int i;

  if((archivo = fopen("credito.dat","rb")) == NULL){
    printf("Error al intentar crear '%s'", "credito.dat");
    return 1;
  }

  printf("%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo");
  fread(&cliente, sizeof(cliente), 1, archivo);
  while(!feof(archivo)){
    if(cliente.numCta != 0){//Previamente todos los registros contienen en numCta 0
      printf("%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
    }
    fread(&cliente, sizeof(cliente), 1, archivo);
  }


  fclose(archivo);
  return 0;
}
