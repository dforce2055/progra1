/* 9. Hacer una función que permita convertir números enteros entre 0 y 999 a 
palabras. Para ello se recibe como parámetros el número y una cadena. 
¿En qué cambiaría su programa si el rango de valores fuese diferente? */
#include <stdio.h>
#include <string.h>
void deNumeroACadena(int numero, char *cadena);
int main(){
  char cadena[256];
  
  deNumeroACadena(110, cadena);
  
  if(*cadena != '\0') puts(cadena);
  else puts("Error el numero ingresado es mayor a 999");
  return 0;
}
void deNumeroACadena(int numero, char *cadena){
  /*char *unidad[] = {"uno","dos","tres","cuatro","cinco","seis","siete","ocho"
                    "nueve","diez"};
  char *decena[] = {"diez","diesi","veinte","veinti","treinta","treinti",
                    "cuarenta","cuarenti","cincuenta","cincuenti","sesenta",
                    "sesenti","setenta","setenti","ochenta","ochenti","noventa",
                    "noventi"};
  char *centena[] ={"cien","ciento","doscientos","trescientos","cuatrocientos",
                    "quinientos","seiscientos","setecientos","ochocientos",
                    "novecientos"};*/
  char unidad, decena, centena;
  
  if(numero < 999){
    sprintf(cadena, "%d", numero);//guardo en el numero en formato char

    unidad = cadena[2];
    decena = cadena[1];
    centena = cadena[0];
    
    switch(centena){
      case '2': strcpy(cadena,"doscientos"); break;
      case '3': strcpy(cadena,"trescientos"); break;
      case '4': strcpy(cadena,"cuatrocientos"); break;
      case '5': strcpy(cadena,"quinientos"); break;
      case '6': strcpy(cadena,"seiscientos"); break;
      case '7': strcpy(cadena,"setecientos"); break;
      case '8': strcpy(cadena,"ochocientos"); break;
      case '9': strcpy(cadena,"novecientos"); break;
      case '1': //cien o ciento
        if(cadena[1] == '0' && cadena[2] == '0') strcpy(cadena,"cien");
        else strcpy(cadena,"ciento"); 
        break;
    }
    switch(decena){
      case '0': break;
      case '1': 
        if(cadena[2] == '0') strcat(cadena," diez");
        else strcat(cadena," diesi");
        break;
      /*case '2': strcpy(cadena,decena[3]); break;
      case '3': strcpy(cadena,decena[4]); break;
      case '4': strcpy(cadena,decena[5]); break;
      case '5': strcpy(cadena,decena[6]); break;
      case '6': strcpy(cadena,decena[7]); break;
      case '7': strcpy(cadena,decena[8]); break;
      case '8': strcpy(cadena,decena[9]); break;
      case '9': strcpy(cadena,decena[10]); break;
      */
    }

  }else cadena[0] = '\0';
}