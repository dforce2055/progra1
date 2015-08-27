 #include <stdio.h>
 #include <ctype.h>
 int main(){
	 char cad[80];
	 int i;
	 printf("Ingrese una cadena de caracteres\n");
	 scanf("%s", cad);
	 for(i = 0; cad[i]; i++){
			if(isalpha(cad[i])){
				printf("%c es un carácter alfabético\n", cad[i]);
			}
		}
	 return 0;
 }
