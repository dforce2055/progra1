/*
 Ingresar una frase cualquiera. y segun la opcion modificar la frase.
  0 cambiarlo a mayuscula.
  1 cambiarlo a minuscula.
  2 Tipo oracion. La primera letra en Mayuscula lo que sigue en minuscula.
  3 Tipo titulo en todas las palabras la primera letra a mayuscula.
  4 Intercambiar, si esta en minuscula pasarlo a mayuscula y viceversa
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char *modFrase(char *frase, int opcion);
void mayusculas(char *pFrase);
void minusculas(char *pFrase);
void oracion(char *pFrase);
void titulo(char *pFrase);
void invertir(char *pFrase);
int menu(void);
int main(){
  char cadena[256];
  int opcion;

  puts("Ingrese una cadena de texto");
  fgets(cadena, 250, stdin);
  opcion = menu();
  modFrase(cadena, opcion);
  puts(cadena);

  return 0;
}
int menu(void){
  int opcion;
  printf("\n¿Que desea hacer con la cadena:\n");
  printf("\n===============================\n");
  printf("0. Pasar todo a mayusculas\n");
  printf("1. Pasar todo a minusculas\n");
  printf("2. Tipo oracion. La primera letra en Mayuscula lo que sigue en minuscula\n");
  printf("3. Tipo titulo en todas las palabras la primera letra a mayuscula\n");
  printf("4. Intercambiar mayusculas por minusculas\n");
  scanf("%d", &opcion);
  return opcion;
}
char *modFrase(char *frase, int opcion){
  char *pFrase = frase;

  switch(opcion){
    case 0:
      mayusculas(pFrase);
      break;
    case 1:
      minusculas(pFrase);
      break;
    case 2:
      oracion(pFrase);
      break;
    case 3:
      titulo(pFrase);
      break;
    case 4:
      invertir(pFrase);
      break;
  }

  return frase;
}

void mayusculas(char *pFrase){
  //opcion: 0
  for( ; *pFrase != '\0'; pFrase++) *pFrase = toupper(*pFrase);
  *pFrase = '\0';
}
void minusculas(char *pFrase){
  //opcion: 1
  for( ; *pFrase != '\0'; pFrase++) *pFrase = tolower(*pFrase);
  *pFrase = '\0';
}
void oracion(char *pFrase){
  //opcion: 2
  for(; *pFrase == ' '; pFrase++);//mientras sea un espacion copia en mod
  *pFrase = toupper(*pFrase);//primera letra en mayúscula
  pFrase++;
  minusculas(pFrase);
}
void titulo(char *pFrase){
  //opcion: 3
  while(*pFrase != '\0'){
    while(isspace(*pFrase)) pFrase++;//mientras sea un ' ' corro el puntero

    if(isalpha(*pFrase)){//si el 1er elemento luego de ultimo ' '
      *pFrase = toupper(*pFrase);
      pFrase++;
    }

    while(!isspace(*pFrase) && *pFrase != '\0'){//mientras no sea un espacio ni fin de cadena tolower()
      *pFrase = tolower(*pFrase);
      pFrase++;
    }
  }
}
void invertir(char *pFrase){
  //opción: 4
  for(; *pFrase != '\0'; pFrase++){
    if(isupper(*pFrase)) *pFrase = tolower(*pFrase);//si es mayúscula pasar a minúscula
    else *pFrase = toupper(*pFrase);//sino pasar a mayúscula
  }
}
