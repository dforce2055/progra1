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
void calcTiempoVuelo(char *duracion, int hPartida, int mPartida, int hLLegada, int mLLegada);

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
  while(!feof(in)){
    vuelo = cpyVuelo(linea);
    mostrarVuelo(vuelo, "Montevideo(URUGUAY)");//desarrollar funcion para controlar destino.
    fgets(linea, 256, in);
  }


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
  error =   cpyCad(vuelo.dias[0],linea,5,7);  //lu
  error =   cpyCad(vuelo.dias[1],linea,8,10); //Ma
  error =   cpyCad(vuelo.dias[2],linea,11,13);//Mi
  error =   cpyCad(vuelo.dias[3],linea,14,16);//Ju
  error =   cpyCad(vuelo.dias[4],linea,17,19);//Vi
  error =   cpyCad(vuelo.dias[5],linea,20,22);//Sa
  error =   cpyCad(vuelo.dias[6],linea,23,25);//Do
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
  vuelo.empresa[strlen(vuelo.empresa)-1] = '\0';//Eliminar salto de línea

  if(error = 0){
    puts("Hubo un error al cargar el vuelo");
    return vueloVacio;
  }else return vuelo;
}
void mostrarVuelo(tVuelo vuelo, char *destino){
  int hPartida, mPartida, hLLegada, mLLegada;
  char duracion[10] = {0};

  sscanf(vuelo.hPartida, "%d", &hPartida);
  sscanf(vuelo.mPartida, "%d", &mPartida);
  sscanf(vuelo.hLLegada, "%d", &hLLegada);
  sscanf(vuelo.mLLegada, "%d", &mLLegada);

  if(strcmp(vuelo.ciudadDestino,destino) == 0){
    if(strcmp(vuelo.dias[0],"Lu") == 0 || strcmp(vuelo.dias[1],"Ma") == 0 || strcmp(vuelo.dias[5],"Sa") == 0){
      if(hPartida >= 15){
        if(mPartida >= 30){
          printf("%s - %s\n", vuelo.numVuelo, vuelo.ciudadDestino);
          printf("%s:%s\n", vuelo.hPartida, vuelo.mPartida);
          calcTiempoVuelo(duracion, hPartida, mPartida, hLLegada, mLLegada);
          printf("Duración estimada de vuelo: %s hs.\n", duracion);
          puts(vuelo.empresa);
          puts("================================================");
        }
      }
    }

  }
}
void calcTiempoVuelo(char *duracion, int hPartida, int mPartida, int hLLegada, int mLLegada){
  int i, horas = 0, minutos = 0;
  long int segPartida, segLLegada, segundos = 0;

  segPartida = (hPartida * 3600) + (mPartida * 60);
  segLLegada = (hLLegada * 3600) + (mLLegada * 60);
  segundos = segLLegada - segPartida;

  while(segundos >= 3600){
    horas++;
    segundos -= 3600;
  }
  while(segundos >= 60){
    minutos++;
    segundos -= 60;
  }
  if(horas < 9){
    if(minutos < 9){
      sprintf(duracion,"0%d:0%d", horas, minutos);
    }else sprintf(duracion,"0%d:%d", horas, minutos);
  }else sprintf(duracion,"%d:%d", horas, minutos);
}
