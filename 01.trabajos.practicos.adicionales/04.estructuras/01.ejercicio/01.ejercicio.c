/* Escribir un programa que utilice una estructura para representar números racionales
(compuestos por un numerador y un denominador enteros), y permita operar con los mismos
a través de funciones. Las operaciones a implementar son la suma, la resta, la multiplicación
y la división de números racionales. */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  int numerador, denominador;
}tNumRacionales;

void limpiarBuffer(void);
int menu(int *opcion);
int suma(tNumRacionales numeros);
int resta(tNumRacionales numeros);
int multiplicacion(tNumRacionales numeros);
int division(tNumRacionales numeros);

int main(){
  tNumRacionales numeros;
  int opcion, result = 0;

  printf("Ingrese 2 valores para operar.\n1: ");
  scanf("%d", &numeros.numerador);
  printf("2: ");
  scanf("%d", &numeros.denominador);

  while(menu(&opcion)){
    switch(opcion){
      case 1: printf("\nEl resultado de la suma es %d\n", result = suma(numeros)); break;
      case 2: printf("\nEl resultado de la resta es %d\n", result = resta(numeros)); break;
      case 3: printf("\nEl resultado de la multiplicacion es %d\n", result = multiplicacion(numeros)); break;
      case 4:
        result = division(numeros);
        if(result != -1) printf("\nEl resultado de la division es %d\n", result);
        else puts("No se puede dividor por 0!");
        break;
      default: puts("El valor ingresado es incorrecto"); break;
    }
  }

  return 0;
}
void limpiarBuffer(void){
  //Limpia la cola de teclado luego de utilizar scanf()
  //para eliminar cualquier '\n'
  while(fgetc(stdin) != '\n');
}
int menu(int *opcion){
  //Recibe un puntero a entero, muesta por pantalla las opciones
  //retora un entero y guarda en el puntero la opcion elegida por el usuario
  puts("Que operacion desea realizar con los numeros?");
  puts("1. Suma");
  puts("2. Resta");
  puts("3. Multiplicacion");
  puts("4. Division");
  puts("0. Salir");
  scanf("%d", opcion);
  limpiarBuffer();
  return *opcion;
}
int suma(tNumRacionales numeros){
  return numeros.numerador + numeros.denominador;
}
int resta(tNumRacionales numeros){
  return numeros.numerador - numeros.denominador;
}
int multiplicacion(tNumRacionales numeros){
  return numeros.numerador * numeros.denominador;
}
int division(tNumRacionales numeros){
  if(numeros.denominador == 0) return -1;
  else return numeros.numerador / numeros.denominador;
}
