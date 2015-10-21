/** Una empresa dispone de un archivo binario de empleados con la siguiente estructura:
  Legajo (número entero)
  Apellido y nombreArch (hasta 40 caracteres)
  Sector (número entero)
  Salario (número real)

  Se solicita desarrollar un programa para realizar las siguientes tareas:
  1.Generar el archivo binario con datos provenientes del teclado
  2.Ordenar el archivo en forma ascendente por sector, utilizando cualquier método de ordenamiento
  3.Realizar un borrado lógico de aquellos registros que pertenezcan al sector 19.
  4.Imprimir un listado que muestre la cantidad total de empleados de cada sector, mostrando además
  los datos del empleado que cobre el mayor salario de cada uno de los sectores.

  NO se conoce la cantidad de sectores, ni el rango de sus números.
**/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  int legajo;
  char nombreArch[41];
  int sector;
  float salario;
}tEmpleado;

typedef struct{
  int sector;
  int cantEmpleados;
}tSector;

int generarBinario(char *nombreArch);
int agregar(char *nombreArch);
int ordenar(char *nombreArch);
void limpiarBuffer(void);
int mostrarArch(char *nombreArch);
void mostrarRegistro(tEmpleado empleado);
  tEmpleado leerRegistro(FILE *in, int numReg);
  void grabarRegistro(FILE *out, int numReg, tEmpleado empleado);

int borrado(char *nombreArch, int sector);
int totalSector(char *nombreArch);

int main(){

  //generarBinario("empleados.dat");
  //agregar("empleados.dat");
  //mostrarArch("empleados.dat");
  //ordenar("empleados.dat");
  //puts("ORDENADO");
  //puts("=====================================");
  //mostrarArch("empleados.dat");
  //borrado("empleados.dat", 19);
  mostrarArch("empleados.dat");
  totalSector("empleados.dat");
  //mostrarArch("empleados.dat");

  return 0;
}
void limpiarBuffer(void){
  while(fgetc(stdin)!='\n');
}
int generarBinario(char *nombreArch){
  //Recibe puntero a nombre de archivo para comenzar a trabajar
  //Utilizando estructura tEmpleado vamos grabando de a 1 registro
  //Hasta que el usuario lo determine con -1
  FILE *archivo;
  tEmpleado empleado;
  int respuesta = 0;

  if((archivo = fopen(nombreArch,"wb")) == NULL){
    printf("No pudo crearse >'%s'", nombreArch);
    return 0;
  }

  do{
    printf("Ingrese nº de legajo: ");
    scanf("%d", &empleado.legajo);
    limpiarBuffer();
    printf("Apellido y nombreArch: ");
    fgets(empleado.nombreArch, 40, stdin);
    printf("Salario: ");
    scanf("%f", &empleado.salario);
    limpiarBuffer();
    printf("Sector: ");
    scanf("%d", &empleado.sector);
    limpiarBuffer();
    fwrite(&empleado, sizeof(tEmpleado), 1, archivo);

    printf("Desea cargar otro empleado? (1: SI | 0: NO): ");
    scanf("%d", &respuesta);
    limpiarBuffer();
  }while(respuesta != 0);

  fclose(archivo);
  return 1;
}
int agregar(char *nombreArch){
  //Recibe puntero a nombre de archivo.
  //Utilizando estructura tEmpleado va solicitando los datos
  //y grabando en el archivo de a 1 registro a la vez
  //Hasta que el usuario lo determine con 0
  FILE *archivo;
  tEmpleado empleado;
  int respuesta = 0;

  if((archivo = fopen(nombreArch,"rb+")) == NULL){
    printf("No pudo crearse >'%s'", nombreArch);
    return 0;
  }
  fseek(archivo, 0, SEEK_END);

  do{
    printf("Ingrese nº de legajo: ");
    scanf("%d", &empleado.legajo);
    limpiarBuffer();
    printf("Apellido y nombreArch: ");
    fgets(empleado.nombreArch, 40, stdin);
    printf("Salario: ");
    scanf("%f", &empleado.salario);
    limpiarBuffer();
    printf("Sector: ");
    scanf("%d", &empleado.sector);
    limpiarBuffer();
    fwrite(&empleado, sizeof(tEmpleado), 1, archivo);

    printf("Desea cargar otro empleado? (1: SI | 0: NO): ");
    scanf("%d", &respuesta);
    limpiarBuffer();
  }while(respuesta != 0);

  fclose(archivo);
  return 1;
}
int ordenar(char *nombreArch){
  //Recibe puntero a nombreArch de archivo
  //Ordena todos los registros de manera ascendentemente por sector
  FILE *archivo;
  tEmpleado empleado1, empleado2;
  int largo, i, j;

  if((archivo = fopen(nombreArch,"rb+")) == NULL){
    printf("No pudo leerse >'%s'", nombreArch);
    return 0;
  }

  fseek(archivo, 0, SEEK_END);
  largo = ftell(archivo) / sizeof(tEmpleado);
  fseek(archivo, 0, SEEK_SET);

  for(i = 0; i < largo - 1; i++){
    for(j = i + 1; j < largo; j++){
      empleado1 = leerRegistro(archivo, i);
      empleado2 = leerRegistro(archivo, j);
      if(empleado1.sector > empleado2.sector){
        grabarRegistro(archivo, i, empleado2);
        grabarRegistro(archivo, j, empleado1);
      }
    }
  }
  fclose(archivo);
  return 1;
}
tEmpleado leerRegistro(FILE *in, int numReg){
  tEmpleado empleado;
  fseek(in, sizeof(tEmpleado) * numReg, SEEK_SET);
  fread(&empleado, sizeof(tEmpleado), 1, in);
  return empleado;
}
void grabarRegistro(FILE *out, int numReg, tEmpleado empleado){
  fseek(out, sizeof(tEmpleado) * numReg, SEEK_SET);
  fwrite(&empleado, sizeof(tEmpleado), 1, out);
}
void mostrarRegistro(tEmpleado empleado){
  empleado.nombreArch[strlen(empleado.nombreArch) -1] = '\0';//Eliminar \n
  printf("%d\n", empleado.legajo);
  printf("%s\n", empleado.nombreArch);
  printf("$%.2f\n", empleado.salario);
  printf("Sector: %d\n", empleado.sector);
  printf("\n");
}
int mostrarArch(char *nombreArch){
  //Recibe puntero a nombreArch de archivo
  //Muestra por pantalla todos los registros almacenados
  FILE *in;
  tEmpleado empleado;

  if((in = fopen(nombreArch,"rb")) == NULL){
    printf("No pudo leerse >'%s'", nombreArch);
    return 0;
  }

  fread(&empleado, sizeof(tEmpleado), 1, in);
  while(!feof(in)){
    empleado.nombreArch[strlen(empleado.nombreArch) -1] = '\0';//Eliminar \n
    printf("%d\n", empleado.legajo);
    printf("%s\n", empleado.nombreArch);
    printf("$%.2f\n", empleado.salario);
    printf("Sector: %d\n", empleado.sector);
    printf("\n");
    fread(&empleado, sizeof(tEmpleado), 1, in);
  }
  fclose(in);
  return 1;
}

