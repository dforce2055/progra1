/*Desarrollar una función para eliminar los espacios en blanco ubicados al
principio y al final de una cadena de caracteres. Los espacios intermedios no
deben alterarse.*/
#include <stdio.h>
void eliminarEspacios(char *cadena);
main() {
    char cadena[] = " el capo re bigote  ";
    printf("%s\n", cadena);
    eliminarEspacios(cadena);
    printf("%s\n", cadena);
    return 0;
}
void eliminarEspacios(char *cadena){
    int i, largo, espacios;
    for(largo = 0; cadena[largo]; largo++);
    if(cadena[0] == ' '){
        for(i = 0; i < largo; i++) cadena[i] = cadena[i+1];
    }
    if(cadena[largo] == ' '){
        cadena[largo] = '\0';
    }
}
