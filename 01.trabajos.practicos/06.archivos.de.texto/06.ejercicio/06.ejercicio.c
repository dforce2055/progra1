/* leer consiga.txt */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 10
typedef struct{
  char descripcion[256];
  float precioDesde, precioHasta, promedio;
}tProducto;

int grabarPrecios(tProducto *producto);
int grabarPromedios(char *precios);
  void grabarPoducto(FILE *out, tProducto producto);
  tProducto leerProducto(FILE *in);
  tProducto leerPromedio(FILE *in);
int mostrarMejores(char *promedios);


int main(){
  tProducto productos[SIZE] = {0};

  strcpy(productos[0].descripcion, "Destornillador");
  productos[0].precioDesde = 12.99;
  productos[0].precioHasta = 19.99;

  strcpy(productos[1].descripcion, "Tornillos");
  productos[1].precioDesde = 1.99;
  productos[1].precioHasta = 2.99;

  strcpy(productos[2].descripcion, "Arandelas");
  productos[2].precioDesde = 0.99;
  productos[2].precioHasta = 1.99;

  strcpy(productos[3].descripcion, "Busca Polo");
  productos[3].precioDesde = 16.99;
  productos[3].precioHasta = 22.00;

  grabarPrecios(productos);
  grabarPromedios("precios.txt");
  mostrarMejores("promedios.txt");

  return 0;
}
int grabarPrecios(tProducto *producto){
  //Recibe un arreglo de estructuras tProducto
  //Lo guarda en archivo de texto 'precios.txt'
  FILE *archivo;
  int i;
  if((archivo = fopen("precios.txt","wt")) == NULL){
    puts("Error al intentar grabar >'precios.txt'");
    return 0;
  }

  while(strlen(producto->descripcion) > 0){
    fputs(producto->descripcion, archivo);
    fprintf(archivo,"\n%.2f\n", producto->precioDesde);
    fprintf(archivo,"%.2f\n", producto->precioHasta);
    producto++;
    i++;
  }

  fclose(archivo);
  return 1;
}
int grabarPromedios(char *precios){
  //Recibe el nombre del archivo donde fueron guardados los precios
  //Lee cada producto y lo guarda en una estructura auxiliar tProducto
  //Calcula el promedio y lo almacena en la estructura auxiliar tProducto
  //Graba en archivo de texto 'promedios.txt' el nombre y el promedio
  //de cada producto
  FILE *in, *out;
  tProducto producto;

  if((in = fopen(precios,"rt")) == NULL){
    printf("El archivo %s no pudo ser leido", precios);
    return 0;
  }
  if((out = fopen("promedios.txt","wt")) == NULL){
    puts("El archivo >'promedios.txt' no pudo ser creado");
    fclose(in);
    return 0;
  }

  producto = leerProducto(in);
  while(!feof(in)){
    producto.promedio = (producto.precioDesde + producto.precioHasta) / 2;
    grabarPoducto(out, producto);
    producto = leerProducto(in);
  }

  fclose(in);
  fclose(out);
  return 1;
}
tProducto leerProducto(FILE *in){
  //Recibe un puntero a FILE
  //Lee de *in y guarda en una estructura axuliar el producto
  //Retorna la estructura auxiliar tProducto
  tProducto producto;
  char cadena[256];

  fgets(cadena, 256, in);
  strcpy(producto.descripcion, cadena);
  producto.descripcion[strlen(producto.descripcion)-1] = '\0';

  fgets(cadena, 256, in);
  sscanf(cadena, "%f", &producto.precioDesde);

  fgets(cadena, 256, in);
  sscanf(cadena, "%f", &producto.precioHasta);

  return producto;
}
void grabarPoducto(FILE *out, tProducto producto){
  //Recibe puntero a FILE y 1 producto
  //Lo guarda en archivo de texto FILE *out
  fputs(producto.descripcion,out);
  fprintf(out, "\n%.2f\n", producto.promedio);
}
int mostrarMejores(char *promedios){
  FILE *in;
  tProducto producto;
  int cant = 0;
  float promedio = 0;

  if((in = fopen(promedios,"rt")) == NULL){
    printf("El archivo %s no pudo ser leido", promedios);
    return 0;
  }

  //cantidad re registros
  producto = leerPromedio(in);
  while(!feof(in)){
    cant++;
    producto = leerPromedio(in);
  }

  rewind(in);
  //promedio de promedios
  producto = leerPromedio(in);
  while(!feof(in)){
    promedio = promedio + producto.promedio;
    producto = leerPromedio(in);
  }
  promedio = promedio / cant;
  printf("El promedio es de $%.2f\n", promedio);
  puts("Los productos que superan el promedio son:");

  rewind(in);
  //mostrar productos que superen el promedio
  producto = leerPromedio(in);
  while(!feof(in)){
    if(producto.promedio > promedio){
      printf("%s $%.2f\n", producto.descripcion, producto.promedio);
    }
    producto = leerPromedio(in);
  }

}
tProducto leerPromedio(FILE *in){
  //Recibe un puntero a FILE promedios.txt
  //Lee de *in y guarda en una estructura auxiliar el producto(descripción y promedio)
  //Retorna la estructura auxiliar tProducto
  tProducto producto;
  char cadena[256];

  fgets(cadena, 256, in);
  strcpy(producto.descripcion, cadena);
  producto.descripcion[strlen(producto.descripcion)-1] = '\0';

  fgets(cadena, 256, in);
  sscanf(cadena, "%f", &producto.promedio);

  return producto;
}
