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
#include <stdio.h>
#include <string.h>
void mostrar(char *cadena);
void mostrarPalabra(char *cadena);
int cargarFrase(char *cadena, int n);
int cantVocales(char *palabra);
int main(){
  char frase[1000];

  puts("Ingrese una frase:");
  cargarFrase(frase, 1000);

  mostrar(frase);

  return 0;
}
void mostrarPalabra(char *cadena){
  for(; *cadena != '\0'; cadena++) printf("%c", *cadena);
}
int cantVocales(char *palabra){
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
void mostrar(char *cadena){
  char cFrase[1000];
  char palabras[100][100];
  char *pCadena = cadena;
  int i = 0;

  strcpy(cFrase, cadena);
  pCadena = strtok(cadena, " ");//separa la cadena en palabras
  while(pCadena != NULL){
    if(cantVocales(pCadena)){
      strcpy(palabras[i], pCadena);
      i++;
      printf("(");
      mostrarPalabra(pCadena);
      printf(") ");
    }else printf("%s ", pCadena);
    pCadena = strtok(NULL, " ");
  }

  strcpy(cadena, cFrase);
}
int cargarFrase(char *cadena, int n){
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

  for( ;palabras < 100 && i < n-1 && (c = getchar()) != EOF && c != '\n'; i++){
    cadena[i] = c;
    if(isspace(c) && !isspace(cadena[i-1])){
      palabras++;
    }
  }
  cadena[i] = '\0';

  return palabras;
}

