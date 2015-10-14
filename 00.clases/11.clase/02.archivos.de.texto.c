#include <stdio.h>
#include <ctype.h>
int main(){
  FILE *archivo;
  int i, vec[26] = {0};//representa el abecedario
  char c, cad[200];

  if((archivo = fopen("notas.txt","rt")) == NULL){
    puts("Error al intentar leer 'notas.txt'");
    return 1;
  }

  fgets(cad, 200, archivo);
  while(!feof(archivo)){
    for(i = 0; cad[i]; i++){
      c = toupper(cad[i]);
      if(isalpha(c))
        vec[c - 'A']++;//subindice de vector abecedario
    }
    fgets(cad, 200, archivo);
  }
  fclose(archivo);
  for(i = 0; i < 26; i++)
    printf("La letra %c aparece %d veces\n", i + 'A', vec[i]);

  return 0;
}
