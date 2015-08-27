/* Escribir una función que reciba como parámetro un número real y lo redondee a una
determinada cantidad de decimales, recibida también como parámetro de tipo entero.
Observe que debe redondear y no truncar, y no deben usarse cadenas de caracteres. */
#include <stdio.h>
#include <math.h>
float redondeo(float numero, int decimales);
int main(){
  float pi = 3.14128, piRedondo = 0;
  //printf("%.3f", redondeo(pi,3));
  piRedondo = redondeo(pi,2);
  printf("%.2f\n", piRedondo);
  return 0;
}
float redondeo(float numero, int decimales){
  //return floor(numero * 100 + 0.5) / 100;
  return floor(numero * (pow(10, decimales)) + 0.5) / pow(10, decimales);
}

/* funcion floor
    http://www.tutorialspoint.com/c_standard_library/c_function_floor.htm
    http://www.c.conclase.net/librerias/?ansifun=floor
*/
/* funcion pow
    http://www.tutorialspoint.com/c_standard_library/c_function_pow.htm
    http://www.c.conclase.net/librerias/?ansifun=pow
 */
