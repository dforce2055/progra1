/* 1.Hacer una función que permita eliminar todos los comentarios de una o varias líneas de
un programa fuente escrito en lenguaje “C”,. */
//strstr(cadena,//);
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int eliminarComentarios(FILE *input, FILE *output);
int main(){
  FILE *input, *output;

  if((input = fopen("comentarios.txt","r")) == NULL){
  puts("Error al leer 'comentarios.txt'");
  return 1;
  }
  if((output = fopen("comentarios2.txt","wt")) == NULL){
  puts("Error al crear 'comentarios2.txt'");
  fclose(input);
  return 1;
  }

  if(eliminarComentarios(input, output)) puts("Comentarios eliminados");
  else puts("No existen comentarios en el archivo");

  fclose(input);
  fclose(output);
  return 0;
}
int eliminarComentarios(FILE *input, FILE *output){
  char cadena[256];
  char c;
  char *pComSimple, *pComInicio, *pComFin = 0;
  int hayComentarios = 0, i = 0;
  //Elimina comentarios simples
  fgets(cadena,256,input);
  while(!feof(input)){
  pComSimple = strstr(cadena,"//");
  pComInicio = strstr(cadena,"/*");
  if(pComInicio != NULL)
    i = 1;

  if(pComSimple != NULL){
    *pComSimple = '\0';
    hayComentarios = 1;
    fputs(cadena,output);
    fputc('\n',output);
    }else if(i == 1 ){
          while(c != '*' && !feof(input)){
              c = fgetc(input);
            }
            c = fgetc(input);
            if(c == '/'){
              fputc('\n', output);
              i = 0;
              pComInicio == NULL;
            }
      }else{
        fputs(cadena,output);
      }
  fgets(cadena,256,input);
  }



  if(hayComentarios != 0) return 1;
  else return 0;
}
