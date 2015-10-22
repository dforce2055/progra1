/* leer consiga.txt */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 15
void nacionalidad(char *nombre, char nacionalidad[40]);
int grabarNacionalidad(char nombre[][40]);

int main(){
  char nombres[SIZE][40] = {  "Arslanian, Gustavo",
                              "Rossini, Giuseppe",
                              "Pérez, Juan",
                              "Smith, John",
                              "Pérez, Andrés",
                              "Ortiz, Cecilia",
                              "Constantini, Cecilia",
                              "Cortez, Hector",
                              "Ñoñoez, Bigote",
                              "Darian, Moico",
                              "Dolorez, Monicar",
                              "Ortiz Pérez, Diego",
                              "Nostra Cosani, Daniel",
                              "Milini, Hector",
                              "Ian, Bebeto"
                              };

  grabarNacionalidad(nombres);

  return 0;
}
void nacionalidad(char *nombre, char nacionalidad[40]){
  //Recibe puntero a cadena con "Apellido, Nombre"
  //Retorna puntero a cadena con Nacionalidad en MAYUS
  //char nacionalidad[40];
  int i, largo;

  for(i = 0; nombre[i] != ','; i++){
    ;
  }
  nacionalidad[0] = toupper(nombre[i-3]);
  nacionalidad[1] = toupper(nombre[i-2]);
  nacionalidad[2] = toupper(nombre[i-1]);
  nacionalidad[3] = '\0';

  if(strcmp(nacionalidad, "IAN") == 0){
    strcpy(nacionalidad, "ARMENIA");
  }else if(strcmp(nacionalidad, "INI") == 0){
     strcpy(nacionalidad,"ITALIA");
    }else if(strcmp(nacionalidad+1, "EZ") == 0){//COMPARO SOLO LAS 2 ULTIMAS LETRAS
      strcpy(nacionalidad,"ESPAÑA");
      }else strcpy(nacionalidad,"descartar");//descartar
}
int grabarNacionalidad(char nombre[][40]){
  //Recibe matriz de nombres
  //Recorre el arreglo completo, determina la nacionalidad del nombre
  //y lo guarda en el archivo correspondiente
  FILE *ARMENIA,*ITALIA,*SPAIN;
  char nacion[40];
  int i = 0;

  if((ARMENIA = fopen("ARMENIA.TXT","wt")) == NULL){
    puts("No pudo abrirse >\'ARMENIA.TXT\'");
    return 0;
  }
  if((ITALIA = fopen("ITALIA.TXT","wt")) == NULL){
    puts("No pudo abrirse >\'ITALUA.TXT\'");
    return 0;
  }
  if((SPAIN = fopen("SPAIN.TXT","wt")) == NULL){
    puts("No pudo abrirse >\'SPAIN.TXT\'");
    return 0;
  }

  for(i = 0; i < SIZE; i++){
    nacionalidad(nombre[i], nacion);
    if(strcmp(nacion,"ARMENIA") == 0){
      fputs(nombre[i],ARMENIA);
      fputs("\n",ARMENIA);
    }
    if(strcmp(nacion,"ITALIA") == 0){
      fputs(nombre[i],ITALIA);
      fputs("\n",ITALIA);
    }
    if(strcmp(nacion,"ESPAÑA") == 0){
      fputs(nombre[i],SPAIN);
      fputs("\n",SPAIN);
    }
  }

  fclose(ARMENIA);
  fclose(ITALIA);
  fclose(SPAIN);
  return 1;
}
