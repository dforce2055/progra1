#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encabezado.h"
int main(){
  Pelicula peliculas[CANTIDAD] = {0};
  int opcion = 1, posicion = 10;


  peliculas[0] = agregarPelicula("Rocky I", "Silvester Stallone", "ACCION", 1, 1976);
  peliculas[1] = agregarPelicula("Rocky II", "Silvester Stallone", "ACCION", 2, 1979);
  peliculas[2] = agregarPelicula("Rocky III", "Silvester Stallone", "ACCION", 10, 1983);
  peliculas[3] = agregarPelicula("Rocky IV", "Silvester Stallone", "ACCION", 3, 1990);
  peliculas[4] = agregarPelicula("Rocky V", "Silvester Stallone", "ACCION", 10, 1994);
  peliculas[5] = agregarPelicula("Rocky VI", "Silvester Stallone", "ACCION", 12, 2006);
  peliculas[6] = agregarPelicula("The Shawshank Redemption", "Frank Darabont", "DRAMA", 10, 1994);
  peliculas[7] = agregarPelicula("The Godfather", "Francis Ford Coppola", "DRAMA", 10, 1972);
  peliculas[8] = agregarPelicula("The Godfather: Part II", "Francis Ford Coppola", "DRAMA", 10, 1974);
  peliculas[9] = agregarPelicula("The Dark Knight", "Christopher Nolan", "ACCION", 10, 2008);

  

  while(opcion = menu()){
     switch (opcion){
      case 0:
        exit;
        break;
      case 1: 
        puts("Listado de Peliculas Ordenadas por año");
        listarPeliculasOrdenadas(peliculas, CANTIDAD);
        system("pause"); system("cls");
        break;
      case 2: 
        puts("Listado de Peliculas por año");
        listarPorAnio(peliculas);
        system("pause"); system("cls");
        break;
      case 3: 
        puts("Guardar listado de peliculas en disco");
        if(guardarEnDisco(peliculas)){
          puts("*****************************");
          puts("***  Peliculas GUARDADAS  ***");
          puts("*****************************");
        }else{
          puts("*****************************");
          puts("***   ERROR AL GUARDAR    ***");
          puts("*****************************");
        }
        system("pause");system("cls");
        break;
      case 4:
        peliculas[posicion] = cargarPelicula();
        posicion++;
        system("pause"); system("cls");
        break;
      default:  
        system("cls");
        puts("*****************************");
        puts("***    Opcion invalida    ***");
        puts("*****************************");
        system("pause");
        break;
    }
  
  }
  
  return 0;
}
