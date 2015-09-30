/* 4. Un supermercado desea contar con un programa que le permita registrar los datos de sus
artículos. En el mismo no existen más de 1000 productos distintos. Realizar un programa ABM
utilizando la estructura indicada en el punto 1.c, en el que los datos deberán estar ordenados
por nombre. Contemplar las siguientes funciones:

altaProd: parámetros recibidos serán el vector y la cantidad cargados hasta el momento. Esta
función deberá permitir cargar productos hasta que se llene el vector o hasta que ingresen un
nombre vacío en el campo nombre.

bajaProd: parámetros recibidos serán el vector y la cantidad cargados hasta el momento. Esta
función deberá permitir ingresar un nombre y eliminar los datos del producto.

mostrarProductos: parámetros recibidos serán el vector y la cantidad cargados hasta el momento.
Esta función deberá permitir mostrar los datos de todos los productos del supermercado.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
//linux clear | windows cls
typedef struct{
  int dia, mes, anio;
}tFecha;
typedef struct{
  char codBar[22];
  char nombre[80];
  float precio;
  int stock;
  tFecha fechaStock;
}tProducto;

void limpiarBuffer(void);
int menu(int *opcion);
void altaProd(tProducto productos[MAX], int *id);
void bajaProd(tProducto productos[MAX], int *id);
  int buscarProducto(tProducto productos[MAX], char *baja, int id);
  void reordenar(tProducto productos[MAX],int pos,int id);
void mostrarProductos(tProducto productos[MAX], int id);

int main(){
  tProducto productos[MAX];
  int opcion, id = 0;
  while(menu(&opcion)){
    switch(opcion){
     case 1:altaProd(productos, &id); break;
     case 2:bajaProd(productos, &id); break;
     case 3:mostrarProductos(productos, id); break;
     default: puts("Opcion desconocida"); break;
    }
  }

  return 0;
}
void limpiarBuffer(void){
  //Luego de cada scanf() es necesario limpiar la cola del teclado
  //para eliminar el salto de linea "\n"
  while(fgetc(stdin)!='\n');
}
int menu(int *opcion){
  puts("Bienvenido al Super Mercado Chino:");
  puts("==================================");
  puts("Que funcion desea realizar?");
  puts("1.Alta de Producto");
  puts("2.Baja de Producto");
  puts("3.Mostrar Productos");
  puts("0.Salir");
  scanf("%d", opcion);
  limpiarBuffer();
  return *opcion;
}
void altaProd(tProducto productos[MAX], int *id){
  //Recibe por referencia un vector de estructuras tProducto y la cantidad
  //de productos almacenados en el vector también por referencia.
  //Solicita la carga a traves de teclado para c/u de los campos y los
  //guarda en la posicion del vector de estructura, hasta llegar al maximo
  //o hasta cargar un producto con nombre vacio.
  int vacio = 0;

  for( ; *id < MAX && vacio != 1; *id += 1){
    printf("Ingrese Nombre del Producto id%2d: ", *id);
    fgets(productos[*id].nombre, 79, stdin);
    if(productos[*id].nombre[0] == '\n'){
      vacio = 1;
      system("cls");
      break;
    }
    printf("Ingrese Codigo de Barra: ");
    fgets(productos[*id].codBar, 21, stdin);
    printf("Ingrese Precio: ");
    scanf("%f", &productos[*id].precio);
    limpiarBuffer();
    printf("Ingrese la cantidad a stock: ");
    scanf("%d", &productos[*id].stock);
    limpiarBuffer();
  }
}
void bajaProd(tProducto productos[MAX], int *id){
  char baja[128];
  int pos = 0;

  printf("Ingrese el producto a dar de baja: ");
  fgets(baja,128, stdin);

  pos = buscarProducto(productos, baja, *id);
  baja[strlen(baja)-1] = '\0';//elimino \n de la cadena
  if(pos != -1){
    reordenar(productos, pos, *id);
  *id = *id - 1;
  printf("El producto \"%s\" ha sido eliminado\n", baja);
  }else{
    printf("\nEl producto \"%s\" no existe\n\n", baja);
  }
}
  int buscarProducto(tProducto productos[MAX], char *baja, int id){
  //Recibe por referencia un vector de estructuras tProducto y la cantidad
  //de productos almacenados en el vector también por referencia.
  //Ademas recibe por referencia una cadena
  //Busca en todas las posiciones del vector la cadena y devuelve la posicion
  int pos = -1, i;

  for(i = 0; i < id; i++){
    if(strcmp(productos[i].nombre, baja) == 0){
      pos = i;
    }
  }
  return pos;
}
  void reordenar(tProducto productos[MAX],int pos,int id){
  //Recibe por referencia un vector de estructuras tProducto y la cantidad
  //de productos almacenados en el vector por valor.
  //Tambien recibe por valor la posicion del vector a partir de cual se
  //debe reordenar. Reordena copiando en vector[n] -> vector[n-1]
  int i;

  for(i = pos; i < id; i++){
    productos[i] = productos[i+1];
  }
  strcpy(productos[i].codBar, "");//"" comillas dobles para string agrega el '\0'
}
void mostrarProductos(tProducto productos[MAX], int id){
  //Recibe por referencia un vector de estructuras tProducto y la cantidad
  //de productos almacenados en el vector también por referencia.
  //Imprime por pantalla los productos dentro del vector hasta llegar al ultimo
  int i;
  if(id > 0){
    system("cls");
    puts("##################");
    puts("Mostrar Productos:");
    puts("##################");
    for(i = 0; i < id; i++){
      printf("id: %2d\n", i);
      printf("Nombre: %s", productos[i].nombre);
      printf("Codigo de Barra: %s", productos[i].codBar);
      printf("Precio: $%.2f\n", productos[i].precio);
      printf("Stock: %2d\n\n", productos[i].stock);
    }
    puts("##########################");
    puts("Fin de productos en stock.");
    puts("##########################\n\n");
  }else{
      system("cls");
      puts("##############################");
      puts("No existen productos en stock");
      puts("##############################\n");
    }
}

