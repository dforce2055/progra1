/* Realizar una función grabarPromedios() que permita leer el archivo generado en el ejercicio
anterior y generar otro archivo de texto con los promedios de los alumnos con el siguiente
formato:
  Nombre
  Promedio
*/
#include <stdio.h>
#include <string.h>
int main(){
  FILE *in, *out;
  char nombre[80];
  char nota[80];
  int n1, n2;
  float promedio;

  if((in = fopen("notas.txt","rt")) == NULL){
    puts("No pudo leerse notas.txt");
    return 1;
  }
  if((out = fopen("promedios.txt","wt")) == NULL){
    puts("No pudo grabarse promedios.txt");
    return 1;
  }

  fgets(nombre, 79, in);
  while(!feof(in)){
    //nombre[strlen(nombre)-1] = '\0';
    fgets(nota, 79, in);
    sscanf(&nota[4], "%d", &n1);
    fgets(nota, 79, in);
    sscanf(&nota[4], "%d", &n2);
    promedio = (n1 + n2) / 2;
    printf("%s %d %d %.2f\n", nombre, n1, n2, promedio);
    fprintf(out,"%s%.2f\n", nombre, promedio);
    fgets(nombre, 79, in);
  }

 return 0;
}
