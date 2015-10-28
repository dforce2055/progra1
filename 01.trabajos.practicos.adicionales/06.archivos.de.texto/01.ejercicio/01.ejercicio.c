/* Desarrollar una función grabarNotas() que permita grabar en un archivo de texto las notas
de los parciales de cada alumno con el siguiente formato:
  Nombre
  Nota1
  Nota2 */
#include <stdio.h>
#include <string.h>
#include <time.h>
typedef struct{
  char nombre[80];
  int nota1, nota2;
}tNotas;
int grabarNotas(FILE *archivo, tNotas notas);
int main(){
  srand(time(NULL));
  FILE *out;
  tNotas alumno;
  int i;

  if((out = fopen("notas.txt","wt")) == NULL){
    puts("No pudo abrirse >\'notas.txt\'");
    return 1;
  }

  for(i = 0; i < 10; i++){
    puts("Nombre?: ");
    fgets(alumno.nombre, 79, stdin);
    alumno.nota1 = rand()%10;
    alumno.nota2 = rand()%10;
    grabarNotas(out, alumno);
  }

  fclose(out);
  return 0;
}
int grabarNotas(FILE *archivo, tNotas notas){
  fputs(notas.nombre, archivo);
  fprintf(archivo, "N1: %d\n", notas.nota1);
  fprintf(archivo, "N2: %d\n", notas.nota2);
}
