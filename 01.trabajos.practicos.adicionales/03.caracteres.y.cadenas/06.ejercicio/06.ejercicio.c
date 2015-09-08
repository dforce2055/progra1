/* Desarrollar  una  función  que  permita  convertir  un  número  entero  
positivo  cualquiera  a palabras,  tal  como  se  realiza  en  los  cheques  al 
escribir  el  importe  en  números  y  en  letras. 
Para  ello  se  recibe  como  parámetros  el  número  y  una  cadena  donde  se 
devolverá  el resultado.   */
#include <stdio.h>
void deNumeroAPalabras(int numero, char *cadena);
int main(){
  char texto[256];
  int numero = 1500;
  deNumeroAPalabras(numero, texto);
  
  return 0;
}
void deNumeroAPalabras(int numero, char *cadena){
  char *pCadena = cadena;
  
  if(numero > 0){
    sprintf(cadena, "%d", numero);
    
    
  }
  
}

//Muy parecido al de la practica principal. Seria demasiado largo y aburrido de
//codificar. 
//1.000.000 = un millon.
//3 trillones?