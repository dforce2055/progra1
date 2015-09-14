/* 6.	Hacer una función que cargue una matriz con números al azar entre 0 y 999,
la cual representa la lluvia mensual caída del año 1995 al 2008. Las filas 
representan los años y las columnas correponden a los 12 meses del año */
//Función Aleatoria
//rand () % (Valor final – Valor inicial + 1) + Valor inicial
#include <stdio.h>
#define FIL 14
#define COL 12
void lluviAnual(int matriz[FIL][COL]);
void mostrar(int *matriz);
int main(){
  srand(time(NULL));
  int matriz[FIL][COL] = {0};
  
  lluviAnual(matriz);
  mostrar((int *)matriz);
  
  return 0;
}
void lluviAnual(int matriz[FIL][COL]){
  int anio, mes;
  
  for(anio = 0; anio < FIL; anio++){
    for(mes = 0; mes < COL; mes++){
      matriz[anio][mes] = rand() % 1000; //(999 - 0 + 1) + 0
    }
  }
}
void mostrar(int *matriz){
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