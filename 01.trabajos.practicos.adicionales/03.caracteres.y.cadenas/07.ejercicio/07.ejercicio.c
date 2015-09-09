/* Codificar  una  función  strsub(s,d,n)   que  devuelva  una  subcadena  de
la  cadena  de caracteres  s,  indicando  en  d  la  posición  inicial  y  en
n  la  cantidad  de  caracteres  deseada.
Ejemplo,  dada  la  secuencia:  "El  número  de  teléfono  es  4356-7890."  se
desea  obtener  el teléfono, que está a partir de la posición 26 y tiene 9
caracteres.  */
/* REHACER EJERCICIO */
#include <stdio.h>
#include <string.h>
char *strsub(char *s,int d,int n, char *subC);
int main(){
  char cadena[256] = "El  número  de  teléfono  es  4356-7890.";
  char *pSubCadena;
  strsub(cadena, 32, 9, pSubCadena );

  puts(cadena);

  if(pSubCadena[0] != '\0') puts(pSubCadena);
  else puts("Error");
  return 0;
}
char *strsub(char *s,int d,int n, char *subC){
  char *pCadena = s;
  char *pSubC = subC;

  if(strlen(s) > d + n){//si el largo de la cadena es mayor posición+cant.caracteres
    pCadena = pCadena+d;//corro hasta llegar a la posición cadena+d
    while(n>0){//copio caractér x caractér hasta cumplir con la cantidad solicitada n
      *pSubC = *pCadena;
      pCadena++;
      pSubC++;
      n--;
    }
    *pSubC = '\0';
  }else *pSubC = '\0';

  return(pSubC);
}
/* error detectado, se esta modificando el string de main cadena[256]
  Si quiero modificar una cadena en una función, y quiero devolver un puntero
  a esa cadea,¿Es esto correcto?¿Las variables declaradas en una función terminan
  al terminar la llamanda a la función?
  Si utilizo void, modifico el string de main
*/
/* RESPUESTA DE PATRICIA:
  Siempre que necesites devolver una cadena, tenes que pasarla como parametro!!!!
  Ejemplo:

  char *enteroACadena(int entero, char *cadena){
  //Inserta en un vector de cadenas pasado por parametro, la representacion en
  //caracter del entero (positivo o negativo) pasado por parametro
    char const digito[] = "0123456789";
    char *pCadena = cadena;
    if(entero<0){//si el numero es negativo, inserto un signo '-' al principio de la cadena
        *pCadena++ = '-';
        entero *= -1;//hago positivo el número
    }
    int unidades = entero;
    do{ //Muevo el puntero hasta que el número no sea divisible / 10, es decir mayor a 0
        ++pCadena;
        unidades = unidades/10;
    }while(unidades);
    *pCadena = '\0';
    do{ //De atras hacia delante voy insertando el caracter correspondiente en la posición de puntero
        *--pCadena = digito[entero%10];
        entero = entero/10;
    }while(entero);
    return cadena;
}
}



  */
