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
}tFraccion;

void limpiarBuffer(void);
int menu(int *opcion);
tFraccion suma(tFraccion f1, tFraccion f2);
tFraccion resta(tFraccion f1, tFraccion f2);
tFraccion multiplicacion(tFraccion f1, tFraccion f2);
tFraccion division(tFraccion f1, tFraccion f2);

int main(){
  tFraccion f1 = {3,5}, f2 = {4,3}, result;
  int opcion;

  /*printf("Ingrese 1er fraccion.\nnumerado: ");
  scanf("%d", &f1.numerador);
  printf("denominador: ");
  scanf("%d", &f1.denominador);
  printf("Ingrese 2da fraccion.\nnumerado: ");
  scanf("%d", &f2.numerador);
  printf("denominador: ");
  scanf("%d", &f2.denominador);*/

  while(menu(&opcion)){
    switch(opcion){
      case 1:
        result = suma(f1, f2);
        system("clear");
        printf("El resultado de la suma es %d/%d\n\n", result.numerador, result.denominador);
        break;
      case 2:
        result = resta(f1, f2);
        system("clear");
        printf("El resultado de la resta es %d/%d\n\n", result.numerador, result.denominador);
        break;
      case 3:
        result = multiplicacion(f1, f2);
        system("clear");
        printf("El resultado de la multiplicacion es %d/%d\n\n", result.numerador, result.denominador);
        break;
      case 4:
        result = division(f1, f2);
        system("clear");
        printf("El resultado de la division es %d/%d\n\n", result.numerador, result.denominador);
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
tFraccion suma(tFraccion f1, tFraccion f2){
  tFraccion result;
  if(f1.denominador == f2.denominador){
    result.numerador = f1.numerador + f2.numerador;
    result.denominador = f1.denominador;
  }else{
    result.numerador = (f1.numerador * f2.denominador) + (f1.denominador * f2.numerador);
    result.denominador = f1.denominador * f2.denominador;
  }
  return result;
}
tFraccion resta(tFraccion f1, tFraccion f2){
  tFraccion result;
  if(f1.denominador == f2.denominador){
    result.numerador = f1.numerador - f2.numerador;
    result.denominador = f1.denominador;
  }else{
    result.numerador = (f1.numerador * f2.denominador) - (f1.denominador * f2.numerador);
    result.denominador = f1.denominador * f2.denominador;
  }
  return result;
}
tFraccion multiplicacion(tFraccion f1, tFraccion f2){
  tFraccion result;
  result.numerador = f1.numerador * f2.numerador;
  result.denominador = f1.denominador * f2.denominador;
  return result;
}
tFraccion division(tFraccion f1, tFraccion f2){
  tFraccion result;
  result.numerador = f1.numerador * f2.denominador;
  result.denominador = f1.denominador * f2.numerador;
  return result;
}
