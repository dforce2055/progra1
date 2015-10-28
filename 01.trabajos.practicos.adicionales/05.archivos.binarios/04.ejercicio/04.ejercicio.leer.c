/* leer "consigna.txt" */
/* Leer registros y actualizar segun corresponda*/
#include <stdio.h>
#include <time.h>
#define MAX 25000
typedef struct{
  int numeroCliente;
  int saldo;
  int limiteDeCredito;
}tSaldo;
void mostrar(tSaldo saldo);
int main(){
  FILE *archivo;
  tSaldo saldo;


  if((archivo = fopen("clientes.dat","rb+")) == NULL){
    puts("No pudo leerse >\'clientes.dat\'");
    return 1;
  }
  rewind(archivo);

  fread(&saldo, sizeof(tSaldo), 1, archivo);
  while(!feof(archivo)){
    /*if(saldo.limiteDeCredito > MAX){
      mostrar(saldo);
      saldo.limiteDeCredito = MAX;
      saldo.saldo = -100;
      fseek(archivo, (-1) * (int)sizeof(tSaldo), SEEK_CUR);
      fwrite(&saldo, sizeof(tSaldo), 1, archivo);
      fseek(archivo, 0, SEEK_CUR);
    }*/
    mostrar(saldo);
    fread(&saldo, sizeof(tSaldo), 1, archivo);
  }


  fclose(archivo);
  return 0;
}
void mostrar(tSaldo saldo){
  printf("Numero de cliente: %d\n", saldo.numeroCliente);
  printf("Saldo: %d\n", saldo.saldo);
  printf("Límite de Crédito: %d\n", saldo.limiteDeCredito);
  printf("\n");
}
