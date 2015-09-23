Miercoles 23 de Septiembre de 2015
Temas: Estructuras. Arreglos de estructuras. Pasaje como parámetro.

Estructuras:
===========
Una estructura es un conjunto de datos agrupados bajo un solo nombre, a cada uno
de estos datos, se lo denomina campo, y por lo tanto una estructura es un conjunto
de campos.

Declaración antes del main:
--------------------------
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
Diferencias entre struct y vector
  · acceso a los campos
  · Alamacena diferentes tipos de datos (char, int, float, struct)

PROHIBIDO COMPARAR ESTRUCTURAS!
Se compara campo x campo, para saber si 2 estructuras son iguales

REFORZAR CON MÁS TEORIA

Pasaje de estructuras como parámetro:
====================================
1. Pasaje de campos por valor;
void imprimirMaterias(int cuantas){
  printf("Materias aprobadas: %d", cuantas);
}
imprimirMaterias(alumno1.materias);

2. Pasaje de campos por referencia:
void incrementarMaterias(int *cuantas){
  *cuantas = *cuantas+1;
}
incrementarMaterias(&alumno1.materias);

3. Pasaje de estructura por valor:
void imprimirAlumno(struct sAlumno.quien){
  printf("LU: %s\nNombre: %s\n", quien.lu, quien.nombre);
}
imprimirAlumno(alumno1);

4. Pasaje de estructura por referencia:
void inicializarAlumno(struct alumno *quien){
  srtcpy((*quien).lu,"");
  srtcpy((*quien).nombre,"");
  srtcpy((*quien).domicilio,"");
  (*quien).materias = 0;
  (*quien).fechaNac.dia = 0;
  (*quien).fechaNac.mes = 0;
  (*quien).fechaNac.anio = 0;
}
//SINTÁXIS MÁS AMIGABLE Operador flecha ->
void inicializarAlumno(struct alumno *quien){
  strcpy(quien->lu, "");
  strcpy(quien->nombre, "");
  strcpy(quien->domicilio, "");
  quien->materias = 0;
  quien->fechaNac.dia = 0;
  quien->fechaNac.mes = 0;
  quien->fechaNac.anio = 0;
}
inicializarAlumno(&alumno1);


Operador flecha ->:
==================
[puntero a estructura]->[campo]

typedef:
=======
1.
struct sFecha{
  int dia, mes, anio;
};
typedef struct sFecha tFecha;//sinonimos
----------------------------
struct sFecha hoy;
tFechar ayer;

2.
typedef struct sFecha{
  int dia, mes, anio;
}tFecha;
----------------------------
struct sFecha hoy;
tFechar ayer;

3.//Este es el más simple
typedef struct{
  int dia, mes, anio;
}tFecha;
--------------------------
tFecha hoy, ayer;

Operador sizeof():
=================
Cuantos bytes ocupa en memoria una variable o tipo de dato.
int a, b;
a = sizeof(char);
b = sizeof(a);
printf("%d - %d", a, b);
