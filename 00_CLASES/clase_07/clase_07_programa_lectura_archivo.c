/* Lectura */
#include <stdio.h>

typedef struct salumno{
	int lu;
	char nombre[80];
	char domicilio[80];
	}talumno;

int main(){
	talumno alumno1;
	FILE *archivo;
	
	archivo = fopen("alumnos.dat", "rb"); // w * r
	
	if(archivo == NULL){
		puts("No se puede abrir el archivo"); // crear * abrir
		return 1;
	}
	
	fread(&alumno1, sizeof(alumno1), 1, archivo);//Error frecuente, sino leemos se procesan 2 veces los datos al finalizar el archivo
	
	while(!feof(archivo)){
		if(alumno1.lu < 1000000){
			printf("LU: %d\nNombre: %s\n", alumno1.lu, alumno1.nombre);
		}
		fread(&alumno1, sizeof(alumno1), 1, archivo); 
	}
	
	fclose(archivo);
	
	return 0;
}
