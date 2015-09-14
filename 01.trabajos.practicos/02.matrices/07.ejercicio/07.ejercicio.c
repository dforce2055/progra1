/* 7.	Dada una matriz cargada utilizando la función del ejercicio anterior, 
realizar funciones para:
a)	Almacenar en un vector la lluvia promedio caida en cada uno de los meses 
b)	Almacenar en un vector la lluvia promedio caida durante cada uno de los años
c)	Mostrar los resultados obtenidos en los puntos a y b 
*/
#include <stdio.h>
#include <string.h>
#define FIL 14
#define COL 12
void lluvia(int matriz[FIL][COL]);
void mostrarLLuvia(int *matriz);
void mostrarPromedio(float *promedio, char *tipo);
void promMensual(float *promedio, int matriz[FIL][COL]);
void promAnual(float *promedio, int matriz[FIL][COL]);
int main(){
  srand(time(NULL));
  int matriz[FIL][COL] = {0};
  float promedioMensual[14] = {0};
  float promedioAnual[14] = {0};
  
  lluvia(matriz);
  mostrarLLuvia((int *)matriz);
  
  promMensual(promedioMensual, matriz);
  mostrarPromedio(promedioMensual, "mensual");
  
  promAnual(promedioAnual, matriz);
  mostrarPromedio(promedioAnual, "anual");
  
  
  return 0;
}
void lluvia(int matriz[FIL][COL]){
  int anio, mes;
  
  for(anio = 0; anio < FIL; anio++){
    for(mes = 0; mes < COL; mes++){
      matriz[anio][mes] = rand() % 1000; //(999 - 0 + 1) + 0
    }
  }
}
void mostrarLLuvia(int *matriz){
  int *pFin = matriz + (FIL*COL);
  int i, anio = 1995;
  
  printf("%10s%6s%6s%6s%6s%6s%6s%6s%6s%6s%6s%6s\n",
      "Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic");
  
  for( i = 0 ; matriz < pFin; matriz++){
    if(i == 0){
      printf("%4d", anio++);
      i++;
    } 
    printf("%6d", *matriz);
    i++;
    
    if(i == 13){
      printf(" ml.\n"); 
      i = 0;
    } 
  }
}
void mostrarPromedio(float *promedio, char *tipo){
  float *pFin = promedio + FIL;
  char mensaje[256] = "Promedio ";
  
  strcat(mensaje, tipo);
  puts(mensaje);
  if(tipo == "mensual"){
    printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s\n",
      "Ene","Feb","Mar","Abr","May","Jun","Jul","Ago","Sep","Oct","Nov","Dic");
    for(; promedio < pFin - 2; promedio++) printf("%8.2f",*promedio);
  }else if(tipo == "anual"){
    printf("%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s%8s\n",
      "1995","1996","1997","1998","1999","2000","2001","2002","2003","2004","2005","2006","2007","2008");
    for(; promedio < pFin; promedio++) printf("%8.2f",*promedio);
    }else puts("El parametro de tiempo ingresado es incorrecto.");
  printf("\n");
}
void promMensual(float *promedio, int matriz[FIL][COL]){
  int mes = 0, anio, i;
  float suma = 0;
  
  for(mes = 0; mes < 12; mes++){
    for(anio = 0; anio < FIL; anio++){//desplaza hacia abajo
      suma += matriz[anio][mes];
    }
    promedio[mes] = suma / FIL;
    suma = 0;
  }
}
void promAnual(float *promedio, int matriz[FIL][COL]){
  int mes = 0, anio, i;
  float suma = 0;
  
  for(anio = 0; anio < FIL; anio++){
    for(mes = 0; mes < 12; mes++){//desplaza a la derecha
      suma += matriz[anio][mes];
    }
    promedio[anio] = suma / 12;
    suma = 0;
  }
}