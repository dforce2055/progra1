/* 9. Hacer una función que permita convertir números enteros entre 0 y 999 a 
palabras. Para ello se recibe como parámetros el número y una cadena. 
¿En qué cambiaría su programa si el rango de valores fuese diferente? */
#include <stdio.h>
#include <string.h>
void deNumeroACadena(int numero, char *cadena);
int main(){
  char cadena[256];
  char texto[256];
  int numero;
  
  deNumeroACadena(119, cadena);
  sscanf(cadena, "%d", &numero);
  sprintf(texto, "%s", cadena+4);
  printf("numero: %d\n",numero);
  printf("texto: %s\n", texto);
  
  
  if(*cadena != '\0') puts(cadena);
  else puts("Error el numero ingresado es mayor a 999");
  return 0;
}
void deNumeroACadena(int numero, char *cadena){
  char unidad, decena, centena;

  if(numero < 999){
    sprintf(cadena, "%d", numero);//guardo en el numero en formato char
    if(numero > 99){
      unidad = cadena[2]; 
      decena = cadena[1];
      centena = cadena[0];
    }else if(numero > 9){
      unidad = cadena[1]; 
      decena = cadena[0];
      centena = ' ';
    }else{
      unidad = cadena[0]; 
      decena = ' ';
      centena = ' ';
    }
    
    switch(centena){
      case '2': strcat(cadena," doscientos"); break;
      case '3': strcat(cadena," trescientos"); break;
      case '4': strcat(cadena," cuatrocientos"); break;
      case '5': strcat(cadena," quinientos"); break;
      case '6': strcat(cadena," seiscientos"); break;
      case '7': strcat(cadena," setecientos"); break;
      case '8': strcat(cadena," ochocientos"); break;
      case '9': strcat(cadena," novecientos"); break;
      case '1': //cien o ciento
        if(decena == '0' && unidad == '0') strcat(cadena," cien");
        else strcat(cadena," ciento"); 
        break;
    }
    switch(decena){
      case '0': break;
      case '1': 
        switch(unidad){
          case '0': strcat(cadena, " diez"); unidad = ' '; break;
          case '1': strcat(cadena, " once"); unidad = ' '; break;
          case '2': strcat(cadena, " doce"); unidad = ' '; break;
          case '3': strcat(cadena, " trece"); unidad = ' '; break;
          case '4': strcat(cadena, " catorce"); unidad = ' '; break;
          case '5': strcat(cadena, " quince"); unidad = ' '; break;
          default: strcat(cadena, " diesci"); break;
        }
        break;      
      case '2': 
        if(unidad == '0') strcat(cadena," veinte");
        else strcat(cadena," veinti");
        break;
      case '3':
        if(unidad == 0) strcat(cadena," treinta");
        else strcat(cadena," treinti");
        break;
      case '4':
        if(unidad == 0) strcat(cadena," cuarenta");
        else strcat(cadena," cuarenti");
        break;
      case '5':
        if(unidad == 0) strcat(cadena," cincuenta");
        else strcat(cadena," cincuenti");
        break;
      case '6':
        if(unidad == 0) strcat(cadena," sesenta");
        else strcat(cadena," sesenti");
        break;
      case '7':
        if(unidad == 0) strcat(cadena," setenta");
        else strcat(cadena," setenti");
        break;
      case '8':
        if(unidad == 0) strcat(cadena," ochenta");
        else strcat(cadena," ochenti");
        break;
      case '9':
        if(unidad == 0) strcat(cadena," noventa");
        else strcat(cadena," noventi");
        break;
    }
    switch(unidad){
      case '1': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"uno"); 
        else strcat(cadena," uno");
        break;
      case '2': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"dos"); 
        else strcat(cadena," dos");
        break;
      case '3': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"tres"); 
        else strcat(cadena," tres");
        break;
      case '4': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"cuatro"); 
        else strcat(cadena," cuatro");
        break;
      case '5': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"cinco"); 
        else strcat(cadena," cinco");
        break;
      case '6': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"seis"); 
        else strcat(cadena," seis");
        break;
      case '7': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"siete"); 
        else strcat(cadena," siete");
        break;
      case '8': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"ocho"); 
        else strcat(cadena," ocho");
        break;
      case '9': 
        if(cadena[strlen(cadena)-1] == 'i') strcat(cadena,"nueve"); 
        else strcat(cadena," nueve");
        break;
    }
  
  }else cadena[0] = '\0';
}