/*
 * Clase #06
 * Martes 10 de Septiembre de 2013
 * Estructuras. Arreglos de estructuras. Pasaje como parámetro.
 * ***************************************************************
 * 
 * Definición de estructura:
 * -------------------------
 * Una estructura es un conjunto de datos agrupados bajo un solo nombre, estos datos
 * pueden ser de distintos tipos. Y cada uno de ellos recibe el nombre de campo o de miembro.
 * 
 * Se declaran fuera de toda función (main), para que puedan ser utilizadas por todo el programa.
 * Los nombres de estructuras llamados sFecha, la s al principio indica que es una estrctura (struc)
 * Es fundamental agregar un ";" después de la llave de cierre
 * 
 * */
#include <stdio.h>
#include <string.h>
struct sfecha{
	int dia, mes, anio;
}; /* FUNDAMENTAL ";" */
struct salumno{
	char lu[10]; /* todo numero que no vaya a funcionar en operaciones aritmeticas, es conveniente guardarlos en tipo de dato char */
	char nombre[80];
	char domicilio[80];
	int materias; /* cantidad de materias aprobadas */
	struct sfecha fechanac; /* llama a la estructura de arriba, importante llamarla "struct<nombre_de_estructura>" */
};
int main(){
	struct sfecha hoy;
	struct sfecha ayer = {9, 9, 2013};
	struct salumno alumno1, alumno2;
	struct salumno curso[50]; /* vector de alumnos */
	
	/*inicializamos la estructura hoy */
	hoy.dia = 10;
	hoy.mes = 9;
	hoy.anio = 2013;
	/*inicializamos la estructura alumno1 */
	/* al no poder asignar una cadena de caracteres a un arreglo se utiliza strcpy*/
	strcpy(alumno1.lu,"1000000");
	strcpy(alumno1.nombre,"Luis Arias");
	strcpy(alumno1.domicilio,"Lima 717");
	alumno1.materias = 0;
	alumno1.fechanac.dia = 1;
	alumno1.fechanac.mes = 5;
	alumno1.fechanac.anio = 1985;
	
	/*inicializamos la estructura alumno2, copiando la estructura de alumno1 */
	alumno2 = alumno1;
	
	/* cargamos datos en vector curso */
	curso[0] = alumno1; /* la asignación es posible, ya que son todas variables del mismo dato, es decir todas estructuras */
	/* cargamos a mano, los datos del alumno */
	strcpy(curso[1].lu,"1000001");
	strcpy(curso[1].nombre,"Angel Ruiz");
	strcpy(curso[1].domicilio,"Lima 755");
	curso[1].materias = 0;
	curso[1].fechanac.dia = 25;
	curso[1].fechanac.mes = 12;
	curso[2].fechanac.anio = 1992;
}
/* Operador punto / operador de pertenencia:
 * <variable de estructura>.<campo>
 * */
/* 
 * Pasaje de estructuras como párametro
 * ************************************
 * 1- Pasaje de campos por valor
 * 2- Pasaje de campos por referencia
 * 3- Pasaje de estructuras por valor
 * 4- Pasaje de estructuras por referencia
 * */
/* 1- Pasaje de campos por valor */
void imprimirmaterias(int cuantas)
{
	printf("Materias aprobadas: %d\n", cuantas);
}
/* llamada a la función */
imprimirmaterias(alumno1.materias);

/* 2- Pasaje de campos por referencia */
void incrementarmaterias(int *cuantas)
{
	*cuantas= *cuantas+1;
}
/* llamada a la función */
incrementarmaterias(&alumno1.materias); /* el ampersan es escencial para indicar la dirección en memoria a modificar */

/* 3- Pasaje de estructuras por valor */
void imprimiralumno(struc salumno quien)
{
	printf("Nombre:%s\nLU:%s\n", quien.nombre, quien.lu);
}
/* llamada a la función */
incrementarmaterias(alumno1);

/* 4- Pasaje de estructuras por referencia */
void inicializaralumno(struct salumno*quien)
{
	strcpy((*quien).lu"");
	strcpy((*quien).nombre"");
	strcpy((*quien).domicilio"");
	(*quien).materias = 0;
	(*quien).fechanac.dia = 0;
	(*quien).fechanac.mes = 0;
	(*quien).fechanac.anio = 0;
}
/* llamada a la función */
inicializaralumno(&alumno1);

/* código más limpio, deberia ser una buena practica de programación escribir las funciones de la siguiente manera */
void inicializaralumno(struct salumno*quien)
{
	strcpy(quien->lu,"");
	strcpy(quien->nombre,"");
	strcpy(quien->domicilio,"");
	quien->materias = 0;
	quien->fechanac.dia = 0;
	quien->fechanac.mes = 0;
	quien->fechanac.anio = 0;
}
/* Se utilizael operador "Flecha"/Operador de puntero a estructur 
 * <puntero a estructura>-><campo>
 * 
 * typedef:
 * ********
 * Crea sinonimos para tipos de datos que ya fueron definidos. algo asi como un "bind"
 * 
 * */
/* Declaración #1 */
struct sfecha{
	int dia,mes,anio;
};
typedef struct sfecha tfecha;
/* llamada #1 */
struc sfecha hoy;
tfecha ayer;

/* Declaración #2 */
typedef struc sfecha{
	int dia,mes,anio;
}tfecha;
/* llamada #2 */
struc sfecha hoy;
tfecha ayer;

/* Declaración #3 */
typedef struc{
	int dia,mes,anio;
}tfecha;
/* llamada #3 */
tfecha hoy;

/* Operador sizeof:
 * **************
 * int a,b;
 * b = sizeof(int);
 * a = sizeof(b);
 * 
 * */
