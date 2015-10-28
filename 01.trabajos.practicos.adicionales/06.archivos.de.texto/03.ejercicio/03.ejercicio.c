/*Escribir una función mostrarMejores() que lea el archivo del ejercicio anterior y permita
mostrar los alumnos cuyo promedio supere al promedio general del curso. */
#include <stdio.h>
void mostrarMejores(FILE *archivo);
main(){
  FILE *archivo;

  if((archivo = fopen("promedios.txt","rt"))== NULL){
    puts("No pudo abrirse >\'promedios.txt\'");
    return 1;
  }

  mostrarMejores(archivo);

  fclose(archivo);
  return 0;
}
void mostrarMejores(FILE *archivo){
  char nombre[80], cadena[80];
  float promedio = 0.0, promedioGeneral = 0.0;
  int i = 0;

  fgets(nombre, 79, archivo);
  while(!feof(archivo)){
    fgets(cadena, 79, archivo);
    sscanf(cadena, "%f", &promedio);
    promedioGeneral += promedio;
    i++;
    fgets(nombre, 79, archivo);
  }
  promedioGeneral = promedioGeneral / i;
  printf("Promedio General: %.2f\n", promedioGeneral);

  rewind(archivo);
  fgets(nombre, 79, archivo);
  while(!feof(archivo)){
    fgets(cadena, 79, archivo);
    sscanf(cadena, "%f", &promedio);
    if(promedio > promedioGeneral){
      printf("Nombre:%sPromedio:%2.f\n", nombre, promedio);
    }
    fgets(nombre, 79, archivo);
  }
}
