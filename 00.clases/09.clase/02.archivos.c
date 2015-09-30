#include <stdio.h>
typedef struct{
  int lu;
  char nombre[80];
  char domicilio[80];
}tAlumno;
int main(){
  FILE *archivo;
  tAlumno alumno;

  archivo = fopen("alumnos.dat","rb");//write binari
  if(archivo == NULL){
    puts("No se puede leer el archivo");
    return 1;
  }

  fread(&alumno, sizeof(alumno), 1, archivo);
  while(!feof(archivo)){
    if(alumno.lu < 1000000)
      printf("%d-%s\n", alumno.lu, alumno.nombre);
    fread(&alumno, sizeof(alumno), 1, archivo);
  }
  fclose(archivo);
  return 0;
}
