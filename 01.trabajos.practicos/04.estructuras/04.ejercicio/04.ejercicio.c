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
#include <stdio.h>
#include <string.h>
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

void altaProd(tProducto productos[MAX], int *id);
void bajaProd(tProducto productos[MAX], int *id);
int buscarProducto(tProducto productos[MAX], char *baja, int id);
void mostrarProductos(tProducto productos[MAX], int id);
void limpiarBuffer(void);
void reordenar(tProducto productos[MAX],int pos,int id);
int menu(int *opcion);
int main(){
  tProducto productos[MAX];
  int opcion, id;
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
int menu(int *opcion){
  puts("Bienvenido al Super Mercado Chino:");
  puts("==================================");
  puts("¿Que funcion desea realizar?");
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
      system("clear");
      break;
    }
    puts("Ingrese Codigo de Barra: ");
    fgets(productos[*id].codBar, 21, stdin);
    puts("Ingrese Precio: ");
    scanf("%2f", &productos[*id].precio);
    limpiarBuffer();
    puts("Ingrese la cantidad a stock: ");
    scanf("%d", &productos[*id].stock);
    limpiarBuffer();
  }
}
void bajaProd(tProducto productos[MAX], int *id){
  char baja[128];
  int pos = 0;

  puts("Ingrese el producto a dar de baja: ");
  fgets(baja,128, stdin);
  pos = buscarProducto(productos, baja, *id);
  if(pos != -1){
    reordenar(productos, pos, *id);
  }
}
void mostrarProductos(tProducto productos[MAX], int id){
  //Recibe por referencia un vector de estructuras tProducto y la cantidad
  //de productos almacenados en el vector también por referencia.
  //Imprime por pantalla los productos dentro del vector hasta llegar al ultimo
  int i;
  if(id > 0){
    system("clear");
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
      system("clear");
      puts("##############################");
      puts("No existen productos en stock");
      puts("##############################\n");
    }
}
void limpiarBuffer(void){
  //Luego de cada scanf() es necesario limpiar la cola del teclado
  //para eliminar el salto de linea "\n"
  while(fgetc(stdin)!='\n');
}
int buscarProducto(tProducto productos[MAX], char *baja, int id){
  int pos = -1, i;

  for(i = 0; i < id; i++){
    if(strcmp(productos[i].nombre, baja) == 0){
      pos = i;
    }
  }
  return pos;
}
void reordenar(tProducto productos[MAX],int pos,int id){
  int i;

  for(i = pos; i < id; i++){
    productos[i] = productos[i+1];
  }
  //productos[i] = "NULL";//Como guardar una posición nula en un vector de structuras?
  strcpy(productos[i].codBar, "\0");
  strcpy(productos[i].nombre, "\0");
  productos[i].precio = 0;
  productos[i].stock = 0;
  productos[i].fechaStock.dia = 0;
  productos[i].fechaStock.mes = 0;
  productos[i].fechaStock.anio = 0;
}
