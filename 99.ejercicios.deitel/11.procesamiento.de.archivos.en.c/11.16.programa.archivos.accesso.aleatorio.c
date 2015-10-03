#include <stdio.h>
#include <string.h>
typedef struct{
  int numCta;
  char apellido[15];
  char nombre[10];
  float saldo;
}tCliente;

void limpiarBuffer(void);
int menu(int *opcion);
int nuevoRegistro(FILE *archivo);
int actualizarCuenta(FILE *archivo);
int actualizarSaldo(FILE *archivo);
int borrarRegistro(FILE *archivo);
int guardarArchivoTexto(FILE *archivo);

int main(){
  FILE *archivo;
  tCliente cliente;
  int opcion = 1;

  if((archivo = fopen("credito.dat","rb+")) == NULL){
    puts("No se encuentra el archivo 'credito.dat'.\nAntes de ejecutar el programa debe crear el archivo de registros.");
    return 1;
  }

  while(menu(&opcion)){
    switch(opcion){
      case 1: if(nuevoRegistro(archivo)){
                puts("Nuevo registro generado exitosamente.");
              }else puts("### 0 registros fueron generados ###");
              break;
      case 2: if(actualizarCuenta(archivo)){
                puts("Registro actualizado exitosamente.");
              }else puts("### 0 registros fueron actualizados ###");
              break;
      case 3: if(actualizarSaldo(archivo)){
                puts("Registro actualizado exitosamente.");
              }else puts("### 0 registros fueron actualizados ###");
              break;
      case 4: if(borrarRegistro(archivo)){
                puts("Registro eliminado correctamente.");
              }else puts("### 0 registros fueron borrados ###");
              break;
      case 5: if(guardarArchivoTexto(archivo)){
                puts("Archivo de texto generado exitosamente.");
              }else puts("### 0 registros fueron guardados ###");
              break;
      default: puts("Opcion incorrecta."); break;
    }
  }

  fclose(archivo);
  return 0;
}
void limpiarBuffer(void){
  while(fgetc(stdin)!='\n')
    ;
}
int menu(int *opcion){
  puts("Bienvenido al sistema de actualización de registros:");
  puts("====================================================");
  puts("Que desea realizar?");
  puts("1.Agregar una nueva cuenta");
  puts("2.Actualizar datos de una cuenta");
  puts("3.Actualizar saldo en cuenta");
  puts("4.Borrar cuenta");
  puts("5.Almacenar en un archivo de texto con formato, las cuentas");
  puts("0.Salir");
  scanf("%d", opcion);
  limpiarBuffer();
  if(*opcion != 0) return 1;
  else return 0;
}
int nuevoRegistro(FILE *archivo){
  tCliente cliente;
  int cuenta = 0;

  system("clear");
  printf("Ingrese numero de cuenta: ");
  scanf("%d", &cuenta);
  limpiarBuffer();

  //ubico el archivo en el registro indicado por el usuario
  fseek(archivo, sizeof(cliente) * (cuenta -1), SEEK_SET);
  fread(&cliente, sizeof(cliente), 1, archivo);

  if(cliente.numCta != 0){
    puts("ERROR, esta intentando crear una cuenta que ya existe.");
    return 0;
  }
  cliente.numCta = cuenta;
  puts("ingrese Apellido, Nombre, saldo");
  fscanf(stdin, "%s%s%f", cliente.apellido, cliente.nombre, &cliente.saldo);
  //Ubico en el registro adecuado, ya que luego de fread el apuntador se movio 1 pos
  fseek(archivo, sizeof(cliente) * (cuenta -1), SEEK_SET);
  fwrite(&cliente, sizeof(cliente), 1, archivo);

  return 1;
}
int actualizarCuenta(FILE *archivo){
  tCliente cliente;
  int cuenta = 0;

  printf("Ingrese numero de cuenta: ");
  scanf("%d", &cuenta);
  limpiarBuffer();
  //ubico el registro indicado dentro del archivo
  fseek(archivo, sizeof(cliente) * (cuenta -1), SEEK_SET);
  fread(&cliente, sizeof(cliente), 1, archivo);

  if(cliente.numCta == 0){
    printf("ERROR, la cuenta %d no existe\n", cuenta);
    return 0;
  }
  puts("Ingrese Apellido, Nombre, Saldo");
  fscanf(stdin, "%s%s%f", cliente.apellido, cliente.nombre, &cliente.saldo);
  //ubico el registro indicado dentro del archivo
  fseek(archivo, sizeof(cliente) * (cuenta - 1), SEEK_SET);
  fwrite(&cliente, sizeof(cliente), 1, archivo);

}
int actualizarSaldo(FILE *archivo){
  tCliente cliente;
  int cuenta = 0;
  float saldo = 0.0;

  system("clear");
  puts("Ingrese el numero de cuenta para actualizar (1-100): ");
  scanf("%d", &cuenta);
  limpiarBuffer();
  //Muevo a la posicion de registro indicada por el usuario
  fseek(archivo, sizeof(cliente) * (cuenta - 1), SEEK_SET);
  fread(&cliente, sizeof(cliente), 1, archivo);

  if(cliente.numCta == 0){
    printf("El cuenta nro. %d no existe\n", cuenta);
    return 0;
  }

  printf("%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
  puts("Introduzca el cargo (+) o el pago (-): ");
  scanf("%f", &saldo);
  cliente.saldo += saldo;
  printf("%-6d%-16s%-11s%10.2f\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
  //muevo al registro indicado nuevamente ya que luego de fread se corrio 1 punto..
  fseek(archivo, sizeof(cliente) * (cuenta - 1), SEEK_SET);
  fwrite(&cliente, sizeof(cliente), 1, archivo);//guardo los cambios en el archivo

  return 1;
}
int borrarRegistro(FILE *archivo){
  tCliente cliente;
  int cuenta = 0;

  printf("Ingrese numero de cuenta: ");
  scanf("%d", &cuenta);
  limpiarBuffer();

  fread(&cliente, sizeof(cliente), 1, archivo);
  if(cliente.numCta == 0){
    printf("ERROR, la cuenta %d no existe\n", cuenta);
    return 0;
  }
  //ubico el puntero en el registro correcto
  fseek(archivo, sizeof(cliente) * (cuenta - 1), SEEK_SET);
  //inicializo cliente
  strcpy(cliente.apellido,"");
  strcpy(cliente.nombre,"");
  cliente.numCta = 0;
  cliente.saldo = 0.0;
  fwrite(&cliente, sizeof(cliente), 1, archivo);

  return 1;
}
int guardarArchivoTexto(FILE *archivo){
  FILE *archTexto;
  tCliente cliente;
  int i = 0;

  if((archTexto = fopen("registros.txt","wt")) == NULL){
    puts("No pudo crearse 'registro.txt");
    return 0;
  }
  rewind(archivo);//Establece el apuntador al inicio del archivo
  fread(&cliente, sizeof(cliente), 1, archivo);
  fprintf(archTexto,"%-6s%-16s%-11s%10s\n", "Cta", "Apellido", "Nombre", "Saldo");
  while(!feof(archivo)){
    if(cliente.numCta != 0){
      i++;
      fprintf(archTexto,"%-6d%-16s%-11s%10.2lf\n", cliente.numCta, cliente.apellido, cliente.nombre, cliente.saldo);
    }
    fread(&cliente, sizeof(cliente), 1, archivo);
  }
  fclose(archTexto);
  if(0 == i) return 0;
  else return 1;
}
