#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cabecera.h"
int grabarNotas(Alumno alumno){
  //Recibe un alumno y lo guarda en archivo de texto
  FILE *archivo = fopen("notas.txt", "a+");
  if(!archivo) return 0;
  else{
    fprintf(archivo, "%s\n", alumno.nombre);
    fprintf(archivo, "%d\n", alumno.nota1);
    fprintf(archivo, "%d\n", alumno.nota2);
  }
  fclose(archivo);
  return 1;
}
int grabarPromedios(void){
  //Leer archivo de texto con nombre y notas de alumnos
  //Calcula el promedio y guarda en otro archivo de texto nombre y promedio
  FILE *archivo = fopen("notas.txt", "rt");
  FILE *salida = fopen("promedios.txt", "a+");
  if(!archivo || !salida) return 0;
  else{
    Alumno alumno;
    char linea[80];

    fgets(linea, 79, archivo);
    while(!feof(archivo)){
      //Cargar alumno
      //sscanf(linea, "%s%s", alumno.nombre);
      linea[strlen(linea)-1] = '\0';
      strncpy(alumno.nombre, linea, 30);
      fgets(linea, 79, archivo);
      sscanf(linea, "%d", &alumno.nota1);
      fgets(linea, 79, archivo);
      sscanf(linea, "%d", &alumno.nota2);
      alumno.promedio = promedio(alumno.nota1, alumno.nota2);
      //Grabar promedio
      fprintf(salida, "%s\n", alumno.nombre);
      fprintf(salida, "%.2f\n", alumno.promedio);

      fgets(linea, 79, archivo);
    }
  }
  fclose(archivo);
  fclose(salida);
  return 1;
}
float promedio(int nota1, int nota2){
  return ((nota1 + nota2) / 2);
}
int mostrarMejores(void){
  //Abre archivo de promedios, lee todos los registros y calcula el prom. gral.
  //Vuelve a leer todos los registros y muestra el mejor promedio
  FILE *archivo = fopen("promedios.txt", "rt");
  if(!archivo) return 0;
  else{
    Alumno alumno, mejorPromedio;
    float promedios = 0.0;
    int cantidad = 0;
    char linea[80];

    fgets(linea, 79, archivo);
    while(!feof(archivo)){
      fgets(linea, 79, archivo);//lee linea de nombre pero no lo guarda
      sscanf(linea, "%f", &alumno.promedio);
      promedios += alumno.promedio;
      cantidad++;
      fgets(linea, 79, archivo);
    }
    promedios = promedios / cantidad;
    printf("Se leyeron %d promedios de alumnos. El promedio general es de %.2f\n",
          cantidad, promedios);

    rewind(archivo);
    fgets(linea, 79, archivo);
    while(!feof(archivo)){
      linea[strlen(linea)-1] = '\0';
      strncpy(alumno.nombre, linea, 30);
      fgets(linea, 79, archivo);
      sscanf(linea, "%f", &alumno.promedio);
      if(alumno.promedio > promedios){
        mejorPromedio = alumno;
      }
      fgets(linea, 79, archivo);
    }
    printf("El alumno con el mejor promedio es %s -> promedio: %.2f",
          mejorPromedio.nombre, mejorPromedio.promedio);
  }

  fclose(archivo);
  return 1;
}
