/* Escribir un programa que lea un número entero cualquiera y lo convierta a cadena de
caracteres. No utilice ninguna función de biblioteca para la conversión, desarrolle la
estrategia desde cero.
Imprimir por pantalla la cadena obtenida. Tener en cuenta que el numero puede ser
negativo. No confundir convertir a cadena con convertir a palabras. */
#include <stdio.h>
char *enteroACadena(int entero, char cadena[]);
int main(){
  int numero = -120;
  char cadena[256];
  enteroACadena(numero, cadena);

  puts(cadena);

  return 0;
}
char *enteroACadena(int entero, char cadena[]){
  //Inserta en un vector de cadenas pasado por parametro, la representacion en
  //caracter del entero (positivo o negativo) pasado por parametro
    char const digito[] = "0123456789";
    char *pCadena = cadena;
    if(entero<0){//si el numero es negativo, inserto un signo '-' al principio de la cadena
        *pCadena++ = '-';
        entero *= -1;
    }
    int shifter = entero;
    do{ //Muevo el puntero hasta que el número no sea divisible / 10, es decir mayor a 0
        ++pCadena;
        shifter = shifter/10;
    }while(shifter);
    *pCadena = '\0';
    do{ //De atras hacia delante voy insertando el caracter correspondiente en la posición de puntero
        *--pCadena = digito[entero%10];
        entero = entero/10;
    }while(entero);
    return cadena;
}
