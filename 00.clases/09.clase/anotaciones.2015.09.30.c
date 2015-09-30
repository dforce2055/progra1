Miercoles 30 de Septiembre de 2015
Temas: Archivos. Generalidades. Archivos binarios de acceso secuencial.

Archivo:
========
Un archivo es un conjunto de elementos llamados registros, todos del mismo tipo
de datos, que se almacena en un dispositivo externo, para preservar su contenido
a través del tiempo.

Clasificación de Archivos:
=========================
1.Según el contenido de los registros
    Archivos binarios:En un archivo binario los datos se guardan respetando el
                      mismo formato que tienen en memoria.

    Archivos de texto:En un archivo de texto los datos se guardan en forma de
                      cadenas de caracteres.

2.Según el sentido de la transferencia de datos.
  Archivos de Entrada(lectura);
  Archivos de Salida(escritura);
  Archivos de Entrada & Salida(lectura & escritura);

3.Según el metodo de acceso
  Archivos de acceso secuencial:En un archivo de acceso secuencial para acceder
                                al registro nº N, es necesario pasar por los N-1
                                registros anteriores.

  Archivos de acceso directo:En un archivo d acceso directo conociendo el número
                             de registros, es posible acceder a el en forma
                             directa.

Etapas en el trabajo con archivos:
=================================
1.Declaración
  FILE * archivo;

2.Apertura
  archivo = fopen("nombre.archivo", <modo.apertura>);
      binarios -> "archi.dat/.bin" {r, w, a} modo básico: read, write, append(agregar).modificadores{b,t}binario|texto
      texto    -> "archi.txt"
Ruta "c:\\nuevo\\arch.txt"
Ruta "c:/nuevo/arch.txt"

3.Procesamiento
 if(archivo == NULL) puts("erro al abrir el archivo.");
 else{
   procesamiento...
 }

4.Cierre
fclose(archivo);


3.Procesamiento de archivos binarios de acceso secuencial:
=========================================================
Escritura:
---------
fwrite(<direccion.del.bloque>, <tamaño.del.bloque>, <cantidad.de.bloques>, <archivo>);
fwrite(&alumno1, sizeof(alumno1), 1, archivo);
//fwrite devuelve la cantidad de bloques copiados, deberia coincidir con <cantidad.de.bloques> 3er parametro;
#######################################################################################################
SE PUEDE GRABAR UN VECTOR ENTERO EN UN ARCHIVO SIN UTILIZAR UN CICLO PARA RECORRER TODAS SUS POSICIONES
#######################################################################################################
vector a estructuras de 50 elementos
fwrite(vectorCurso, sizeof(strcut sAlumno), 50, archivo);

Indicador de registro activo:
============================
Este indicador señala en todo momento se va a realizar la proxima grabación o lectura.
fopen(); situa el indicador en la posicion 0.
fwrite(); graba en la posición del indicador. Al terminar la escritura, el indicador avanza.


Lectura:
-------
fread(<direccion.del.bloque>,<tamaño.del.bloque>,<cantidad.del.bloque>,<archivo>);
feof(*FILE); File End Of File; retorna 1:verdadero | falso:0;

Siempre leer el registro completo, sino el indicador de registro activo queda mal posicionado
Jamás leer ni grabar a nivel de campo, siempre registro completo.

###########################################################################################
LOS ARCHIVOS BINARIOS NO SE PUEDEN EDITAR, SIEMPRE SE DEBE LEER EL ARCHIVO ENTERO,
REALIZAR LAS MODIFICACIONES NECESARIAS, Y COPIARLO EN UN ARCHIVO NUEVO DE A 1 O 2 REGISTROS
POR VEZ LUEGO BORRAR EL ARCHIVO ORIGINAL Y RENOMBRAR EL NUEVO CON EL ARCHIVO NUEVO COMO EL
ORIGINAL
###########################################################################################
