/* Escriba un programa que lea una línea de texto mediante la función gets y que la
introduzca en el arreglos s[1OO].Muestre la línea de texto con letras mayúsculas y
con letras minúsculas. */
#include <stdio.h>
#include <string.h>
void cargar(char *cadena, int n);
void mayus(char *cadena);
void minus(char *cadena);
int main(){
  char s[100];
  int i;

  puts("Ingrese una frase de menos de 100 letras:");
  cargar(s, 100);
  mayus(s);
  minus(s);
  return 0;
}
void cargar(char *cadena, int n){
  char c;
  int i;
  c = getchar();
  for(i = 0; c != EOF && c != '\n' && i < n; i++){
    cadena[i] = c;
    c = getchar();
  }
  cadena[i] = '\0';
}
void mayus(char *cadena){
  char *pCadena = cadena;
  for(; *pCadena != '\0'; pCadena++) printf("%c", toupper(*pCadena));
  printf("\n");
}
void minus(char *cadena){
  char *pCadena = cadena;
  for(; *pCadena != '\0'; pCadena++) printf("%c", tolower(*pCadena));
  printf("\n");
}
