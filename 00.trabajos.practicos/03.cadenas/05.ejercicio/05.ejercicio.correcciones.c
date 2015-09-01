/*Hola Diego,
Te envío las correcciones.
Correcciones que no hacen al funcionamiento, sino al entendimiento del programa.
1 - Escribir una sentencia por renglón.

Correcciones
1 - Los prototipos deben colocarse antes de comenzar el main. Si se coloca dentro de la
  función, solo lo podrá ver la misma.
2 - Las cadenas deben tener el tamaño antes de empezar a compilar, y su tamaño no puede
  modificarse.
3 - El tamaño de un vectopr o cadena no puede estar en una variable o un parámetro.
4 - Es incorrecto devolver la dirección de un vector que fue declarado en una función,
  pues al terminar esta, ese vector se destruye. (esto es probable que modifique el algoritmo)
  No está corregido.


Saludos,
Patricia*/

#define _CRT_SECURE_NO_WARNINGS
/* 5. Hacer una función que permita insertar en una secuencia de dígitos los caracteres
guión cada 8 dígitos a partir del cuarto dígito, y un espacio cada 8 dígitos a partir
del octavo dígito. Si la cantidad de dígitos no es múltiplo de ocho agregar delante de
la cadena caracteres '0' hasta que la misma sea múltiplo de 8.
  Ejemplos: 472348237388539055823012   ->    4723-4823 7388-5390 5582-3012
            8237388539055823012        ->    0000-0823 7388-5390 5582-3012

 */
#include <stdio.h>
char * formateaArreglo(char *arreglo);
void mostrarArreglo(char *arreglo);
char * agregarCeros(char *arreglo, int largo, int cantCeros);
char * agregarGuiones(char *arreglo, int largo);
char * agregarEspacios(char *arreglo, int largo);

int main(){
        /* char arreglo[]  = "8237388539055823012";  falta tamaño */

        char arreglo[256]  = "8237388539055823012";
        char *pArreglo = arreglo;

        printf("Arreglo Original:\n====================\n");
        mostrarArreglo(pArreglo);
        pArreglo = formateaArreglo(pArreglo);
        printf("\nArreglo Formateado:\n=====================\n");
        mostrarArreglo(pArreglo);

        return 0;
}
char * formateaArreglo(char *arreglo){
        /* char * agregarCeros(char *arreglo, int largo, int cantCeros);  van antes del main los prototipos
        char * agregarGuiones(char *arreglo, int largo);
        char * agregarEspacios(char *arreglo, int largo);
        */

        int i, largo, agregar = 0;
        for(largo = 0; arreglo[largo]; largo++)
        ;
        if(largo % 8 != 0){
                agregar = 8 - (largo % 8);
                arreglo = agregarCeros(arreglo, largo, agregar);
        }
        for(i = 0; arreglo[i]; i++)
                ;
        largo = i + (i / 4);//le agrego a largo la cantidad de 0 y de espacios a agregar

        arreglo = agregarGuiones(arreglo, largo);

        for(largo = 0; arreglo[largo]; largo++)
                ;
        arreglo = agregarEspacios(arreglo, largo);

        return arreglo;
}
char * agregarCeros(char *arreglo, int largo, int cantCeros){
        int i, j, size = largo + cantCeros +1;
        //char nuevoArreglo[size];  no puede definirse el tamaño ni con una variable ni con un parámetro
        char nuevoArreglo[256];
        for(i = 0; i < size-1; i++)
                nuevoArreglo[i] = '0';
        for(i = largo -1, j = size -2; arreglo[i]; i--, j--)
                nuevoArreglo[j] = arreglo[i];

        arreglo = nuevoArreglo;
        return arreglo;
}
char * agregarGuiones(char *arreglo, int largo){
//      char nuevoArreglo[largo*2]; no puede definirse el tamaño ni con una variable ni con un parámetro
        char nuevoArreglo[256];
        int i = 0, j = 0, contador;

        for(contador = 1; arreglo[i]; i++, j++, contador++){
                if(contador % 4 == 0 && contador %8 != 0){
                        nuevoArreglo[j] = arreglo[i];
                        j++;
                        nuevoArreglo[j] = '-';
                }else
                        nuevoArreglo[j] = arreglo[i];
        }
        nuevoArreglo[j] = '\0';
        arreglo = nuevoArreglo; //el puntero de arreglo ahora apunta al nuevo arreglo
        return arreglo;
}
char * agregarEspacios(char *arreglo, int largo){
        //char nuevoArreglo[largo+100];no puede definirse el tamaño ni con una variable ni con un parámetro
        char nuevoArreglo[256];
        int i = 0, j = 0, contador;
        for(contador = 1; arreglo[i]; i++, j++, contador++){
                if(contador % 9 == 0){
                        nuevoArreglo[j] = arreglo[i];
                        j++;
                        nuevoArreglo[j] = ' ';
                }else nuevoArreglo[j] = arreglo[i];
        }
        nuevoArreglo[j] = '\0';
        arreglo = nuevoArreglo; //el puntero de arreglo ahora apunta al nuevo arreglo
        return arreglo;
}
void mostrarArreglo(char *arreglo){
        printf("%s\n", arreglo);
}
