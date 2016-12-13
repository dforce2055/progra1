#include <stdlib.h>
#include <stdio.h>
#ifndef _09EJERCICIO_
//#pragma warning(disable:4996)
#define N 16
#define M 34
typedef struct Cheque{
  char nombre[N];
  char domicilio[M];
  int dd, mm, aa;   //fecha de emición del cheque
  int plazoValidez;
}Cheque;

Cheque cargarCheque0(char *linea);
Cheque cargarCheque1(FILE *archivo);
Cheque cargarCheque2(FILE *archivo);
int cpycad(char *destino, char *origen, int desde, int hasta);
int cpyfech(Cheque *cheque, char *fecha);
void guardarCheque(Cheque cheque);
void mostrarCheques(void);
#endif //_09EJERCICIO_
