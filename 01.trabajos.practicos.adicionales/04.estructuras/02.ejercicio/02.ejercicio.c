/* Realizar un programa que declare una estructura llamada cuadrilatero con tres campos
enteros: Tipo, Lado1, Lado2. El programa deberá leer los tres datos del teclado e invocar a
una función que reciba la estructura como parámetro y devuelva la superficie del
cuadrilátero, de acuerdo con la siguiente tabla:
0: Cuadrado     Sup=Lado1 * Lado1
1: Rectángulo   Sup=Lado1 * Lado2
2: Rombo        Sup=(Lado1 * Lado2) / 2 (en este caso los lados corresponden a la
                medida de las diagonales)
3: Paralelogramo Sup=Lado1 * Lado2
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char tipo[14];
  int lado1, lado2;
  char formular[256];
}tCuadrilatero;

void limpiarBuffer(void);
void cargar(tCuadrilatero *cuadrilatero);
int calcSuperficie(tCuadrilatero *cuadrilatero);
int main(){
  tCuadrilatero cuadrilatero;
  int superficie = 0;

  cargar(&cuadrilatero);
  superficie = calcSuperficie(&cuadrilatero);
  printf("La superficie de %s es: %d\nFormula: %s", cuadrilatero.tipo, superficie, cuadrilatero.formular);

  return 0;
}
void limpiarBuffer(void){
  //Limpia la cola de teclado luego de utilizar scanf()
  //para eliminar cualquier '\n'
  while(fgetc(stdin) != '\n');
}
void cargar(tCuadrilatero *cuadrilatero){
  //Recibe por referencia una estructura tCuadrilatero
  //Solicita la carga de datos por teclado
  //Los guarda en la estructura
  int opcion = 0;
  do{
    printf("Cargue valores para el cuadrilatero\n");
    printf("Tipo: 1.Cuadrado, 2.Rectangulo, 3.Rombo, 4.Paralelogramo\n");
    scanf("%d", &opcion);
    limpiarBuffer();
    switch(opcion){
      case 1: strcpy(cuadrilatero->tipo,"cuadrado"); break;
      case 2: strcpy(cuadrilatero->tipo,"rectangulo"); break;
      case 3: strcpy(cuadrilatero->tipo,"rombo"); break;
      case 4: strcpy(cuadrilatero->tipo,"paralelogramo"); break;
      default: puts("La opcion ingresada es incorrecta\n"); opcion = 0; break;
    }
  }while(opcion == 0);
  printf("Ingrese el valor de Lado1: ");
  scanf("%d", &cuadrilatero->lado1);
  limpiarBuffer();
  printf("Ingrese el valor de Lado2: ");
  scanf("%d", &cuadrilatero->lado2);
  limpiarBuffer();
}
int calcSuperficie(tCuadrilatero *cuadrilatero){
  //Recibe una estructura tCuadrilatero por referencia
  //Segun su tipo, aplica formula para calcular superficie
  //y retorna el resultado
  if(strcmp(cuadrilatero->tipo, "cuadrado") == 0){
    strcpy(cuadrilatero->formular,"Lado x Lado");
    return cuadrilatero->lado1 * cuadrilatero->lado1;
  }
  if(strcmp(cuadrilatero->tipo, "rectangulo") == 0){
    strcpy(cuadrilatero->formular,"Base x Altura");
    return cuadrilatero->lado1 * cuadrilatero->lado2;
  }
  if(strcmp(cuadrilatero->tipo, "rombo") == 0){
    strcpy(cuadrilatero->formular,"(Base x Altura) % 2");
    return (cuadrilatero->lado1 * cuadrilatero->lado2) / 2;
  }
  if(strcmp(cuadrilatero->tipo, "paralelogramo") == 0){
    strcpy(cuadrilatero->formular,"Base x Altura");
    return cuadrilatero->lado1 * cuadrilatero->lado2;
  }
}
