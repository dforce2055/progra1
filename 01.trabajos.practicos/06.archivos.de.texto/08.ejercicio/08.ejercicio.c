/*leer consigna.txt*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
  char numVuelo[5];        //01-04
  char dias[7][3];         //6-25
  char ciudadDestino[25];  //27-49
  char hPartida[3];        //51-52
  char mPartida[3];        //54-55
  char hLLegada[3];        //57-58
  char mLLegada[3];        //60-61
  char empresa[27];        //63-89->fin de línea
}tVuelo;
tVuelo cpyVuelo(char *linea);
int cpyCad(char *destino, char *salida, int desde, int hasta);
void eliminarEspacios(char *cadena);
void mostrarVuelo(tVuelo vuelo, char *destino);

int main(){
  FILE *in;
  tVuelo vuelo;
  char linea[256];
  char destino[80];

  if((in = fopen("vuelos.2015.txt","rt")) == NULL){
    puts("No pudo leerse >\'vuelos.txt\'");
    return 1;
  }

  fgets(linea, 256, in);
  vuelo = cpyVuelo(linea);

  //puts("Ingrese Destino: ");
  //fgets(destino, 79, stdin);
  //destino[strlen(destino)-1] = '\0';
  mostrarVuelo(vuelo, "Cordoba");

  fclose(in);
  return 0;
}
int cpyCad(char *destino, char *salida, int desde, int hasta){
  //Recibe una cadena destino y origen, ademas 2 enteros desde y hasta
  //Copia en destino desde origen lo indicado por desde y hasta
  //Finaliza la cadena con el caracter nulo '\0';
  int i;
  for(; desde < hasta; desde++){
    *destino = salida[desde];
    destino++;
  }
  *destino = '\0';
  return (desde == hasta)?1:0;
}
void eliminarEspacios(char *cadena){
  int i = 0;
  for(i = 0; cadena[i] != ' '; i++);
  cadena[i] = '\0';
}
tVuelo cpyVuelo(char *linea){
  //Recibe una cadena *linea con todos los datos de 1 vuelo
  //Guarda los valores en la variable correspondiente
  //Retorna una estructura vuelo cargada por completo
  tVuelo vuelo, vueloVacio = {0};
  int error = 0, i = 0;

  error =   cpyCad(vuelo.numVuelo,linea,0,4);
  eliminarEspacios(vuelo.numVuelo);
  error =   cpyCad(vuelo.dias[0],linea,5,7);  //lun.
  eliminarEspacios(vuelo.dias[0]);
  error =   cpyCad(vuelo.dias[1],linea,8,10); //Mar.
  eliminarEspacios(vuelo.dias[1]);
  error =   cpyCad(vuelo.dias[2],linea,11,13);//Mie.
  eliminarEspacios(vuelo.dias[2]);
  error =   cpyCad(vuelo.dias[3],linea,14,16);//Jue.
  eliminarEspacios(vuelo.dias[3]);
  error =   cpyCad(vuelo.dias[4],linea,17,19);//Vie.
  eliminarEspacios(vuelo.dias[4]);
  error =   cpyCad(vuelo.dias[5],linea,20,22);//Sab.
  eliminarEspacios(vuelo.dias[5]);
  error =   cpyCad(vuelo.dias[6],linea,23,25);//Dom.
  eliminarEspacios(vuelo.dias[6]);
  error =   cpyCad(vuelo.ciudadDestino,linea,26,48);
  eliminarEspacios(vuelo.ciudadDestino);
  error =   cpyCad(vuelo.hPartida,linea,50,52);
  eliminarEspacios(vuelo.hPartida);
  error =   cpyCad(vuelo.mPartida,linea,53,55);
  eliminarEspacios(vuelo.mPartida);
  error =   cpyCad(vuelo.hLLegada,linea,56,58);
  eliminarEspacios(vuelo.hLLegada);
  error =   cpyCad(vuelo.mLLegada,linea,59,61);
  eliminarEspacios(vuelo.mLLegada);
  error =   cpyCad(vuelo.empresa,linea,62,88);
  eliminarEspacios(vuelo.empresa);

  if(error = 0){
    puts("Hubo un error al cargar el vuelo");
    return vueloVacio;
  }else return vuelo;
}
void mostrarVuelo(tVuelo vuelo, char *destino){

  if(strcmp(vuelo.ciudadDestino,destino) == 0){
    puts(vuelo.empresa);
  }
}
