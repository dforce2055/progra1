int main(){
  //FILE *archivo = fopen("01.longitud.fija.txt", "rt");
  //FILE *archivo = fopen("02.longitud.fija.txt", "rt");
  FILE *archivo = fopen("03.longitud.variable.txt", "rt");
  Cheque cheque;

  if(!archivo){
    puts("Error al intentar abrir el archivo");
    return 1;
  }

  //fgets(linea, 256, archivo);
  /*while(!feof(archivo)){
    cheque = cargarCheque0(linea);
    puts(cheque.nombre);
    printf("%d/%d/%d\n", cheque.dd, cheque.mm, cheque.aa);
    printf("Domicilio: %s\n", cheque.domicilio);
    fgets(linea, 256, archivo);
  }*/


  /*cheque = cargarCheque1(archivo);
  while(!feof(archivo)){
    puts(cheque.nombre);
    printf("%d/%d/%d\n", cheque.dd, cheque.mm, cheque.aa);
    printf("Domicilio: %s\n", cheque.domicilio);
    puts("================================================");
    cheque = cargarCheque1(archivo);
  }*/

  cheque = cargarCheque2(archivo);

  while(!feof(archivo)){
    guardarCheque(cheque);
    puts(cheque.nombre);
    printf("%d/%d/%d\n", cheque.dd, cheque.mm, cheque.aa);
    printf("Domicilio: %s\n", cheque.domicilio);
    puts("================================================");
    cheque = cargarCheque2(archivo);
  }
  system("clear");
  puts("Mostrar Cheques Guardados");
  puts("================================================");
  mostrarCheques();


  fclose(archivo);
  return 0;
}
