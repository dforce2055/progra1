/* Escriba un programa que lea cuatro cadenas que representen valores en punto flotante,
que convierta las cadenas a valores double, que sume los valores y que imprima el total
de los cuatro valores.*/
#define FIL 4
#define COL 10
#include <stdio.h>
#include <string.h>
void cargar(char cadenas[FIL][COL]);
void stringToFloat(float numeros[], char cadenas[FIL][COL]);
float sumar(float numeros[]);
int main(){
  char palabras[FIL][COL];
  float numeros[FIL], suma;

  cargar(palabras);
  stringToFloat(numeros, palabras);
  suma = sumar(numeros);

  printf("La suma total de los valores ingresados es %.2f", suma);
  return 0;
}
void cargar(char cadenas[FIL][COL]){
  int i;
  puts("Cargar valores flotantes");
  for(i = 0; i < FIL; i++){
    printf("Ingrese %d valor: ", i);
    fgets(cadenas[i], COL, stdin);
  }
}
void stringToFloat(float numeros[], char cadenas[FIL][COL]){
  int i;
  float *pNumeros = numeros;
  for(i = 0; i < FIL; i++){
    sscanf(cadenas[i], "%f", pNumeros);
    pNumeros++;
  }
}
float sumar(float numeros[]){
  int i;
  float suma = 0;
  for(i = 0; i < FIL; i++){
    suma += numeros[i];
  }
  return suma;
}
