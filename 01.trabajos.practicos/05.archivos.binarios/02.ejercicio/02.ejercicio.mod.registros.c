/* Leer 02.ejercicio.consigna.txt*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
  int mes, anio;
}tFecha;
typedef struct{
  char lote[6];
  char codBar[22];
  char nombre[41];
  float costo;
  int stock;
  tFecha fechVen;
}tMedicamento;

void mostrarRegistros(FILE *archivo);
void vencidos(FILE *archivo, tFecha fechaTestigo);

int main(){
  FILE *archivo;
  FILE *archNoVencidos;



  if((archivo = fopen("base.medicamento.dat","rb+")) == NULL){
    puts("El archivo no pudo abrirse.");
    return 1;
  }
  if((archNoVencidos = fopen("medicamentos.vencidos.dat","rb+")) == NULL){
    puts("El archivo no pudo abrirse.");
    return 1;
  }

  mostrarRegistros(archivo);
  system("clear");
  puts("Medicamentos NO vencidos");
  puts("========================");
  mostrarRegistros(archNoVencidos);



  return 0;
}
void mostrarRegistros(FILE *archivo){
  tMedicamento medicamento;
  rewind(archivo);
  fread(&medicamento, sizeof(tMedicamento), 1, archivo);
  printf("%-12s %-25s %-5s\n", "CODIGO","NOMBRE","CANTIDAD EN STOCK");
  while(!feof(archivo)){
    if(strlen(medicamento.nombre) != 0)
      printf("%-12s %-25s %-3du.\n", medicamento.codBar, medicamento.nombre, medicamento.stock);
      //printf("%-20s %-8s %-10s $%-8.2f %-3du.  %d/%-7d\n", medicamento.nombre,medicamento.lote,medicamento.codBar,medicamento.costo,medicamento.stock,medicamento.mes, medicamento.anio);

    fread(&medicamento, sizeof(tMedicamento), 1, archivo);
  }
}
