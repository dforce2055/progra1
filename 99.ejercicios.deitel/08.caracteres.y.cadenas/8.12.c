/* (Rimas.) Una rima es un verso humorístico de 5 líneas en el cual, la primera y la segunda
línea riman con la quinta, y la tercera línea rima con la cuarta. Mediante el uso de técnicas
similares a las desarrolladas en el ejercicio 8.11,escriba un programa que genere rimas al
azar. ¡Depurar el programa para generar buenas rimas es un problema desafiante, pero el
resultado valdrá la pena!*/
#include <stdio.h>
#include <string.h>
#include <time.h>
void rimaRandom(char *rima, char **rima125, char **rima34);
int main(){
  srand((int *)time(NULL));
  char *primeraSegundaQuinta[] = {"tus hijos no van a clase porque escuchan rap",
                                  "no hay de que preocuparse","tus hijos escuchan rap porque tienen clase"
                                  "El guerrero es sabio","hace del escenario un santuario","cielo de discipulos, inferno de adversarios"};


  char *terceraCuarta[] = {"si no existieran los colores","el hombre seria razista por los olores",
                           "si hay tanta comida por que hay bebes que lloran","y por que si somos tantos, tanta gente sigue sola"
                           "trabaja","plasma las palabras hazlas balas"};


  char rima[256];

  rimaRandom(rima, primeraSegundaQuinta, terceraCuarta);
  puts(rima);

  return 0;
}
void rimaRandom(char *rima, char **rima125, char **rima34){
  strcpy(rima, rima125[rand()% 5]);//1
  strcat(rima, "\n ");
  strcat(rima, rima125[rand()% 5]);//2
  strcat(rima, "\n ");
  strcat(rima, rima34[rand()% 5]);//3
  strcat(rima, "\n ");
  strcat(rima, rima34[rand()% 5]);//4
  strcat(rima, "\n ");
  strcat(rima, rima125[rand()% 5]);//5
  strcat(rima, ".");
  strcat(rima, "\0");
  rima[0] = toupper(rima[0]);
}
