#include <stdio.h>
#include <string.h>

int main()
{
   char cadena[80] = "Esta es una, cadena con varias. palabras; separadas|por signos";
   char *token;
   
   /* get the first token */
   token = strtok(cadena, " -,|;.");
   
   /* walk through other tokens */
   while( token != NULL ) 
   {
      puts(token);
      token = strtok(NULL, " -,|;.");
   }
   
   return(0);
}
