/*
 * Ejercicio integrador: Ordenar un archivo binario
 * */
#include <stdio.h>
/* prototipos */
int leerregistro(FILE * f, int numreg);
void grabarregistro(FILE * f, int numreg, int dato);

int main(){
	FILE *arch;
	int i, j, cantreg, reg1, reg2;
	
	arch = fopen("enteros.dat", "rb+");
	
	if(arch == NULL){
		printf("No se puede abrir el archivo\n");
		return 1;
	}
	
	fseek(arch, 0, SEEK_END);
	cantreg = ftell(arch) / sizeof(int);
	
	/* Método de Selección */
	for(i = 0; i < cantreg -1; i++){
		for(j = i + 1; j < cantreg; j++){
			reg1 = leerregistro(arch, i);
			reg2 = leerregistro(arch, j);
			if(reg1 > reg2 ){
				grabarregistro(arch, i, reg2);
				grabarregistro(arch, j, reg1);
			}
		}
	}
	fclose(arch);
	
	return 0;
}

int leerregistro(FILE * f, int numreg)
{
	int dato;
	fseek(f, numreg * sizeof(int), SEEK_SET);
	fread(&dato, sizeof(dato), 1, f);
	return dato;
}

void grabarregistro(FILE * f, int numreg, int dato)
{
	fseek(f, numreg * sizeof(int), SEEK_SET);
	fwrite(&dato, sizeof(dato), 1, f);
}
