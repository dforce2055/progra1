Miercoles 14 de Octubre de 2015
Temas: Archivos de texto. Entrada y salida con formato sobre archivos de texto.

Archivos de Texto:
Son cadenas de caracteres, en un archivo de texto cada linea equivale a un registro.
Las lineas tienen distintas longitudes, por eso los archivos de texto, tienen registros
de longitudes variables.
Cada registro termina en '\n'

                 -> windows: Retorno de carro (CR, ASCII 13) seguido de un avance de linea(LF, ASCII 10)
Delimitador '\n' -> Linux:   LF(line feed)
                 -> Mac:     CR

SIEMPRE TIENE QUE TERMINAR CON '\n' al final del archivo

Cuadro comparativo Archivos Binarios y de Texto:
===============================================
                              BINARIOS                        DE TEXTO
Contenido de los registros    Datos binarios:                 Cadena de caracteres
                              Variables simples y
                              estructuradas.
Longitud del registro         Fija                            Variables
Delimitador del registro      Ninguno                         \n
Conversión de Datos           NO                              SI, (\n windows, linux, mac)
Método de acceso              Secuencial o directo            Secuencial
Modo de apertura              Entrasa, Salida o E/S           Entrada o Salida

Procesamiento de archivos de texto:
==================================
1. Carácter a carácter
  fgetc(<archivo>)->char
  fputsc(<carácter>,<archivo>); //graba en archivo el caracter

2. Línea a Línea
  fgets(<cadena>,<nºmaximo>, <archivo>); //Lee hasta el salto de linea, agrega un '0'
  fputs(<cadena>,<archivo>);

3. Con formato
  //LEE DE A 1 PALABRA POR VEZ, LEE HASTA EL ESPACIO
  fscanf(<archivo>, <cadena control formato>, <direccion variable>);//Lee un archivo y guarda con formato en la direccion de variable
  fprintf(<archivo>, <cadena contol formato>, <datos>;)//Imprime en archivo con formato los datos

Ejemplo:
10/11/1990
23/1/1986
18/04/2013

fscanf(archivo, "%d/%d/%d", &dia, &mes, &anio);//No lee '\n'
c = fgetc(archivo);//leeo el '\n'

fseek(); con archivos de texto:
===========================
1.fseek() con desplazamiento 0 desde cualquier extremo del archivo
  fseek(archivo.texto, 0, SEEK_SET);
  fseek(archivo.texto, 0, SEEK_END);

2.fseek() con un desplazamiento obtenido previamente con la función ftell() y utilizar SEEK_SET;
  ftell() me indica donde se encuentra el indicador, guardo ese lugar para regresar en algun momento
