/* leer consiga.txt */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void nacionalidad(char *nombre, char nacionalidad[40]);

int main(){
  char nombres[8][21] = { "Arslanian, Gustavo",
                          "Rossini, Giuseppe",
                          "Pérez, Juan",
                          "Smith, John",
                          "Pérez, Andrés",
                          "Ortiz, Cecilia",
                          "Constantini, Cecilia",
                          "Cortez, Hector"};
  char nacion[40];
  //puts(nombres[1]);
  nacionalidad(nombres[0], nacion);
  puts(nacion);
  return 0;
}
void nacionalidad(char *nombre, char nacionalidad[40]){
  //Recibe puntero a cadena con "Apellido, Nombre"
  //Retorna puntero a cadena con Nacionalidad en MAYUS
  //char nacionalidad[40];
  int i, largo;


  for(i = 0; nombre[i] != ','; i++){

  }
  //printf("La coma en %s se encontro en posicion %d\n", nombre, i);
  //printf("%c%c%c", nombre[i-3], nombre[i-2], nombre[i-1]);
  nacionalidad[0] = toupper(nombre[i-3]);
  nacionalidad[1] = toupper(nombre[i-2]);
  nacionalidad[2] = toupper(nombre[i-1]);
  nacionalidad[3] = '\0';
  //puts(nacionalidad);
  if(strcmp(nacionalidad, "IAN") == 0){
    strcpy(nacionalidad, "ARMENIA");
  }else if(strcmp(nacionalidad, "INI") == 0){
     strcpy(nacionalidad,"ITALIA");
    }else if(strcmp(nacionalidad+1, "EZ") == 0){//COMPARO SOLO LAS 2 ULTIMAS LETRAS
      strcpy(nacionalidad,"ESPAÑA");
      }else puts("Descartar");


}
