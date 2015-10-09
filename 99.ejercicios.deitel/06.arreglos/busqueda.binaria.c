/*
 * Figura 6.19: fig06_19.c
 * Búsqueda binaria dentro de un arreglo
 * */
#include <stdio.h>
#define TAMANIO 15

/* prototipos de funciones */
int busquedaBinaria(const int b[], int claveDeBusqueda, int bajo, int alto);
void despliegaEncabezados(void);
void despliegaLinea(const int b[], int bajo, int cen, int alt);
int main(){
  int a[TAMANIO];
  int i, llave, resultado;

  for(i = 0; i < TAMANIO; i++){
    a[i] = 2 * i;
  }

  printf("introduzca un número entre 0 y 28: ");
  scanf("%d", &llave);

  despliegaEncabezados();
  resultado = busquedaBinaria(a, llave, 0, TAMANIO-1);

  if(resultado != -1) printf("\n%d se encuentra en el elemento %d del arreglo\n", llave, resultado);
  else printf("\n%d no se encuentra\n", llave);

  return 0;
}
int busquedaBinaria(const int b[], int claveDeBusqueda, int bajo, int alto){
  int central;
  while(bajo <= alto){
    central = (bajo + alto) / 2;
    despliegaLinea(b, bajo, central, alto);

    if(claveDeBusqueda == b[central])     return central;
    else if(claveDeBusqueda < b[central]) alto = central -1;
    else                                  bajo = central + 1;
  }
  return -1;
}
/* imprime un encabezado para la salida */
void despliegaEncabezados(void){
  int i;
  printf("\nSubindices:\n");
  /* Muestra el encabezado de la columna */
  for(i = 0; i < TAMANIO; i++){
    printf("%3d", i);
  }
  printf("\n");
  /* muestra una línea de caracteres - */
  for(i = 0; i <= 4 * TAMANIO; i++){
    printf("-");
  }
  printf("\n");
}
/* Imprime una línea de salida que muestra la parte actual del arreglo que se está procesando */
void despliegaLinea(const int b[], int baj, int cen, int alt){
  int i;
  /* ciclio a través del arreglo completo */
  for(i = 0; i < TAMANIO; i++){
    /* desplieg espacios si se encuentra fuera del rango actual del subarreglo */
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
