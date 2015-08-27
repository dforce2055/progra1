/* Grabación */
#include <stdio.h>

typedef struct salumno{
	int lu;
	char nombre[80];
	char domicilio[80];
	}talumno;

int main(){
	talumno alumno1;
	FILE *archivo;
	
	archivo = fopen("alumnos.txt", "wb");
	
	if(archivo == NULL){
		puts("No se puede crear el archivo");
		return 1;
	}
	
	printf("LU?(-1 para terminar)");
	scanf("%d", &alumno1.lu);
	
	while(alumno1.lu != -1){
		fflush(stdin); //borra caracteres pendientes de procesamiento
		printf("Nombre?");
		gets(alumno1.nombre);
		printf("Domicilio?");
		gets(alumno1.domicilio);
		
		fwrite(&alumno1, sizeof(alumno1), 1, archivo);
		printf("Lu?(-1 para terminar)");
		scanf("%d", &alumno1.lu);
	}
	fclose(archivo);
	
	return 0;
}
