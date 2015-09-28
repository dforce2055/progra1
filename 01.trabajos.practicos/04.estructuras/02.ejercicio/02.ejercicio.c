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
void guardarHora(tHora *resultado, long int segundos);
void formatHora(char *cadena, tHora resultado);

int main(){
  //tHora horario1 = {24,30,00}, horario2 = {23,39,01}, resultado = {0,0,0};
  tHora horario1, horario2 , resultado = {0,0,0};
  char horarioImpreso[12] = "00:00:00 s.";

  ingresarHorario(&horario1);
  ingresarHorario(&horario2);
  compararHorario(horario1, horario2, &resultado);
  formatHora(horarioImpreso, resultado);
  printf("La diferencia de horario es de %s\n", horarioImpreso);

  return 0;
}
void ingresarHorario(tHora *horario){
  //Recibe por referencia una estructura hora, solicita la carga de
  //la estructura por el usuario desde teclado, validando los datos
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
  //Recibe por valor 2 estructuras hora, pasa a segundos todas sus variables
  //realiza una resta segun corresponda y envia la estructura hora resultado por referencia
  //y los segundos por valor a guardarHora(), la misma devuelve la estructura hora resultado
  //completa
  long int seg1, seg2, segundos;

  seg1 = (horario1.hora * 3600) + (horario1.minuto * 60) + horario1.segundo;
  seg2 = (horario2.hora * 3600) + (horario2.minuto * 60) + horario2.segundo;

  if(seg1 == seg2){
    resultado->hora = 0;
    resultado->minuto = 0;
    resultado->segundo = 0;
    return;
  }
  if(seg1 > seg2) segundos = seg1 - seg2;
  if(seg2 > seg1) segundos = seg2 - seg1;

  guardarHora(resultado, segundos);
}
void guardarHora(tHora *resultado, long int segundos){
  //Recibe por referencia una estructura hora vacia y por valor cantidad de segundos
  //Devuelve la estructura de hora con el resultado correspondiente en cada variable
  while(segundos >= 3600){
    segundos = segundos - 3600;//resta 3600 segundos
    resultado->hora++;//suma 1 hora
  }
  while(segundos >= 60){
    segundos = segundos - 60;//resta 60 segundos
    resultado->minuto++;//suma 1 munuto
  }
  resultado->segundo = segundos;
}
void formatHora(char *cadena, tHora resultado){
  //Recibe por valor una estructura hora, pasa cada variable a cadena
  //y la guarda formateada en una cadena pasada por referencia
  char hora[2], minuto[2], segundo[2];
  sprintf(hora, "%d", resultado.hora);
  sprintf(minuto, "%d", resultado.minuto);
  sprintf(segundo, "%d", resultado.segundo);

  if(resultado.hora < 9){
    strcpy(cadena, "0");
    strcat(cadena, hora);
  }else strcpy(cadena, hora);
  strcat(cadena, ":");
  if(resultado.minuto < 9){
    strcat(cadena, "0");
    strcat(cadena, minuto);
  }else strcat(cadena, minuto);
  strcat(cadena, ":");
  if(resultado.segundo < 9){
    strcat(cadena, "0");
    strcat(cadena, segundo);
  }else strcat(cadena, segundo);
  strcat(cadena, " s.");
}
