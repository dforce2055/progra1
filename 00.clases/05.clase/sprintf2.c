/* comentarios */
#include <stdio.h>
int main(){
  char cad[80];
  char cad1[] = "Lunes";
  char cad2[] = "Martes";
  char cad3[] = "Miercoles";
  char cad4[] = "Jueves";
  char cad5[] = "Viernes";
  sprintf(cad, "%s, %s, %s, %s, %s", cad1, cad2, cad3, cad4, cad5);
  puts(cad);
  return 0;
}
