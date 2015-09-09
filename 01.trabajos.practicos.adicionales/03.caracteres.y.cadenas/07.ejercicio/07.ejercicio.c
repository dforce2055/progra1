/* Codificar  una  función  strsub(s,d,n)   que  devuelva  una  subcadena  de  
la  cadena  de caracteres  s,  indicando  en  d  la  posición  inicial  y  en  
n  la  cantidad  de  caracteres  deseada. 
Ejemplo,  dada  la  secuencia:  "El  número  de  teléfono  es  4356-7890."  se  
desea  obtener  el teléfono, que está a partir de la posición 26 y tiene 9 
caracteres.  */
#include <stdio.h>
#include <string.h>
char *strsub(char *s,int d,int n);
int main(){
  char cadena[256] = "El  número  de  teléfono  es  4356-7890.";
  char *subCadena = strsub(cadena, 32, 9);
  
  puts(cadena);
  //puts(subCadena);
  
  if(subCadena[0] != '\0') puts(subCadena);
  else puts("Error");
  return 0;
}
char *strsub(char *s,int d,int n){
  char *pSubCadena = s;
  char *pFinSubCadena;
  
  if(strlen(s) > d + n){//si el largo de la cadena es mayor posición+cant.caracteres
    pSubCadena = pSubCadena+d;//corro hasta llegar a la posición cadena+d
    pFinSubCadena = pSubCadena+n;//le asigno la dirección final a pSubCadena
    *pFinSubCadena = '\0';
  }else *pSubCadena = '\0';
  
  return(pSubCadena);
}
/* error detectado, se esta modificando el string de main cadena[256] 
  Si quiero modificar una cadena en una función, y quiero devolver un puntero
  a esa cadea,¿Es esto correcto?¿Las variables declaradas en una función terminan
  al terminar la llamanda a la función?
  Si utilizo void, modifico el string de main
*/