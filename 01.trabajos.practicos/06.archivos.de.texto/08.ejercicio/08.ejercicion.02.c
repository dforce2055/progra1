/*leer consigna.txt*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LU vuelo.dia.Lu
#define MA vuelo.dia.Ma
#define MI vuelo.dia.Mi
#define JU vuelo.dia.Ju
#define VI vuelo.dia.Vi
#define SA vuelo.dia.Sa
#define DO vuelo.dia.Do

typedef struct Dia{
  char Lu[3], Ma[3], Mi[3], Ju[3], Vi[3], Sa[3], Do[3];
}Dia;

typedef struct Vuelo{
  char numVuelo[5];   //0-5 copiar
  Dia dia;    //05-20 días de la semana de salida (se indica con “No”
                      //si ese día el avión no parte del aeropuerto)
  char destino[25];    //27-49 ciudad de destino
  char hPartida[3];   //51-52 hora de partida
  char mPartida[3];   //54-55 minuto de partida
  char hLLegada[3];   //57-58 hora de llegada
  char mLLegada[3];   //60-61 minuto de llegada
  char empresa[27];   //63-89 empresa de aviación
  char duracionVuelo[6]; //duración del vuelo formato hh:mm
}Vuelo;

int cargarVuelo(char *linea, Vuelo *vuelo);
int cpycad(char *destino, char *origen, int desde, int hasta);
void eliminarEspacios(char *cadena);
void mostrarVuelo(Vuelo vuelo);
int validarDestino(Vuelo vuelo, char *destino);
void calcularHorasDeVuelo(Vuelo *vuelo);

int main(){
  FILE *archivo = fopen("vuelos.2015.txt", "rt");
  Vuelo vuelo;
  char linea[256];
  char destino[80];
  int error = 0;

  if(!archivo){
    puts("Hubo un error al intentar abrir el archivo");
    return 1;
  }
  printf("Que destino desea conocer?: ");
  fgets(destino, 80, stdin);


  fgets(linea, 256, archivo);
  error = cargarVuelo(linea, &vuelo);
  if(error){
    puts("Hubo un error al cargar el vuelo");
    return 0;
  }
  while(!feof(archivo)){
    if(validarDestino(vuelo, destino)){
      calcularHorasDeVuelo(&vuelo);
      mostrarVuelo(vuelo);
    }
    fgets(linea, 256, archivo);
    cargarVuelo(linea, &vuelo);
  }

  fclose(archivo);
  return 0;
}
int cargarVuelo(char *linea, Vuelo *vuelo){
  ///Recibe una cadena *linea con todos los datos de 1 vuelo
  ///Guarda los valores en la variable correspondiente
  ///Retorna una estructura vuelo cargada por completo
  Vuelo vueloVacio = {0};
  int error = 0, i = 0;

  error =   cpycad(vuelo->numVuelo,linea,0,4);
  eliminarEspacios(vuelo->numVuelo);
  error =   cpycad(vuelo->dia.Lu,linea,5,7);  //lu
  error =   cpycad(vuelo->dia.Ma,linea,8,10); //Ma
  error =   cpycad(vuelo->dia.Mi,linea,11,13);//Mi
  error =   cpycad(vuelo->dia.Ju,linea,14,16);//Ju
  error =   cpycad(vuelo->dia.Vi,linea,17,19);//Vi
  error =   cpycad(vuelo->dia.Sa,linea,20,22);//Sa
  error =   cpycad(vuelo->dia.Do,linea,23,25);//Do
  error =   cpycad(vuelo->destino,linea,26,48);
  eliminarEspacios(vuelo->destino);
  error =   cpycad(vuelo->hPartida,linea,50,52);
  eliminarEspacios(vuelo->hPartida);
  error =   cpycad(vuelo->mPartida,linea,53,55);
  eliminarEspacios(vuelo->mPartida);
  error =   cpycad(vuelo->hLLegada,linea,56,58);
  eliminarEspacios(vuelo->hLLegada);
  error =   cpycad(vuelo->mLLegada,linea,59,61);
  eliminarEspacios(vuelo->mLLegada);
  error =   cpycad(vuelo->empresa,linea,62,88);
  eliminarEspacios(vuelo->empresa);

  return(error)?0:1;
}
int cpycad(char *destino, char *origen, int desde, int hasta){
  ///Recibe 2 cadenas por referencia y 2 enteros que indican el inicio y el final
  ///de la copia caracter por caracter.
  ///Si existe algun error, retorna 0. Si todo salio bien retorna 1.
  for(; desde < hasta; desde++){
    *destino = origen[desde];
    destino++;
  }
  *destino = '\0';
  return (desde == hasta)?1:0;
}
void eliminarEspacios(char *cadena){
  ///Recibe una cadena con espacios al final, recorre la cadena desde el final
  ///hacia el principio, hasta encontrar el primer caracter distinto de '0'
  ///modifica la cadena y pone el fin de la cadena
  int i = strlen(cadena);

  for(; cadena[i] == ' '; i--);
  cadena[i] = '\0';
}
void mostrarVuelo(Vuelo vuelo){
  printf("Vuelo N:%s\n", vuelo.numVuelo);
  printf("Dias: %s|%s|%s|%s|%s|%s|%s|\n", LU, MA, MI, JU, VI, SA, DO);
  printf("Hora de partida: %s:%s\n", vuelo.hPartida, vuelo.mPartida);
  printf("Hora de llegada: %s:%s\n", vuelo.hLLegada, vuelo.mLLegada);
  printf("Duración estimada del vuelo: %s\n", vuelo.duracionVuelo);
  printf("Destino:%s\n", vuelo.destino);
  printf("Aerolinea:%s\n", vuelo.empresa);
  puts("=================================");
}
int validarDestino(Vuelo vuelo, char *destino){
  ///Valida el destino con la cadena de texto pasada como referencia.
  ///Si el destino coincide retorna 1. Caso contrario retorna 0.
  int valido = 0;
  int hLLegada, mLLegada, hPartida, mPartida;
  sscanf(vuelo.hPartida, "%d", &hPartida);
  sscanf(vuelo.mPartida, "%d", &mPartida);
  sscanf(vuelo.hLLegada, "%d", &hLLegada);
  sscanf(vuelo.mLLegada, "%d", &mLLegada);

  if(strncmp(vuelo.destino, destino, 4) == 0){
      if(strcmp(vuelo.dia.Lu, "No") != 0 ||
        strcmp(vuelo.dia.Ma, "No") != 0 ||
        strcmp(vuelo.dia.Sa, "No") != 0){
        if(hPartida >= 15){
          if(mPartida >= 30){
            valido = 1;
          }
        }
      }
  }
  return valido;
}
void calcularHorasDeVuelo(Vuelo *vuelo){
  ///Recibe un vuelo por referencia, calcula las horas de vuelo y carga en el
  ///campo duracionVuelo el resultado
  int hPartida, mPartida, hLLegada, mLLegada, segPartida, segLLegada, duracion,
      horas = 0, minutos = 0;

  sscanf(vuelo->hPartida, "%d", &hPartida);
  sscanf(vuelo->mPartida, "%d", &mPartida);
  sscanf(vuelo->hLLegada, "%d", &hLLegada);
  sscanf(vuelo->mLLegada, "%d", &mLLegada);

  segPartida = (hPartida * 3600) + (mPartida * 60);
  segLLegada = (hLLegada * 3600) + (mLLegada * 60);
  duracion = segLLegada - segPartida;

  while(duracion >= 3600){
    horas++;
    duracion -= 3600;
  }
  while(duracion >= 60){
    minutos++;
    duracion -= 60;
  }
  if(horas < 9){
    if(minutos < 9){
      sprintf(vuelo->duracionVuelo,"0%d:0%d", horas, minutos);
    }else sprintf(vuelo->duracionVuelo,"0%d:%d", horas, minutos);
  }else sprintf(vuelo->duracionVuelo,"%d:%d", horas, minutos);
}
