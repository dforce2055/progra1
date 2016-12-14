#include "encabezado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int menu(){
  int opcion = 1;
  puts("***    MENU DE PELICULAS   ***");
  puts("===============================");
  puts("1- Mostrar todas las peliculas ordenas por año");
  puts("2- Mostrar cantidad de peliculas de un año");
  puts("3- Guardar listado de peliculas por genero en disco");
  puts("4- Agregar una nueva pelicula");
  puts("0- Salir");
  scanf("%d", &opcion);
  limpiarBuffer();
 
  return opcion;
}
void mostrarPelicula(Pelicula pelicula){
  printf("Titulo: %s\n", pelicula.titulo);
  printf("Director: %s\n", pelicula.director);
  printf("Genero: %s\n", pelicula.genero);
  printf("Lanzamiento: %d/%d\n", 
          pelicula.mesLanzamiento, 
          pelicula.anioLanzamiento);
  puts("=======================================");
}
void listarPeliculasOrdenadas(Pelicula peliculas[], int cantidad){
  int i, j;
  Pelicula aux1, aux2;

  for(i = 0; i < cantidad -1 ; i++){
    for(j = i+1; j < cantidad; j++){
      aux1 = peliculas[i];
      aux2 = peliculas[j];
      if(aux1.anioLanzamiento > aux2.anioLanzamiento){
        peliculas[i] = aux2;
        peliculas[j] = aux1;
       }
      else if(aux1.anioLanzamiento == aux2.anioLanzamiento){
        if(aux1.mesLanzamiento > aux2.mesLanzamiento){
          peliculas[i] = aux2;
          peliculas[j] = aux1;
        }
      }
      
    }
  }
  for(i = 0; i < cantidad; i++)
    mostrarPelicula(peliculas[i]);
}
Pelicula agregarPelicula(char *titulo, char *director, char *genero, int mes, int anio){
  Pelicula nuevaPelicula;
  strcpy(nuevaPelicula.titulo, titulo);
  strcpy(nuevaPelicula.director, director);
  strcpy(nuevaPelicula.genero, genero);
  nuevaPelicula.mesLanzamiento = mes;
  nuevaPelicula.anioLanzamiento = anio;

  return nuevaPelicula;
}
Pelicula cargarPelicula(){
  char titulo[80], director[50], genero[80];
  int mes = 0, anio = 0;
  Pelicula nuevaPelicula;

  printf("Titulo? ");
  fgets(titulo, 79, stdin);
  borrarSalto(titulo);

  printf("Director? ");
  fgets(director, 79, stdin);
  borrarSalto(director);

  printf("Genero? ");
  fgets(genero, 79, stdin);
  borrarSalto(genero);
  mayus(genero);

  printf("Mes? ");
  scanf("%d", &mes);
  limpiarBuffer();
  
  printf("Año? ");
  scanf("%d", &anio);
  limpiarBuffer();

  nuevaPelicula = agregarPelicula(titulo, director, genero, mes, anio);

  return nuevaPelicula;
}
int guardarEnDisco(Pelicula peliculas[]){
  FILE *archivo = fopen("listador.por.genero.txt", "wt");
  if(!archivo) return 0;
  else{
    int i;
    char genero[80];
    
    printf("Que genero de Pelicula desea guardar?");
    fgets(genero, 79, stdin);
    borrarSalto(genero);
    mayus(genero);
    fprintf(archivo, "Listado de Peliculas por genero '%s'\n", genero);

    for(i = 0; i < CANTIDAD; i++){
      if(strncmp(peliculas[i].genero, genero, 3) == 0)
        fprintf(archivo, "%s\n", peliculas[i].titulo);
    }

  }

  fclose(archivo);
  return 1;
}
void listarPorAnio(Pelicula peliculas[]){
  int anios[100] = {0};
              /*{2016, 2015, 2014, 2013, 2012, 2011, 2010, 
                 2009, 2008, 2007, 2006, 2005, 2004, 2003, 2002, 2001, 2000,                        1999, 1998, 1997, 1996, 1995, 1994, 1993, 1992, 1991, 1990,
                 1989, 1988, 1987, 1986, 1985, 1984, 1983, 1982, 1981, 1980,
                 1979, 1978, 1977, 1976, 1975, 1974, 1973, 1972, 1971, 1970,
                 1969, 1968, 1967, 1966, 1965, 1964, 1963, 1962, 1961, 1960};*/
  
  int i;

  for(i = 0; i < CANTIDAD; i++){
   if(peliculas[i].anioLanzamiento != 0)
    anios[2016 - peliculas[i].anioLanzamiento]++;//sumo 1 en la posicion del vector.
  }

 mostrarAnios(anios, CANTIDAD);
  

}
void mostrarAnios(int anios[], int largo){
  int i;
  for(i = 0; i < largo; i++){
    if(anios[i] != 0){
      printf("año %d : %d Peliculas\n", 2016 - i, anios[i]); 
    }
  }
}

//AUX
void limpiarBuffer(void){
  while(fgetc(stdin) != '\n');
}
void borrarSalto(char *cadena){
  cadena[strlen(cadena)-1] = '\0';
}
void mayus(char *cadena){
  int largo = strlen(cadena), i = 0;
  for(i = 0; i < largo; i++){
    cadena[i] = toupper(cadena[i]);
  }
}