/* 3. Desarrollar las siguientes funciones para manejar “fechas”:
    a.Ingresar una fecha (día, mes, año) desde teclado, validando que corresponda a una
      fecha gregoriana.
    b.Indicar cual de dos fechas es la mayor.
    c.Sumar n días a una fecha
    d.Generar una cadena con formato dd/mm/aaaa
*/
#include <stdio.h>
#include <string.h>
typedef struct{
  int dia, mes, anio;
}tFecha;
void ingresarFecha(tFecha *fecha);
int fechaValida(tFecha *fecha);
int diasMes(tFecha *fecha);
int bisiesto(int anio);
int fechaMayor(tFecha fecha1, tFecha fecha2);
void sumarDias(tFecha *fecha, int dias);
void formatFecha(char *cadena, tFecha fecha);
int main(){
  tFecha fecha1, fecha2, fecha3 = {29,7,1986}, fecha4 = {29,4,1980};
  char fechaImpresa1[11], fechaImpresa2[11];
  int dias = 0;

  //a.Ingresar una fecha
  ingresarFecha(&fecha1);
  ingresarFecha(&fecha2);
  //guardo con formato las fechas
  formatFecha(fechaImpresa1, fecha1);
  formatFecha(fechaImpresa2, fecha2);
  //b.Indicar cual de dos fechas es la mayor.
  switch(fechaMayor(fecha1, fecha2)){
    case 1: printf("%s es mayor\n", fechaImpresa1); break;
    case 0: puts("fechas identicas"); break;
    case -1: printf("%s es mayor\n", fechaImpresa2); break;
  }
  //c.Sumar n días a una fecha
  printf("Cuantos días desea sumarle a fecha1 %s : ", fechaImpresa1);
  scanf("%d", &dias);
  sumarDias(&fecha1, dias);
  //d.Generar una cadena con formato dd/mm/aaaa
  formatFecha(fechaImpresa1, fecha1);
  printf("El resultado es: %s", fechaImpresa1);

  return 0;
}
void ingresarFecha(tFecha *fecha){
  int d,m,a;
  do{
    puts("Ingrese una fecha valida: dd/mm/aaaa");
    printf("Dia: ");
    scanf("%d", &fecha->dia);
    printf("Mes: ");
    scanf("%d", &fecha->mes);
    printf("Año: ");
    scanf("%d", &fecha->anio);
  }while(!fechaValida(fecha));//mientras la fecha sea invalida seguir solicitando
}
int fechaValida(tFecha *fecha){
  //Recibe una estructura fecha cargada por referencia
  //Comprueba si el mes esta entre 0 y 12 (ene-dic) y comprueba que los días
  //correspondan al mes.
  //devuelve 1:verdadero 0:falso
  if(fecha->mes > 0 && fecha->mes <= 12){
    if(fecha->dia > 0 && fecha->dia <= diasMes(fecha))
      return 1;
    else return 0;
  }else
    return 0;
}
int diasMes(tFecha *fecha){
  //Recibe una estructura fecha por referencia
  //Calcula los dias del mes
  //devuelve la cantidad de dias
  switch(fecha->mes){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
      return 31;
      break;
    case 4: case 6: case 9: case 11:
      return 30;
      break;
    case 2:
      if(bisiesto(fecha->anio)) return 29;
      else  return 28;
      break;
  }
}
int bisiesto(int anio){
  //recibe un enterio (año) y calcula si es bisiesto
  //devuelve 1:verdadero 0:falso
  if(anio % 4 == 0  || anio % 4 == 0 && anio % 100 != 0)
    return 1;
  else return 0;
}
int fechaMayor(tFecha fecha1, tFecha fecha2){
  //Recibe por valor 2 estructuras fecha
  //Devuelve 1 si f1 > f2, 0 si son iguales, -1 si f1 es menos a f2
  if(fecha1.anio == fecha2.anio){
    if(fecha1.mes == fecha2.mes){
      if(fecha1.dia == fecha2.dia) return 0;
      else
        if(fecha1.dia > fecha2.dia) return 1;
        else return -1;
    }else
      if(fecha1.mes > fecha2.mes) return 1;
      else return -1;
  }else
    if(fecha1.anio > fecha2.anio) return 1;
    else return -1;
}
void sumarDias(tFecha *fecha, int dias){
  for(; dias > 0; dias--){
    if(fecha->dia < diasMes(fecha)){
      fecha->dia++;
    }else{
      if(fecha->mes == 12){
        fecha->mes = 1;
        fecha->anio++;
      }else{
        fecha->dia = 1;
        fecha->mes++;
      }
    }
  }
}
void formatFecha(char *cadena, tFecha fecha){
  //Recibe una cadena por referencia y una estructura fecha por valor
  //Devuelve la cadena formateada
  char dia[3], mes[3], anio[5];

  sprintf(dia, "%d", fecha.dia);
  sprintf(mes, "%d", fecha.mes);
  sprintf(anio, "%d", fecha.anio);

  if(fecha.dia < 10){
    strcpy(cadena, "0");
    strcat(cadena, dia);
  }else strcpy(cadena, dia);
  strcat(cadena, "/");
  if(fecha.mes < 10){
    strcat(cadena, "0");
    strcat(cadena, mes);
  }else strcat(cadena, mes);
  strcat(cadena, "/");
  strcat(cadena, anio);
}
