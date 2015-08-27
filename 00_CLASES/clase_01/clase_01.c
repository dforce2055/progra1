/*
 * Clase #01
 * Martes 6 de agosto de 2013
 * Estructura de un programa en C. Tipos de dato. Operadores. Estructuras de control.
 * **********************************************************************************
 * 
 * Estructura básica de un programa en C
 * */
 #include <stdio.h>
 int main(){
	 ............;
	 ............;
	 ............;
	 ............;
	 /* Esto es un comentario!*/
	 
	 return 0;
	 }
/* 
 * Primer programa
 * */
 #include <stdio.h>
 int main(){
	 printf("Hola mundo!\n"); /* \n es utilizado para imprimir por pantalla un salto de línea */
	 return 0;
	 }
/* \n = secuencia de escape, salto de línea
 * \t = tabulador
 * \b = tetroceso o backspace
 * \a = campanilla de sonido de alerta
 * 
 * Variables:
 * Una variable define espacio de almacenamiento capaz de contener un valor, y que se caracteriza por 3 atributos
 * 1)Nombre: letras, números, _ unicamente. No pueden comenzar con un número, no pueden coincidir con las palabras reservadas del lenguaje C(IF, MAIN, RETURN, WHILE, etc.)
 * 2)Tipo de dato:	int = Enteros
 * 					char = Caracteres
 * 					float = números reales, es decir números con decimales (7 decimales exactos)
 * 					double = números reales, es decir números con decimales (15 decimales exactos)
 * 					void = para funciones que no devuelven ningún valor de retorno
 * 					boleanos = 0: falso | !0: verdadero
 * 3)El valor: tiene que estar en concordancia con el tipo de dato de la variable.
 * 
 * Declaración de variables
 * */
 #include <stdio.h>
 int main(){
	 int a;
	 float pi = 3,14156;
	 a = 2;
	 printf("El número %d multiplicado por %f es igual a %f\n", a, pi, pi * a);
	  
	 return 0;
	 }
/*
 * Especificadores de conversión
 * %d = enteros
 * %f = reales
 * %c = caracteres
 * 
 * %4d		 4 define el ancho del valor en pantalla
 * %04d		 rellena con 0 a la izquierda
 * %82f		 8 es el ancho
 * 			 2 la cantidad de decimales
 * $.2f		 3.14 (2 decimales)
 * 
 * Definición HARDCODE = harcodeado = dentro del código 
 * 
 * Ingresar valores desde teclado
 * */
 #include <stdio.h>
 int main(){
	 int edad;
	 
	 printf("Ingrese su edad: ");
	 scanf("%d", &edad);
	 printf("\nUsted lleva vividos aproximadamente %d días\n", edad * 365);
	 
	 return 0;
	 }
/* Operadores aritmeticos 
 * **********************
 * + suma
 * - resta
 * * multiplicación
 * / división
 * % modulo/resto
 * 
 * Operadores de asignación adicionales
 * ************************************
 * +=
 * -=
 * *=
 * /=
 * %=
 * se utilizan cuando la variable aparece tanto a la izquierda, como a la derecha del =
 * a = a + 5; > a +=5;
 * 
 * Operadores incrementales
 * ************************
 * ++
 * --
 * 
 * Estructuras de control
 * **********************
 * Las estructuras secuencial lineal, se realiza en forma vertical descendente
 * 
 * IF(<CONDICIÓN>){
 * 	..........;
 * 	..........;
 * }
 * 
 * Estructura alternativa condicional
 * **********************************
 * IF(<CONDICIÓN>){
 * 	..........;
 * 	..........;	(verdadero)
 * }ELSE{
 * 			..........;
 * 			..........;	(falso) 
 *		 }
 * 
 * Operadores relacionales
 * ***********************
 * 
 * ==	igual
 * >	mayor
 * <	menor
 * >=	mayor igual
 * <=	menor igual
 * !=	distinto
 * 
 * Operadores logicos
 * ******************
 * 
 * &&	and
 * ||	or
 * !	NOT
 * 
 * Operador condicional
 * ********************
 * 
 * (<CONDICIÓN>) ? <VALOR1> : <VALOR2>;
 * b = (a < 0) ? -a : a;ç
 * 
 * SWITCH
 * ******
 * 
 * SWITCH(<VARIABLE SELECTORA(INT/CHAR)>){
	 * case <VALOR1>:	........;
	 * 					........;
	 * 					break;
	 * case <VALOR2>:	........;
	 * 					........;
	 * 					break; 
	 * default:			........;
	 * 					........; // no es obligatorio
	 * 					break;
	 * }
	 * 
 * Ejemplo de CASE
 * */
 #include <stdio.h>
 int main(){
	 int mes;
	 
	 printf("mes?");
	 scanf("%d", &mes);
	 
	 switch(mes){
		case1: printf("Enero");
				break;
		case2: printf("Febrero");
				break;
		case3: printf("Marzo");
				break;
		case4: printf("Abril");
				break;
		case5: printf("Mayo");
				break;
		case6: printf("Junio");
				break;
		case7: printf("Julio");
				break;
		case8: printf("Agosto");
				break;
		case9: printf("Septiembre");
				break;
		case10: printf("Octubre");
				break;
		case11: printf("Noviembre");
				break; 
		case12: printf("Diciembre");
				break;
		default: printf("Mes invalido");
				break;
		}
	 return 0; 
	}
/*
 * WHILE(<CONDICIÓN>){
 *		..........; 
 *		..........; 
 *  }
 * 
 * DO {
 * 		..........;
 * 		..........;// el código se ejecuta al menos 1 vez
 * } WHILE(<CONDICIÓN>);
 * */
 do{
	 printf("Ingrese un número positivo");
	 scanf("%d", &dato);
	 }while{dato < 0};

/* FOR(<INICIALIZACIÓN> ; <CONDICIÓN> ; <INVREMENTO/DECREMENTO>){
 * 		................;
 * 		................;
 * }º
 * */
