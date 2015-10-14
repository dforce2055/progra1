Miercoles 06 de Octubre de 2015
Temas: Archivos de acceso directo. Ordenamiento de archivos.

Archivos Binarios de Acceso Directo:
====================================
Indicador de registro activo.
rewind(<archivo>);

                                      SEEK_END : Desde el comienzo del archivo
                                      SEEK_CUR : Desde la posición actual(desplazamiento +[der] y -[izq])
                                      SEEK_END : Desde el final, desplazamiento + solo para grabar
fseek(<archivos>, <desplazamiento>, <punto de partida>);
                    Nº de bytes
                    Nº de registro * sizeof(<registro>);


fseek(archivo, sizeof(reg) * 2, SEEK_END);//corre el indicador de reg. activo 2 lugares más allá del final del archivo
fwrite(&reg, sizeof(reg), 1, archivo);//Graba un registro allí mismo, esto genera que el sistema, guarde basura
                                     //entre el ultimo registro y los 2 que salteamos, genera 2 registros con valores basura
//Esto se llama expandir un archivo, generar espacio en disco, con registros con basura para luego, guardar datos validos
//La misma tecniva es utilizada por archivos torrents
expandir un archivo(el sistema llena los registros de basura)

Modos de apertura de archivo:
============================
rb+ -> Lee y graba, sino existe error.
wb+ -> Escribe y graba, si existe  el archivo borra el contenido.
ab+ -> Agrega y graba, se agregan registros al final, NO SE MODIFICAN REGISTROS ALMACENADOS ANTERIORMENTE

Función FTELL(<archivo>);
========================
ftell(<archivo>) -> devuelve indicador de registro activo. En BYTES. Hay que dividir por el sizeof(reg);

Ordenamiento de archivos:
========================
Ordenamiento por selección.

Desplazamientos NEGATIVOS:
--------------------------
fseek(archivo, -1 * (int)sizeof(alumno), SEEK_CUR);//desplazo 1 lugar a la izquierda (*-1) || cast de la devolucion de sizeof, que devuleve entero sin signo

Cambiar el sentido de trabajo LECTURA > GRABACION || GRABACION -> LECTURA:
fseek(archivo, 0, SEEK_CUR); corre 0 bytes, en la ubicación actual.
Es obligatorio utilizar fseek, luego de cambiar el sentido de trabajo, de lectura a grabacióny viceversa.

Borrado logico de registros:
===========================
No se borran realmente, sino que le agregamos una marca, al campo llave.
Con lo cual eso sirve, para saber que ese registro no es valido.
