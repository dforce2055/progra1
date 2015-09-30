#include <stdio.h>
typedef struct{
  int lu;
  char nombre[80];
  char domicilio[80];
}tAlumno;
void limpiarBuffer(void);
int main(){
  FILE *archivo;
  tAlumno alumno;

  archivo = fopen("alumnos.dat","wb");//write binari
  if(archivo == NULL){
    puts("No se puede crear el archivo");
    return 1;
  }

  puts("LU?(-1 para terminar) ");
  scanf("%d", &alumno.lu);
  while(alumno.lu != -1){
    limpiarBuffer();
    puts("Nombre? ");
    fgets(alumno.nombre, 80, stdin);
    puts("Domicilio? ");
    fgets(alumno.domicilio, 80, stdin);
    //guarda la estructura en el archivo
    fwrite(&alumno, sizeof(alumno), 1, archivo);

    puts("LU?(-1 para terminar) ");
    scanf("%d", &alumno.lu);
  }
  fclose(archivo);
  return 0;
}
void limpiarBuffer(void){
  //Luego de cada scanf() es necesario limpiar la cola del teclado
  //para eliminar el salto de linea "\n"
  while(fgetc(stdin)!='\n');
}
