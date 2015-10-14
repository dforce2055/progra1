#include <stdio.h>
#include <ctype.h>
int main(){
  FILE *input, *output;
  char c;
  if((input = fopen("notas.txt", "rt")) == NULL){
    puts("NO pudo leerse el archivo 'notas.txt'");
    return 1;
  }
  if((output = fopen("notas2.txt", "wt")) == NULL){
    puts("NO pudo crearse el archivo 'notas2.txt'");
    fclose(input);
    return 1;
  }

  c = fgetc(input);
  while(!feof(input)){
    fputc(toupper(c), output);
    c = fgetc(input);
  }

  fclose(input);
  fclose(output);
  return 0;
}
