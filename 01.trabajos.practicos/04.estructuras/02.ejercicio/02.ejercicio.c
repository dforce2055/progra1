/* 2. Desarrollar las siguientes funciones para manejar “tiempos”:
a)  Ingresar un horario (horas, minutos, segundos) desde teclado, validando
  que sea correcto
b)  Calcular la diferencia de horas. En el caso que la primera hora es
  mayor a la segunda, considerar que la primera hora corresponde a la
  hora del día anterior. La diferencia en horas no supera las 24 horas.
c)  Generar una cadena con formato hh:mm:ss
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct{
  int dia, mes, anio;
}tFecha;
typedef struct{
  int hora, minuto, segundo;
}tHora;
typedef struct{
  char codBar[22];
  char nombre[80];
  float precio;
  int stock;
  tFecha fechaStock;
}tProducto;
void ingresarHorario(tHora *horario);
void compararHorario(tHora horario1, tHora horario2, tHora *resultado);
int main(){
  tHora horario1 = {22,30,01}, horario2 = {23,39,01}, resultado = {0,0,0};
  char horario[9];

  //ingresarHorario(&horario1);
  //ingresarHorario(&horario2);
  //printf("\nHorario: %d:%d:%d", horario1.hora, horario1.minuto, horario1.segundo);
  compararHorario(horario1, horario2, &resultado);
  printf("La diferencia en horas es h:%d m:%d s:%d\n", resultado.hora, resultado.minuto, resultado.segundo);
  sprintf(horario,"%d",resultado.hora);
  strcat(horario,":");

  puts(horario);


  return 0;
}
void ingresarHorario(tHora *horario){
  int h, m, s;
  puts("Ingrese horario:");
  do{
    puts("ingrese hora correctamente(0-23):");
    scanf("%d", &h);
  }while(h > 23 || h < 0);
  do{
    puts("ingrese minuto correctamente(0-59):");
    scanf("%d", &m);
  }while(m > 59 || m < 0);
  do{
    puts("ingrese segundos correctamente(0-59):");
    scanf("%d", &s);
  }while(s > 59 || s < 0);
  horario->hora = h;
  horario->minuto = m;
  horario->segundo = s;
}
void compararHorario(tHora horario1, tHora horario2, tHora *resultado){

 if(horario1.hora > horario2.hora){
   resultado->hora = horario1.hora - horario2.hora;
 }
 if(horario1.minuto > horario2.minuto){
   resultado->minuto = horario1.minuto - horario2.minuto;
 }
 if(horario1.segundo > horario2.segundo){
   resultado->segundo = horario1.segundo - horario2.segundo;
 }

 if(horario1.hora < horario2.hora){
  resultado->hora = horario2.hora - horario1.hora;
 }
 if(horario1.minuto < horario2.minuto){
  resultado->minuto = horario2.minuto - horario1.minuto;
 }
  if(horario1.segundo < horario2.segundo){
  resultado->segundo = horario2.segundo - horario1.segundo;
 }



}
