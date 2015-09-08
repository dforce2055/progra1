/* Cargar desde el teclado una matriz de enteros de M x N (declarados mediante directivas
#define) e imprimirla por pantalla respetando el formato de la matriz. La impresión deberá
realizarse exclusivamente mediante el uso de punteros. */

/*Hola Diego, en primer lugar cuando realizaste la función matrizFull estas preguntando 
por las variables inicio y fin que son variables globales al igual.  
Las variables globales (variables declaradas fuera de main y todas las funciones del 
programa) está prohibido su uso en programación estructurada.
Por otro lado, no es conveniente la forma que asignaste el último elemento al puntero fin, 
si modificas  los valores de la etiqueta FIL y COL, estarías asignando una dirección que 
no corresponde al último elemento.
La función matrizFull debería recibir los punteros inicio y fin.
La forma de recorrer la matriz mediante punteros en la función mostrarMatriz es correcta 
si la recorres por filas.
*/
#include <stdio.h>
#define FIL 3
#define COL 4
void mostrarMatriz(int *matriz);
int matrizFull(int *matriz);

/*int matriz[FIL][COL] = {1,2,3,4,
                        1,2,3,4,
                        4,3,2,1};*/
int matriz[FIL][COL] = {0};
int *inicio = &matriz[0][0], *fin = &matriz[2][3];

int main(){
  int numero = 0;
  printf("Ingrese números enteros (-1 fin): ");
  scanf("%d", &numero);
  while(numero != -1 && !matrizFull(&matriz[0][0])){
    *inicio = numero;
    inicio++;
    printf("Ingrese números enteros: ");
    scanf("%d", &numero);
  }
  mostrarMatriz(&matriz[0][0]);
  return 0;
}
void mostrarMatriz(int *matriz){
  int fila, columna;
  inicio = matriz;
  for(fila = FIL ; fila > 0; fila--){
    for(columna = COL ; columna > 0; columna--){
      printf("%4d", *inicio);
      inicio++;
    }
    printf("\n");
  }
}
int matrizFull(int *matriz){
  return (inicio == fin)?1:0;
}
