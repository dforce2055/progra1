/*
 * Clase #08
 * Martes 17 de Septiembre de 2013
 * Archivos. Generalidades. Archivos binarios de acceso secuencial.
 * ******************************************************************
 * 
 * Archivos de acceso directo. Ordenamiento de archivos. Búsqueda binaria.
 * ***********************************************************************
 * 
 * Indicador de registro activo = podria hacerse un paralelo con la Dirección en memoria de un vector
 * 
 * rewind(<archivo(variable puntero a file)>); 
 * · Para utilizarla es necesario que el archivo este abierto
 * · Va a volver a apuntar al comienzo del "ARCHIVO", al 1er registro
 * 
 * fseek(<archivo>,<Nª entero, indica desplazamiento>,<Nº entero, punto de partida>);
 * 		ptr				Nº de bytes							SEEK_SET | SEEK_CUR | SEEK_END
 * 		ptr				Nª de registro * sizeoff(reg)		Principio| Actual	| Final
 * 
 * SEEK_END > EXPANDIR UN ARCHIVO, investigar
 * 
 * Tipo de acceso al archivo:
 * rb+			El archivo tiene que existir
 * wb+			Abre el archivo y destuye cualquier archivo anterior con mismo nombre
 * ab+			Abre el archivo y agrega datos al final
 * 
 * Pasos para actualizar un archivo:
 * *********************************
 * fseek(archivo, n * sizeoff(registro), SEEK_SET);		Posición dentro del archivo
 * fread(&reg, sizeoff(registro), 1, archivo);			Lee el registro
 * strcpy(reg.domicilio, nuevo_domicilio);				graba en memoria el cambio
 * fseek(archivo, n * sizeoff(registro), SEEK_SET);		reposicionamiento al registro correcto y no al siguiente
 * 	fsekk(archivo, -1 *(int) sizeoff(registro), SEEK_CUR);	Reposicionamiento con SEEK_CUR (hay que castear el entero para que devuelva signo)
 * fwrite(&reg, sizeoff(reg), 1, archivo);				graba archivo en disco
 * 
 * 
 * ftell(<archivo>);	posición del indicador de registro activo, lo devuelve expresado en bytes
 * 						indicador de registro activo / sizeoff(reg) = registro
 * 
 * fseek(archivo, 0, SEEK_END);
 * n = ftell(archivo) / sizeof(registro)); //++++++++++++++++++++++++++++++++cantidad de registro+++++++++++++++++++++++++
 * 
 * /
