/* leer "consigna.txt" */
/* Crear archivo con la siguiente estructura con datos random */
#include <stdio.h>
#include <time.h>
typedef struct{
  int numeroCliente;
  int saldo;
  int limiteDeCredito;
}tSaldo;
void mostrar(FILE *in);
int main(){
  srand(time(NULL));
  FILE *out;
  tSaldo saldo;
  int i;

  if((out = fopen("clientes.dat","wb")) == NULL){
    puts("No pudo crearse >\'clientes.dat\'");
    return 1;
  }

  for(i = 0; i < 10; i++){
    saldo.numeroCliente = i;
    saldo.saldo =           rand()%25000;//entre 0 y 25000
    saldo.limiteDeCredito = rand()%50000;//entre 0 y 50000
    fwrite(&saldo, sizeof(tSaldo), 1, out);
    printf("Numero de cliente: %d\n", saldo.numeroCliente);
    printf("Saldo: %d\n", saldo.saldo);
    printf("Límite de Crédito: %d\n", saldo.limiteDeCredito);
    printf("\n");

  }

  //mostrar(out);
  fclose(out);
  return 0;
}
void mostrar(FILE *in){
  tSaldo saldo;

  rewind(in);
  fread(&saldo, sizeof(tSaldo), 1, in);
  while(!feof(in)){
    printf("Numero de cliente: %d", saldo.numeroCliente);
    printf("Saldo: %d", saldo.saldo);
    printf("Límite de Crédito: %d", saldo.limiteDeCredito);
    printf("\n");
    fread(&saldo, sizeof(tSaldo), 1, in);
  }
  fclose(in);
}
