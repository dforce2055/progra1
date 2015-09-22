/* Escriba un programa que lea un carácter desde el teclado y que pruebe el
carácter con cada una de las funciones de la biblioteca de manipulación de
caracteres. El programa debe imprimir el valor devuelto por cada función. */
#include <stdio.h>
#include <string.h>
int main(){
  char c;

  puts("Ingrese un caracter:");
  c = getchar();

  if(isdigit(c)) puts("Es digito");
  if(isalpha(c)) puts("Es alfanumerico");
  if(isalnum(c)) puts("Es digito o letra");
  if(isxdigit(c)) puts("Es hexadecimal");
  if(islower(c)) puts("Esta en minuscula");
  if(isupper(c)) puts("Esta en mayuscula");
  printf("tolower: %c\n", tolower(c));
  printf("toupper: %c\n", toupper(c));

  return 0;
}
/*
int isdigit (  int e  ) ;  Devuelve un valor verdadero si e es un dígito; de lo contrario devuelve O (falso).
int isalpha (  int e  ) ;  Devuelve un valor verdadero si e es una letra; de lo contrario devuelve O (falso).
int isalnum (  int e  ) ;  Devuelve un valor verdadero si e es un dígito o una letra; de lo contrario
devuelve O (falso).
int isxdigi t  (  int e  ) ;  Devuelve un valor verdadero si e es un dígito hexadecimal; de lo contrario
devuelve O (falso). (Revise el apéndice E, Sistemas de numeración, para una
explicación detallada acerca de los números binarios, números octales, números
decimales y números hexadecimales.)
int islower(  int e  )  ;
int isupper(  int e  )  ;
int tolower(  int e  ) ;
int toupper(  int e  )  ;
int isspaee(  int e  )  ;
int isentrl(  int e  );
int ispunet(  int e  );
int isprint(  int e  );
int isgraph(  int e  );
Devuelve un valor verdadero si e es una letra minúscula; de lo contrario devuelve O
(falso).
Devuelve un valor verdadero si e es una letra mayúscula; de lo contrario devuelve O
(falso).
Si e es una letra mayúscula, tolower devuelve e como una letra minúscula.
De lo contrario, tolower devuelve el argumento sin modificación.
Si e es una letra minúscula, toupper devuelve e como una letra mayúscula.
De lo contrario, toupper devuelve el argumento sin modificación.
Devuelve un valor verdadero si e es un carácter de espacio en blanco (nueva línea
(' \n' ), espacio ('  '), avance de página (' \ f '), retorno de carro (' \r' ),
tabulador horizontal (' \ t ') o tabulador vertical (' \ v' ); de lo contrario
devuelve O.
Devuelve un valor verdadero si e es un carácter de control; de lo contrario
devuelve O (falso).
Devuelve un valor verdadero si e es un carácter de impresión diferente de
un espacio, un dígito o una letra; de lo contrario devuelve O.
Devuelve un valor verdadero si e es un carácter de impresión, incluso el espacio
('  '); de lo contrario devuelve O.
Devuelve un valor verdadero si e es un carácter de impresión diferente del
espacio ('  '); de lo contrario devuelve O.
*/
