/* Ingresar a través del teclado una frase cualquiera, la que podrá tener hasta
un máximo de 100 palabras. Luego se solicita desarrollar un programa que
realice las siguientes tareas.
  1. Mostrar la frase por pantalla, pero encerrado entre paréntesis aquellas
  palabras donde la cantidad de vocales supere el 50% del total de los
  caracteres de la misma.
  2. Imprimir por pantalla las palabras que cumplan con la condición indicada
  en el punto anterior, mostrándolas en orden alfabético y sin paréntesis.
Nota:
  # Se considera palabra a un conjunto de uno o más caracteres seguidos de uno o
    más espacios al principio o al final.
  # Las vocales con tilde no se consideran.
*/
#define PALABRAS 100
#define LETRAS 35 //cantidad máxima de caracteres en una palabra de español
#define MAX 1000 //cantidad máxima de caracteres en una frase
#include <stdio.h>
#include <string.h>
int cargarFrase(char *cadena, int n);
int parentesis(char *cadena, char palabras[PALABRAS][LETRAS]);
void mostrarPalabra(char *cadena);
void mostrarPalabras(char palabras[PALABRAS][LETRAS], int cantPalabras);
int cantVocales(char *palabra);
void ordenarPalabras(char palabras[PALABRAS][LETRAS], int cantPalabras);
int main(){
  char frase[MAX];
  char palabras[PALABRAS][LETRAS];
  int cantPalabras = 0;

  puts("Ingrese una frase:");
  cargarFrase(frase, MAX);
  cantPalabras = parentesis(frase, palabras);
  ordenarPalabras(palabras, cantPalabras);
  puts("\n\nPalabras ordenadas:");
  puts("====================");
  mostrarPalabras(palabras, cantPalabras);

  return 0;
}
int cargarFrase(char *cadena, int n){
  //guarda en arreglo de caracteres los caracteres introducidos por el usuario
  //uno x uno, hasta que palabras < PALABRAS o hasta que se llegue al límite del
  //arreglo.
  //Devuelve la cantidad de palabras almacenadas.
  int i, palabras = 0;
  char c;

  c = getchar();
  if(c == EOF){
    cadena[0] = '\0';
    return 0;
  }

  if(c == '\n'){
    i = 0;
  }else{
    cadena[0] = c;
    i = 1;
    palabras++;
    }

  for( ;palabras < PALABRAS && (c = getchar()) != EOF && i < n-1 && c != EOF && c != '\n'; i++){
    cadena[i] = c;
    if(isspace(c) && !isspace(cadena[i-1])){
      palabras++;
    }

  }
  cadena[i] = '\0';

  return palabras;
}
int parentesis(char *cadena, char palabras[PALABRAS][LETRAS]){
  //Guarda en arreglo de cadenas las palabras que cumplan con la condición de
  //mayor cantidad de vocales.
  //Imprime por pantalla la frase con aquellas palabras que cumplen la condición
  //encerradas entre paréntesis.
  char cFrase[MAX];
  char auxPalabras[LETRAS];
  char *pCadena = cadena;
  int i = 0, cantPalabras = 0;

  strcpy(cFrase, cadena);//guarda una copia de la frase original
  pCadena = strtok(cadena, " ");//separa la cadena en palabras
  puts("\nPalabras entre ():");
  puts("==================");
  while(pCadena != NULL){
    if(cantVocales(pCadena)){
      strcpy(palabras[i], pCadena);//guarda en arreglo de palabras las palabras que cumplen la condición cantVocales
      i++;
      printf("(");
      mostrarPalabra(pCadena);
      printf(") ");
    }else printf("%s ", pCadena);
    pCadena = strtok(NULL, " ");
  }
  printf("\n");
  cantPalabras = i;
  strcpy(cadena, cFrase);//devuelvo frase a su estado original
  return cantPalabras;
}
void mostrarPalabra(char *cadena){
  for(; *cadena != '\0'; cadena++) printf("%c", *cadena);
}
void mostrarPalabras(char palabras[PALABRAS][LETRAS], int cantPalabras){
  int i;
  for(i = 0; i < cantPalabras; i++) printf("%d:\t%s\n", i+1, palabras[i]);
}
int cantVocales(char *palabra){
  //Detecta la cantidad de vocales en una cadena, si la cantidad de vocales
  //supera el 50% de la cantidad de caracteres, retorna 1, en caso negativo 0
  char *pPalabra = palabra;
  int i, vocales = 0;
  for(i = 0; *pPalabra != '\0'; pPalabra++, i++){
    switch(*pPalabra){
      case 'a': vocales++; break;
      case 'A': vocales++; break;
      case 'e': vocales++; break;
      case 'E': vocales++; break;
      case 'i': vocales++; break;
      case 'I': vocales++; break;
      case 'o': vocales++; break;
      case 'O': vocales++; break;
      case 'u': vocales++; break;
      case 'U': vocales++; break;
      }
  }
  return (vocales > (i/2))?1:0;
}
void ordenarPalabras(char palabras[PALABRAS][LETRAS], int cantPalabras){
  //ordena arreglo de palabras
  char auxPalabras[LETRAS];
  int i, j;

  for(i = 0; i < cantPalabras; i++){
    for(j = 0; j < cantPalabras-1; j++){
      if(strcmp(palabras[j], palabras[j+1]) > 0){
        strcpy(auxPalabras, palabras[j]);
        strcpy(palabras[j], palabras[j+1]);
        strcpy(palabras[j+1], auxPalabras);
      }
    }
  }
}
