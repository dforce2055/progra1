/*
 * Clase #07
 * Martes 17 de Septiembre de 2013
 * Archivos. Generalidades. Archivos binarios de acceso secuencial.
 * ******************************************************************
 * Definición: es un conjunto de elementos lamados registros, todos del mismo tipo que se almacena en un dispositivo auxiliar
 * para conservar su contenido a través del tiempo. conjunto homogeneo de registros.
 * 
 * Clasificación de archivos:
 * 
 * -Según el contenido de sus registros:
 * 		Archivos binarios: la información se guarda respetando el mismo formato que tiene en memoria.
 * 		Archivos de texto: los datos se guardan como cadenas de caracteres.
 * 
 * -Según el sentido de la transferencia:
 * 		Archivos de entrada(archivos  de lectura)		rb
 * 		Archivos de salida(archivos de escritura)		wb
 * 		Archivos de entrada/salida(lectura/escritura)	ab
 * 
 * -Según el metodo de acceso:
 * 		Archivos secuenciales(es necesario recorrer todo el documento hasta llegar al registro especificado)
 * 		Archivos de acceso directo(este tipo de archivos permite acceder directamente al registro)
 * 
 * Etapas para manejo de archivos:
 * *******************************
 * 1- Declaración: 		declaración de variable (puntero) a nuestro archivo
 * 2- Apertura:			encargada de vincular el archivo con el medio externo
 * 3- Procesamiento		procesa los datos, lectrua y grabación de datos dentro del archivo
 * 4- Cierre			cierra el archivo
 * 
 * 1- Declaración:
 * FILE * archi; /* punto a estructura de arhivo FILE 
 * 
 * 2- Apertura:
 * Establecer los canales de comunicación con el dispositivo que contiene el archivo
 * Reserva areas de memorias temporarias llamadas "BUFFERS", sirven para agilizar las tareas de transferencia de datos
 * 
 * archi = fopen(<nombre_de_archivo>, <modo_de_apertura>); // devuelve un puntero a el archivo
 * 		<nombre>	"datos.dat"
 * 			"c:\\nuevo\\datos.dat" (utilizar doble barra invertidas)
 * 			"c:/nuevo/datos.dat"
 * 		<mode_de_apertura>
 * 			básico: r(read) w(write) a(append)
 * 				modificadores: b(binario) t(texto)
 * 
 * 4- Cierre
 * fclose(arch); // devuelve 0 para cierre positivo, cualquier número distinto a 0 para indicar error.
 * 
 * 3- Procesamiento:
 * Arhivos Binarios de acceso secuencial:
 * Grabar registros en archivos
 * 
 * fwrite(<dirección_del_bloque_a_grabar>,<tamaño_de_bloque>,<cantidad_de_bloques>,<archivos>);
 * fwrite(&alumno1, 						sizeoff(alumno1),			1,				ptrarch);
 * 
 * struc salumno curso[50];
 * 
 * fwrite(curso,sizeoff(struct salumno), 50, arch);
 * 
 * 
 * Leer Registros en archivos
 * 
 * fread(<dirección_del_bloque_a_leer>,<tamaño_de_bloque>,<cantidad_de_bloques>,<archivo>);
 * 
 * feof(File End Of File) Se utiliza previa lectura del archivo
 * feof(<archivo>)	V = 0 |		F = !0
 * 
 */
