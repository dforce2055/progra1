#include <stdio.h>
int main(){
	char cad[80] = "3.1416"; /* se ingresa ".", ya que es un caracter valido, sino con "," seria invalido, y sscanf solo convierte hasta el caracter 3 a float*/
	float pi;
	
	sscanf(cad,"%f", &pi);
	printf("%f", pi);
	
	return 0;
}
