#include "encabezado.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

Cheque cargarCheque0(char *linea){
  ///Recibe una linea, retorna un cheque cargado
  Cheque chequeNuevo;
  char fecha[12];
  cpycad(chequeNuevo.nombre, linea, 0, N);
  cpycad(fecha, linea, 17, 6);
  cpyfech(&chequeNuevo, fecha);
  cpycad(chequeNuevo.domicilio, linea, 28, M);

  return chequeNuevo;
}
Cheque cargarCheque1(FILE *archivo){
  ///Recibe puntero a Archivo
  ///Lee registros hasta encontrar un caracter '#', lee 3 registros
  ///Carga un Cheque con los registros leidos
  ///Modifica puntero de Archivo a la ultima posición leida
  ///Retorna Cheque cargado
  Cheque chequeNuevo;
  char fecha[12], linea[3][80], c;
  int i = 0, j = 0;

  c = fgetc(archivo);
  for(i = 0; i < 3; i++){
    for(j = 0; c != '#' && !feof(archivo); j++){
      linea[i][j] = c;
      c = fgetc(archivo);
    }
    linea[i][j] = '\0';
    c = fgetc(archivo);
  }
  if((strlen(linea[2])) > 4){
    fseek(archivo, (1*sizeof(char)*-1), SEEK_CUR);//retorno 1 caracter
    strncpy(chequeNuevo.nombre, linea[0], N-1);
    strncpy(fecha, linea[1], 11);
    cpyfech(&chequeNuevo, fecha);
    strncpy(chequeNuevo.domicilio, linea[2], M-1);
  }
  return chequeNuevo;
}
Cheque cargarCheque2(FILE *archivo){
  ///Recibe puntero a Archivo
  ///Lee 2 primeras posiciones, indica cantidad de caracteres a leer, lee 3 registros
  ///Carga un Cheque con los registros leidos
  ///Modifica puntero de Archivo a la ultima posición leida
  ///Retorna Cheque cargado
  Cheque chequeNuevo;
  char linea[3][80], c[3];
  int numero = 0;

  //Nombre
  c[0]= fgetc(archivo); c[1]= fgetc(archivo); c[2] = '\0';
  sscanf(c, "%d", &numero);
  fgets(linea[0], numero+1, archivo);
  strncpy(chequeNuevo.nombre, linea[0], N-1);
  //fecha
  c[0]= fgetc(archivo); c[1]= fgetc(archivo); c[2] = '\0';
  sscanf(c, "%d", &numero);
  fgets(linea[1], numero+1, archivo);
  cpyfech(&chequeNuevo, linea[1]);
  //Domicilio
  c[0]= fgetc(archivo); c[1]= fgetc(archivo); c[2] = '\0';
  sscanf(c, "%d", &numero);
  fgets(linea[2], numero+1, archivo);
  strncpy(chequeNuevo.domicilio, linea[2], M-1);

  return chequeNuevo;
}
int cpycad(char *destino, char *origen, int desde, int hasta){
  ///Copia en la cadena destino, desde la cadena origen en la posicion desde
  ///la cantidad de caracters indicados hasta.
  int i;
  for(i = 0; i < hasta; i++){
    *destino = origen[desde];
    desde++;
    destino++;
  }
  destino--;
  *destino = '\0';
  return (destino == origen)?1:0;
}
int cpyfech(Cheque *cheque, char *fecha){
  ///Recibe una cadena fecha, la transforma a enteros y la guarda en el Cheque
  ///pasado por referencia
  char dia[3], mes[3], anio[3];

  dia[0] = fecha[0]; dia[1] = fecha[1]; dia[2] = '\0';
  mes[0] = fecha[2]; mes[1] = fecha[3]; mes[2] = '\0';
  anio[0] = fecha[4]; anio[1] = fecha[5]; anio[2]  = '\0';

  sscanf(dia, "%d", &cheque->dd);
  sscanf(mes, "%d", &cheque->mm);
  sscanf(anio, "%d", &cheque->aa);

  return 0;
}

void guardarCheque(Cheque cheque){
  //Recibe Cheque por valor y lo guarda en archivo binario
  //El archivo debe existir previamente, aunque este vacio
  FILE *archivoSalida = fopen("salida.bin", "a+");
  if(!archivoSalida) puts("error al intentar guardar archivo binario");
  else fwrite(&cheque, sizeof(Cheque), 1, archivoSalida);

  fclose(archivoSalida);
}
void mostrarCheques(void){
  ///Muestra todos los cheques guardados en el archivo binario
  FILE *archivo = fopen("salida.bin", "r");
  Cheque cheque;
  if(!archivo) puts("error al intentar abrir archivo binario");
  else{
      fread(&cheque, sizeof(Cheque), 1, archivo);
      while(!feof(archivo)){
        puts(cheque.nombre);
        printf("%d/%d/%d\n", cheque.dd, cheque.mm, cheque.aa);
        printf("Domicilio: %s\n", cheque.domicilio);
        puts("================================================");
        fread(&cheque, sizeof(Cheque), 1, archivo);
      }
  }

  fclose(archivo);
}
