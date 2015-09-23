#include <stdio.h>
#include <string.h>
struct sFecha{
  int dia, mes, anio;
};//FUNDAMENTAL!!!
struct sAlumno{
  char lu[10];
  char nombre[80];
  char domicilio[80];
  int materias;
  struct sFecha fechaNac;
};
int main(){
  struct sFecha hoy;
  struct sFecha ayer = {22, 9, 2015};//asignación solo valida en la declaración.
  struct sAlumno alumno1, alumno2;
  struct sAlumno curso[50];//vector de estructras
  hoy.dia = 23;
  hoy.mes = 9;
  hoy.anio = 2015;

  strcpy(alumno1.lu, "1000000");//campo vector de char no se puede asigar valores directamente, s necesario utilizar strcpy.
  strcpy(alumno1.nombre, "Luis Arce");
  strcpy(alumno1.domicilio, "Lima 717");
  alumno1.materias = 0;
  alumno1.fechaNac.dia = 1;
  alumno1.fechaNac.mes = 5;
  alumno1.fechaNac.anio = 1990;

  //copia de estructura completa
  alumno2 = alumno1;
  //asignación de estructura cargada a posicion de vector de estructuras
  curso[0] = alumno1;
  //carga de datos a estructura dentro de vector de estructura
  strcpy(curso[1].lu, "1000001");
  strcpy(curso[1].nombre, "Juan Ruiz");
  strcpy(curso[1].domicilio, "Lima 775");
  curso[1].materias = 0;
  curso[1].fechaNac.dia = 25;
  curso[1].fechaNac.mes = 12;
  curso[1].fechaNac.anio = 1993;

  return 0;
}
