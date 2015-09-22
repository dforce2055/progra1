/* Escriba un programa que lea cuatro cadenas que representen enteros, que convierta las
cadenas a enteros, que sume los valores, y que imprima el total de los cuatro valores.*/
#define FIL 4
#define COL 10
#include <stdio.h>
#include <string.h>
void cargar(char cadenas[FIL][COL]);
void stringToInt(int numeros[], char cadenas[FIL][COL]);
int sumar(int numeros[]);
int main(){
  char cadenas[FIL][COL] = {0};
  int numeros[4], suma = 0;

  cargar(cadenas);
  stringToInt(numeros, cadenas);
  suma = sumar(numeros);

  printf("La suma total es %d", suma);
  return 0;
}
void cargar(char cadenas[FIL][COL]){
  int i;
  for(i = 0; i < FIL; i++){
    printf("Ingrese %d numero: ", i);
    fgets(cadenas[i], COL, stdin);
  }
}
void stringToInt(int numeros[], char cadena[FIL][COL]){
  int i;
  int *pNumeros = numeros;
  //paso de cadena a enteros
  for(i = 0; i < 4; i++){
    sscanf(cadena[i], "%d", pNumeros);
    pNumeros++;
  }
}
int sumar(int numeros[]){
  int i, suma = 0;
  for(i = 0; i < 4; i++) suma += numeros[i];
  return suma;
}
