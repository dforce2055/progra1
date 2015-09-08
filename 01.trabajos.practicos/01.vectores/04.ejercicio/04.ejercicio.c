/*4. Realizar una función que devuelva la posición en que se haya
un valor dado mediante el método de búsqueda binaria. En caso que
no lo encuentre devolver -1,.*/
#include <stdio.h>
#pragma warning(disable:4996)
#define SIZE 15
/* prototipos de funciones */
int busquedaBinaria(const int b[], int claveDeBusqueda, int bajo, int alto);
void despliegaEncabezados(void);
void despliegaLinea(const int b[], int bajo, int cen, int alt);
int main(){
  int a[SIZE], i, llave, resultado;
  /* crea los datos */
  for(i = 0; i < SIZE; i++){
    a[i] = 2 * i;
  }
  printf("introduzca un número entre 0 y 28: ");
  scanf("%d", &llave);
  despliegaEncabezados();
  resultado = busquedaBinaria(a, llave, 0, SIZE-1);

  if(resultado != -1){
    printf("\n%d se encuentra en el elemento %d del arreglo\n", llave, resultado);
  }else printf("\n[%d] no se encuentra\n", llave);

  return 0;
}
/* función para realizar la búsqueda binaria dentro de un arreglo */
int busquedaBinaria(const int b[], int claveDeBusqueda, int bajo, int alto){
  int central;
  while(bajo <= alto){
    central = (bajo + alto) / 2;
    /* despliega el subarreglo utilizado en este ciclo */
    despliegaLinea(b, bajo, central, alto);
    /* si claveDeBusqueda coincide con el elemento central, devuelve central */
    if(claveDeBusqueda == b[central]){
      return central;
    }
    /* si la claveDeBusqueda es menor que el elemento central, establece el nuevo valor de alto */
    else if(claveDeBusqueda < b[central]){
      alto = central -1; /* busca en la mitad inferior del arreglo*/
    }
    /* Si claveDeBusqueda es mayor que el elemento central, establece el nuevo valor para bajo */
    else bajo = central + 1;/* busca en la mitad superior del arreglo */
  }
  return -1;
}
void despliegaEncabezados(void){
  int i;
  printf("\nSubindices:\n");
  for(i = 0; i < SIZE; i++){
    printf("%3d", i);
  }
  printf("\n");
  /* muestra una línea de caracteres - */
  for(i = 0; i <= 4 * SIZE; i++){
    printf("-");
  }
  printf("\n");
}
/* Imprime una línea de salida que muestra la parte actual del arreglo que se está procesando */
void despliegaLinea(const int b[], int baj, int cen, int alt){
  int i;
  for(i = 0; i < SIZE; i++){
    if(i < baj || i > alt){
      printf("  ");
    }else if(i == cen){/* despliega el elemento central */
      printf("%3d*", b[i]); /* marca el valor central */
    }else{/* despliega otros valores en el subarreglo */
        printf("%3d", b[i]);
      }
  }
  printf("\n");
}
