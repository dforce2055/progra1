/*Ejercicio integrado para manipular archivos.
 Es ejercicio lee los registros desde el archivo:
 /home/dforce/Facultad/3.4.071_programacion_1/00.clases/09.clase/alumnos.dat
*/
#include <stdio.h>
typedef struct{
  int lu;
  char nombre[80];
  char domicilio[80];
}tAlumno;
tAlumno leerRegistro(FILE *archivo, int numReg);
void grabaRegistro(FILE *archivo, int numReg, tAlumno alumno);
void mostrarRegistrosPorPantalla(FILE *archivo);
int main(){
  FILE *archivo;
  tAlumno alumno1, alumno2;
  int i, j, cantReg;

  archivo = fopen("alumnos.dat", "rb+");
  if(archivo == NULL){
    puts("Error al intentar abrir el archivo.");
    return 1;
  }
  puts("Archivo desordenado:");
  mostrarRegistrosPorPantalla(archivo);
  fseek(archivo, 0, SEEK_END);
  cantReg = ftell(archivo) / sizeof(tAlumno);

  //Metodo de selección
  for(i = 0; i < cantReg - 1; i++){
    for(j = i + 1; j < cantReg; j++){
      alumno1 = leerRegistro(archivo, i);
      alumno2 = leerRegistro(archivo, j);
      if(alumno1.lu > alumno2.lu){
        grabaRegistro(archivo,i, alumno2);
        grabaRegistro(archivo,j, alumno1);
      }
    }
  }

  puts("Archivo ordenado:");
  mostrarRegistrosPorPantalla(archivo);
  fclose(archivo);
  return 0;
}
tAlumno leerRegistro(FILE *archivo, int numReg){
  tAlumno alumno;
  fseek(archivo, sizeof(tAlumno) * numReg, SEEK_SET);
  fread(&alumno, sizeof(tAlumno), 1, archivo);
  return alumno;
}
void grabaRegistro(FILE *archivo, int numReg, tAlumno alumno){
  fseek(archivo, sizeof(alumno) * numReg, SEEK_SET);
  fwrite(&alumno, sizeof(alumno), 1, archivo);
}

void mostrarRegistrosPorPantalla(FILE *archivo){
  tAlumno alumno;
  rewind(archivo);

  fread(&alumno, sizeof(alumno), 1, archivo);
  while(!feof(archivo)){
    printf("LU: %d\tNombre: %s\tDomicilio: %s\n", alumno.lu, alumno.nombre, alumno.domicilio);
    fread(&alumno, sizeof(alumno), 1, archivo);
  }
}

