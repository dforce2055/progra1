/* Escriba un programa que utilice la generación de números aleatorios para crear oraciones. El programa debe utili-
zar cuatro arreglos de apuntadores a char llamados, articulo, sustantivo, verbo y preposicion. El
programa debe crear una oración mediante la selección de una palabra al azar de cada arreglo en el siguiente or-
den: articulo, sustantivo, verbo, preposicion, articulo y sustantivo. Al elegir cada palabra,
ésta se debe concatenar a las palabras previas en un arreglo lo suficientemente grande para almacenar una oración
completa. Las palabras deben separarse con espacios. Cuando se imprime la oración final, ésta debe comenzar con
una letra mayúscula y terminar con punto. El programa debe generar 20 oraciones.
Los arreglos deben rellenarse de la siguiente manera: El arreglo articulo debe contener los artíclos "el"
"la", "un", "algun" y "cualquiera"; el arreglo sustantivo debe contener los sustantivos "nino",
"ni na", "perro", "pueblo" y "carro"; el arreglo verbo debe contener los verbos "condujo",
"brinco", "corrio", "camino", y "salto"; el arreglo preposición debe contener la preposiciones
"hacia", "desde", "sobre", "bajo" y "en".
Cuando escriba su programa y ya funcione, modifíquelo para producir una historia corta que consista en varias
de estas oraciones. (¿Qué talla posibilidad de un escritor de términos aleatorios?) */
//formula rand()% (vFinal - vInicial +1) + vInicial;
//rand()% (5 - 0 + 1) + 0 = 6
#include <stdio.h>
#include <string.h>
#include <time.h>
void oracionRandom(char oracion[][20], char **articulo, char **sustantivo, char **verbo, char **preposicion, int n);
int main(){
  srand((int *)time(NULL));
  char *articulo[] = {"el","la","un","algun","cualquiera"};
  char *sustantivo[] = {"niño","niña","perro","pueblo","auto"};
  char *verbo[] = {"condujo","brinco","corrio","camino","salto"};
  char *preposicion[] = {"hacia","desde","sobre","bajo","en"};
  char oracion[1000][20];
  int i;

  for(i = 0; i < 20; i++){
    oracionRandom(oracion, articulo, sustantivo, verbo, preposicion, i);
    puts(oracion[i]);
  }


  return 0;
}
void oracionRandom(char oracion[][20], char **articulo, char **sustantivo, char **verbo, char **preposicion, int n){
  //genera oraciones al azar -> articulo, sustantivo, verbo, preposicion, articulo y sustantivo
  strcpy(oracion[n], articulo[rand()%5]);
  strcat(oracion[n], " ");
  strcat(oracion[n], sustantivo[rand()%5]);
  strcat(oracion[n], " ");
  strcat(oracion[n], verbo[rand()%5]);
  strcat(oracion[n], " ");
  strcat(oracion[n], preposicion[rand()%5]);
  strcat(oracion[n], " ");
  strcat(oracion[n], articulo[rand()%5]);
  strcat(oracion[n], " ");
  strcat(oracion[n], sustantivo[rand()%5]);
  strcat(oracion[n], ".");
  strcat(oracion[n],"\0");
  oracion[n][0] = toupper(oracion[n][0]);
}