int borrado(char *nombreArch, int sector){
  //Recibe puntero a nombre de archivo y numero de sector
  //Realiza borrado logico de los sectores coincidentes
  //dejando en negativo el legajo
  FILE *archivo;
  tEmpleado empleado;
  int numReg = 0;

  if((archivo = fopen(nombreArch,"rb+")) == NULL){
  printf("Error al intentar abrir >\'%s\'", nombreArch);
  return 0;
  }


  fread(&empleado, sizeof(tEmpleado), 1, archivo);
  for(numReg = 0; !feof(archivo); numReg++){
    if(empleado.sector == sector){
      empleado.legajo = empleado.legajo * -1;//Borrado Logico
    fseek(archivo, -1 * (int)sizeof(tEmpleado), SEEK_CUR);
    fwrite(&empleado, sizeof(tEmpleado), 1, archivo);
    fseek(archivo, 0, SEEK_CUR);
    //mostrarRegistro(empleado);
    //printf("NumReg:%d\n", numReg);
    }
    fread(&empleado, sizeof(tEmpleado), 1, archivo);
  }

  fclose(archivo);
  return 1;
}
int totalSector(char *nombreArch){
  /*Generar estructura para guardar cada lectura
  1.Leer el primer registro y comparar con todo el resto de registros
  1.1 si el sector es el mismo cantSector+1
    1.2 Si el salario es mas alto lo guardo, con los datos del empleado
  1.3 muestro el registro
  2. leo el segundo registro y comparo con el resto, el ciclo vuelve a comenzar
  */

  FILE *in;
  tEmpleado empleado, mayorSalario;
  tSector sector;
  int cantReg = 0, i = 0, regActivo = 0;

  if((in = fopen(nombreArch,"rb")) == NULL){
  printf("Error al intentar leer > \'%s\'", nombreArch);
  }

  fseek(in, 0, SEEK_END);
  cantReg = ftell(in) / sizeof(tEmpleado);
  fseek(in, 0, SEEK_SET);

  empleado = leerRegistro(in, regActivo);
  sector.cantEmpleados = 0;
  for(i = 1; i <= cantReg; i++){
    if(empleado.sector == 1){
      sector.sector = empleado.sector;
      sector.cantEmpleados++;
      //printf("%s", empleado.nombreArch);

      if(empleado.salario > mayorSalario.salario){
        mayorSalario = empleado;
      }
    }


    empleado = leerRegistro(in, i);
  }
  printf("Sector: %d CantEmpleados: %d\n", sector.sector, sector.cantEmpleados);
  printf("El mejor salario corresponde a \n%s \r$%.2f\n", mayorSalario.nombreArch, mayorSalario.salario);

  fclose(in);
  return 1;
}
