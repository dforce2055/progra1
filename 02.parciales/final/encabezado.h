#ifndef _FINALPROGRA1_
#pragma warning(disable:4996)
#define CANTIDAD 20
typedef struct Pelicula{
  char titulo[80];
  char director[50];
  char genero[80];
  int mesLanzamiento, anioLanzamiento;
}Pelicula;

//funciones
int menu();
void mostrarPelicula(Pelicula pelicula);
void listarPeliculasOrdenadas(Pelicula peliculas[], int cantidad);
Pelicula agregarPelicula(char *titulo, char *director, char *genero, int mes, int anio);
Pelicula cargarPelicula();
int guardarEnDisco(Pelicula peliculas[]);
void listarPorAnio(Pelicula peliculas[]);
void mostrarAnios(int anios[], int largo, Pelicula peliculas[]);



//AUX
void limpiarBuffer();
void borrarSalto(char *cadena);
void mayus(char *cadena);
#endif//_FINALPROGRA1_
