/* El critero para definir si un registro es valido o no, va a ser el campo
numero de legajo, si es negativo, esta listo para ser borrado.
A los registros que queremos borrar, lo multiplicamos por -1, si queremos
activarlo de nuevo, lo multiplicamos por -1 nuevamente*/
#include <stdio.h>
typedef struct{
  int lu;
  char nombre[80];
  char domicilio[80];
}tAlumno;
int main(){
  FILE *archivo;
  tAlumno alumno;

  archivo = fopen("alumnos.dat","rb+");
  if(archivo == NULL){
    puts("Error al intentar abrir el archivo 'alumnos.dat'");
    return 1;
  }

  fread(&alumno, sizeof(alumno), 1, archivo);
  while(!feof(archivo)){
    if(alumno.lu < 1000000){
      alumno.lu = -1 * alumno.lu;
      fseek(archivo, -1 * (int)sizeof(alumno), SEEK_CUR);//desplazo 1 lugar a la izquierda (*-1) || cast de la devolucion de sizeof, que devuleve entero sin signo
      fwrite(&alumno, sizeof(alumno), 1, archivo);//guardo el registro modificado
      fseek(archivo, 0, SEEK_CUR);//
    }
    fread(&alumno, sizeof(alumno), 1, archivo);
  }

  fclose(archivo);
  return 0;
}
