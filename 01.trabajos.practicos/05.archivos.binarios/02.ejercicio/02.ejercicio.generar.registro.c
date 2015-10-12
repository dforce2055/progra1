/* Leer 02.ejercicio.consigna.txt*/
#include <stdio.h>
#include <string.h>
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

void limpiarBuffer(void);
void guardarCadena(char *cadena, int max);
void inicializarArch(FILE *archivo);
int solicitarRespuesta(void);
void cargarRegistro(tMedicamento *medicamento);
void grabarRegistro(FILE *archivo, tMedicamento *medicamento);
void mostrar(FILE *archivo);
int compFechas(tFecha fecha1, tFecha fecha2);
int main(){
  FILE *archivo;
  FILE *archNoVencidos;
  tMedicamento medicamento, medVacio;
  tFecha fechaTestigo={1,2016};
  tFecha fechaVencimiento;
  int respuesta = 1;

  if((archivo = fopen("base.medicamento.dat","wb+")) == NULL){
    puts("El archivo no pudo crearse.");
    return 1;
  }
  if((archNoVencidos = fopen("medicamentos.no.vencidos.dat","wb+")) == NULL){
    puts("El archivo no pudo crearse.");
    return 1;
  }
  inicializarArch(archivo);
  //inicializarArch(archivo);
  puts("Bienvenido a la carga de Medicamentos:");
  puts("======================================");

  while(respuesta){
    cargarRegistro(&medicamento);
    grabarRegistro(archivo, &medicamento);

    //comparo Fechas de vencimiento
    fechaVencimiento.mes = medicamento.fechVen.mes;
    fechaVencimiento.anio = medicamento.fechVen.anio;
    if(compFechas(fechaVencimiento, fechaTestigo) == 0)
      fwrite(&medicamento, sizeof(tMedicamento), 1, archNoVencidos);

    respuesta = solicitarRespuesta();
  }

  fclose(archivo);
  fclose(archNoVencidos);
  return 0;
}
void limpiarBuffer(void){
  while(fgetc(stdin)!='\n');
}
void inicializarArch(FILE *archivo){
  //Recibe un archivo y genera 130 registros vacios
  tMedicamento medicamento;
  strcpy(medicamento.lote, "");
  strcpy(medicamento.nombre, "");
  strcpy(medicamento.codBar, "");
  medicamento.costo = 0.0;
  medicamento.stock = 0;
  medicamento.fechVen.mes = 0;
  medicamento.fechVen.anio = 0;
  int i = 0;
  for(i = 0; i < 130; i++)
    fwrite(&medicamento, sizeof(tMedicamento), 1, archivo);


}
int solicitarRespuesta(void){
  int respuesta = 0;
  do{
    puts("Desea cargar otro registro(?)\n[1 : SI | 0 : NO]");
    scanf("%d", &respuesta);
    limpiarBuffer();
  }while(respuesta != 1 && respuesta != 0);

  return respuesta;
}
void eliminarSalto(char *cadena){
  int largo = 0;
  largo = strlen(cadena) -1;
  cadena[largo] = '\0';

}
void cargarRegistro(tMedicamento *medicamento){
  int largo = 0;
  puts("Ingrese nº de lote:");
  fgets(medicamento->lote, 7, stdin);
  eliminarSalto(medicamento->lote);

  puts("Codigo de barras:");
  fgets(medicamento->codBar, 21, stdin);
  eliminarSalto(medicamento->codBar);

  puts("Nombre del medicamento:");
  fgets(medicamento->nombre, 40, stdin);
  eliminarSalto(medicamento->nombre);

  puts("Costo:");
  scanf("%f", &medicamento->costo);
  limpiarBuffer();
  puts("Stock:");
  scanf("%d", &medicamento->stock);
  limpiarBuffer();
  puts("Fecha de vencimiento: Mes/anio");
  scanf("%d %d", &medicamento->fechVen.mes, &medicamento->fechVen.anio);
}
void grabarRegistro(FILE *archivo, tMedicamento *medicamento){
  //Recibe un archivo y un registro cargado. Lo graba en la posicion
  //Indicada por lote.
  int numReg;

  sscanf(medicamento->lote, "%d", &numReg);
  fseek(archivo,numReg * sizeof(tMedicamento), SEEK_SET);
  fwrite(medicamento, sizeof(tMedicamento), 1, archivo);
}
void mostrar(FILE *archivo){
  tMedicamento medicamento;
  rewind(archivo);
  fread(&medicamento, sizeof(tMedicamento), 1, archivo);
  while(!feof(archivo)){
    if(strlen(medicamento.nombre) != 0){
      printf("Lote: %s\n", medicamento.lote);
      printf("Codigo: %s\n", medicamento.codBar);
      printf("Nombre: %s\n", medicamento.nombre);
      printf("Costo: %f\n", medicamento.costo);
      printf("Stock: %d\n", medicamento.stock);
      printf("Mes:%d Año:%d\n", medicamento.fechVen.mes, medicamento.fechVen.anio);
    }
    fread(&medicamento, sizeof(tMedicamento), 1, archivo);
  }
}
int compFechas(tFecha fecha1, tFecha fecha2){
  //Compara 2 fechas, si la 1 fecha es menor o igual retorna 1
  //Sino retorna 0
  if(fecha1.anio > 0 && fecha1.anio <= fecha2.anio){
    if(fecha1.anio < fecha2.anio) return 1;
    if(fecha1.anio == fecha2.anio){
      if(fecha1.mes <= fecha2.mes) return 1;
    }
  }
  return 0;
}
