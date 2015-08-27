/* PROGRAMA CORRESPONDIENTE A LA SEGUNDA ETAPA DEL TP OBLIGATORIO DE PROGRAMACI�N I LOS D�AS LUNES DE 7.45 A 11.45 EN EL AULA 212

EL MISMO SE ENCARGA DE UN SISTEMA DE GESTI�N DE STOCK DE PRODUCTOS, CON SU CORRESPONDIENTE ABM CON LISTA ENLAZADA, COMO AS� TAMBI�N LISTADO DE PRODUCTOS ACTIVOS, GUARDADO Y LECTURA DE DATOS EN ARCHIVO

INTEGRANTES:	113987 - ISLA CASARES, GASTON
				124427 - MAGNETICO, HERNAN
				116687 - ZUCCHINO, MARIA CECILIA

PROGRAMADO BAJO PLATAFORMA: MICROSOFT WINDOWS 7 ENTERPRISE
COMPILADO GRACIAS A: MICROSOFT VISUAL STUDIO 2008 ENGLISH */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define CODIGOBARRAS 21
#define DESCRIPCIONPRODUCTO 30
#define NOMBREARCHIVO 250
#define CODIGOPAIS 4
#pragma warning (disable:4996)

/********* DECLARACION DE ESTRUCTURAS *********/
typedef struct
{
	int dia, mes, anio;
}sfecha;

typedef struct n
{
	char codigoBarras[CODIGOBARRAS];
	char descripcion[DESCRIPCIONPRODUCTO];
	sfecha fechaActualizacion;
	float precio;
	int cantidad;
	char nombreArchivo[NOMBREARCHIVO];
	struct n *siguiente, *anterior;
}nodo, *pNodo;

typedef struct
{
	pNodo inicio;
}lista;

typedef struct p
{
	char cod[3];
	struct p *siguiente;
}pais, *pPais;

typedef struct
{
	pPais inicio;
}listaPaises;


/********* DECLARACION DE ENCABEZADOS DE FUNCIONES *********/
void actualizarExistencia(lista pLista);
void altaProducto(lista *pDada, listaPaises pLista);
void bajaProducto(lista pLista);
int buscarCodigoBarras(lista pLista, char cod[CODIGOBARRAS]);
pNodo buscarProducto(lista p);
//int cargarDatosArchivo(sproducto l[]);
void cargaFecha(sfecha *fecha);
void cargarArchivoCodigoPaises(listaPaises *ppais);
void crearArchivoCodigoPaises();
void copiarFechas(sfecha *destino, sfecha *origen);
void guardarDatosArchivo(lista pNodo);
void eliminarRetornoCadena(char cad[]);
void imprimirDatosEncolumnados(lista pLista);
void imprimirFecha(sfecha fecha);
void imprimirLista(lista pLista);
void imprimirProducto(pNodo n);
void inicializarLista(lista *pDada);
void inicializarListaPaises(listaPaises *pLista);
void menu(int *opc);
void modificarProducto(nodo *actual);
void obtenerFechaActual(sfecha *fActual);
void ordenarListaEnlazada(lista *pLista);
void salir(int *s);
int validad_bisiesto(int a);
int validarCodigo(char cod[CODIGOBARRAS]);
int validarCodigoPaisEnCodigoBarras(char codigoBarras[CODIGOBARRAS], listaPaises pList);
int validarFechaGregoriana(sfecha *f);
int verificarFechaConFechaActual(sfecha *fActual, sfecha *fecha);
void verListaCodigoPaises(listaPaises pList);

/******** FUNCION PRINCIPAL *********/
/*NO RECIBE DATOS COMO PARAMETROS DESDE LA CONSOLA DE COMANDOS, DEVUELVE 0 SI LA EJECUCION FINALIZA DE FORMA CORRECTA*/

int main(void)

{
	lista dada;
	listaPaises lPaises;
	int opcion=0;
	nodo *auxiliar;
	inicializarLista(&dada);
	inicializarListaPaises(&lPaises);
	cargarArchivoCodigoPaises(&lPaises);

	do
	{
		menu(&opcion);
		if(opcion!=0){
			switch(opcion)
			{
			case 1:
				altaProducto(&dada, lPaises);
				break;
			case 2:
				
				auxiliar=buscarProducto(dada);
				modificarProducto(auxiliar);
				break;
			case 3:
				bajaProducto(dada);
				break;
			case 4:
				actualizarExistencia(dada);
				break;
			case 5:
				//ordenarLista(stock, cantidad);
				imprimirDatosEncolumnados(dada);
				break;
			case 6:
				crearArchivoCodigoPaises();
				break;
			case 7:
				inicializarListaPaises(&lPaises);
				cargarArchivoCodigoPaises(&lPaises);
				//verListaCodigoPaises(lPaises);
				break;
			}
		}
	}while(opcion!=0);
	//guardarDatosArchivo(dada);
	return 0;
}

/* MENU DESPLEGABLE PARA ACCEDER A LAS OPCIONES DEL SISTEMA */
/* RECIBE COMO PARAMETRO UN PUNTERO A ENTERO Y DEVUELVE EL VALOR CARGADO PARA ACCEDER A LA OPCION ELEGIDA */
void menu(int *opc)
{
	printf("\n*********** MENU ***********\n");
	do
	{
		if(*opc<0 || *opc>7)
			printf("Opcion incorrecta, ingresar nuevamente\n");
		printf("0. SALIR\n");		
		printf("1. Alta de producto\n");
		printf("2. Modificacion de producto\n");
		printf("3. Baja de producto\n");
		printf("4. Actualizacion de stock\n");
		printf("5. Ver lista de stock\n");
		printf("6. Modificar archivo con codigo de paises\n");
		printf("7. Cargar archivo con codigo de paises\n");
		printf("Ingrese la opcion a realizar: ");
		scanf("%d", opc);
	}while(*opc<0 || *opc>7);
}

/*FUNCIONA INICIALIZAR LISTA DE PRODUCTOS
  COMO DATOS DE ENTRADA RECIBE UN PUNTERO DE TIPO LISTA
  DEVUELVE EL MISMO PUNTERO INICIALIZADO EN NULL PARA SU POSTERIOR UTILIZACION*/
void inicializarLista(lista *pDada)
{
	pDada->inicio=NULL;
}

/* FUNCION ALTA DE PRODUCTO, VALIDANDO SUS CAMPOS DE FORMA CORRECTA */
/* COMO DATO DE ENTRADA RECIBE EL VECTOR DE ESTRUCTURA CON LA CANTIDAD DE REGISTROS QUE POSEE EL MISMO */
/* COMO SALIDA, EN CASO DE DARSE DE ALTA PRODUCTOS, SE DEVUELVE LA CANTIDAD INCREMENTADA POR DICHO PRODUCTOS NUEVOS */
void altaProducto(lista *pDada, listaPaises pLista)
{
	pNodo nuevo, actual;
	int salida=1;
	sfecha fechaActual;

	obtenerFechaActual(&fechaActual);
	
	while(salida==1)
	{
		do
		{
			fflush(stdin);
			nuevo=(nodo*)malloc(sizeof(nodo));
			if(nuevo==NULL)
				printf("\nNo hay espacio en memoria\n");
			else
				{
				printf("\nIngrese codigo de barras (Vacio=Salir): ");
				fgets(nuevo->codigoBarras, CODIGOBARRAS, stdin);
				eliminarRetornoCadena(nuevo->codigoBarras);

				if((validarCodigo(nuevo->codigoBarras))!=1)
					printf("El codigo de barras no es alfanumerico\n");
				if(buscarCodigoBarras(*pDada, nuevo->codigoBarras)==1)
					printf("El codigo del producto esta repetido\n");
				if(validarCodigoPaisEnCodigoBarras(nuevo->codigoBarras, pLista)==0)
					printf("El codigo de pais no se encuentra en el archivo de paises\n");
			}
		}while(((validarCodigo(nuevo->codigoBarras))!=1) || (buscarCodigoBarras(*pDada, nuevo->codigoBarras))==1 || (validarCodigoPaisEnCodigoBarras!=0));

			if(strlen(nuevo->codigoBarras)==0)
			{
				printf("\nSe cancela la carga del producto\n");
				salida=0;
			}
			else
			{
				printf("Ingrese descripcion del producto %s (Vacio=Salir): ", nuevo->codigoBarras);
				fgets(nuevo->descripcion, DESCRIPCIONPRODUCTO, stdin);
				eliminarRetornoCadena(nuevo->descripcion);
				if(strlen(nuevo->descripcion)==0)
				{
					printf("\nSe cancela la carga del producto\n");
					salida=0;
				}
				else
				{
					do
					{
						printf("Ingrese cantidad: ");
						scanf("%d", &nuevo->cantidad);
						if(nuevo->cantidad<0)
							printf("La cantidad no puede ser menor a 0\n");
					}while(nuevo->cantidad<0);
					
					do
					{
						cargaFecha(&nuevo->fechaActualizacion);
						if((validarFechaGregoriana(&nuevo->fechaActualizacion))==0)
							printf("\nLa fecha no es gregoriana\n");
						if(verificarFechaConFechaActual(&fechaActual, &(nuevo)->fechaActualizacion)==0)
							printf("La fecha cargada es mayor a la fecha actual, cargue nuevamente\n");
					}while(((validarFechaGregoriana(&nuevo->fechaActualizacion))!=1) || 
						(verificarFechaConFechaActual(&fechaActual, &(nuevo->fechaActualizacion))==0)); 
					
					do
					{
						printf("Ingrese el precio: ");
						scanf("%f", &nuevo->precio);
						if(nuevo->precio<0.00)
							printf("El precio no puede ser menor a $0\n");
					}while(nuevo->precio<0.00);
					printf("Ingrese el nombre de la foto: ");
					fflush(stdin);
					fgets(nuevo->nombreArchivo, NOMBREARCHIVO, stdin);
					eliminarRetornoCadena(nuevo->nombreArchivo);
					if(pDada->inicio==NULL)
					{
						pDada->inicio=nuevo;
						nuevo->siguiente=NULL;
						nuevo->anterior=NULL;
					}
					else
					{
						nuevo->anterior=NULL;
						nuevo->siguiente=pDada->inicio;
						actual=pDada->inicio;
						actual->anterior=nuevo;
						pDada->inicio=nuevo;
					}
					nuevo=(nodo*)malloc(sizeof(nodo));
					printf("\nDesea seguir cargando datos:");
					salir(&salida);
				}
			}
	}
}

/* FUNCION IMPRIMIR UN REGISTRO DE UN PRODUCTO */
/* RECIBE EL REGISTRO DEL PRODUCTO Y LA POSICION DONDE SE ENCUENTRA DICHO REGISTRO EN EL VECTOR PRODUCTO PARA IMPRIMIRLO EN PANTALLA*/
void imprimirProducto(pNodo n)
{
	//printf("\n%2d.\tProducto: ", posicion);
	fputs(n->descripcion, stdout);
	printf("\tCodigo de barras: ");
	fputs(n->codigoBarras, stdout);
	printf("\tStock actual: %d\n", n->cantidad);
	printf("\tPrecio: $%.2f\n", n->precio);
	printf("\tFecha de actualizacion: ");
	//imprimirFecha(&n->fechaActualizacion);
}

/* FUNCION UTILIZADA PARA LA CARGA DE FECHA DESDE TECLADO */
/* RECIBE COMO PARAMETRO UN PUNTERO DE ESTRUCTURA DE TIPO SFECHA PARA SU CARGA */
void cargaFecha(sfecha *fecha)
{
	do
	{
		printf("Ingrese la fecha (dd/mm/aaaa): ");
		scanf("%d/%d/%d", &(fecha)->dia, &(fecha)->mes, &(fecha)->anio);
		if(fecha->dia<0 || fecha->dia>31 ||
			fecha->mes<0 || fecha->mes>12 ||
			fecha->anio<1900 || fecha->anio>2100)
			printf("Fecha incorrecta, ingrese nuevamente\n");
	}while(fecha->dia<0 || fecha->dia>31 ||
		   fecha->mes<0 || fecha->mes>12 ||
		   fecha->anio<1900 || fecha->anio>2100);
	
}

/* FUNCION UTILIZADA PARA CONFIRMAR SI SE DESEA SEGUIR CON UNA TAREA O ABANDONAR */
/* COMO PARAMETRO RECIBE UN PUNTERO DE TIPO ENTERO PARA SELECCIONAR LA OPCION 1 = SEGUIR, 0 = SALIR */
void salir(int *s)
{
	do{
		printf("\n1. Seguir\n0. SALIR\n");
		scanf("%d", s);
		if(*s<0 || *s>1)
			printf("Opcion incorrecta\n");
	}while(*s<0 || *s>1);
}

/* IMPRIME UNA FECHA EN FORMATO FECHA */
/* COMO DATO DE ENTRADA RECIBE UN PUNTERO A FECHA PARA ACCEDER A SU CONTENIDO */
void imprimirFecha(sfecha fecha)
{
	printf("%.2d/%.2d/%.4d", fecha.dia, fecha.mes, fecha.anio);
}

/* FUNCION COPIAR FECHAS */
/* RECIBE UNA ESTRUCTURA DE FECHA DE ORIGEN Y UNA DE DESTINO, PARA REALIZAR LA COPIA ENTRE AMBAS */
void copiarFechas(sfecha *destino, sfecha *origen)
{
	destino->dia=origen->dia;
	destino->mes=origen->mes;
	destino->anio=origen->anio;
}

/* FUNCION PARA ORDENAR UNA LISTA A TRAVES DEL CODIGO DE PRODUCTO DE FORMA CRECIENTE A TRAVES DEL METODO DE BURBUJEO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS ACTIVOS EN EL VECTOR */
/*void ordenarListaEnlazada(lista *pLista)
{
	int totalNodos=0;
	nodo *actual=pLista->inicio, *siguiente;
	if(actual!=NULL)
	{
		if(actual->siguiente!=NULL)
		{
			while(actual!=NULL)
			{
				totalNodos++;
				actual=actual->siguiente;
			}
			actual=pLista->inicio;
			siguiente=actual->siguiente;






}

/* IMPRIME LISTA DE PRODUCTOS */
/* RECIBE EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE REGISTROS ACTIVOS */
void imprimirLista(lista pLista)
{
	nodo *actual;

	if(pLista.inicio==NULL)
		printf("\nNo hay productos en la lista\n");
	else
	{
		actual=pLista.inicio;
		while(actual!=NULL)
			imprimirProducto(actual);
	}
}

/* FUNCION PARA MODIFICAR UN PRODUCTO ACTIVO VERIFICANDO PREVIAMENTE SI EL PRODUCTO EXISTE A TRAVES DE SU CODIGO DE BARRAS */
/* RECIBE COMO PARAMETROS EL VECTOR DE ESTRUCTURAS DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS ACTIVOS EN DICHO VECTOR */
void modificarProducto(nodo *actual)
{
	
	printf("Ingrese descripcion del producto %s para modificar(Vacio=Salir): ");
			fgets(actual->descripcion, DESCRIPCIONPRODUCTO, stdin);
			if(strlen(actual->descripcion)-1==0)
				printf("Se cancela la modificacion del producto\n");
			else
			{
				fflush(stdin);
				printf("Ingrese el nombre de la foto: ");
				fgets(actual->nombreArchivo, NOMBREARCHIVO, stdin);
			}
}

/* FUNCION UTILIZADA PARA BUSCAR UN PRODUCTO EN LA LISTA DE ESTRUCTURAS DE PRODUCTOS 
   RECIBE COMO PARAMETRO LA LISTA DE NODOS DE PRODUCTOS Y DEVUELVE LA DIRECCION DEL PUNTERO DE TIPO NODO DEL PRODUCTO EN LA LISTA 
   EN CASO DE NO ENCONTRARLO, DEVUELVE NULL */
pNodo buscarProducto(lista p)
{
	nodo *actual=p.inicio;
	char codigoBuscado[CODIGOBARRAS];

	fflush(stdin);
	printf("Ingrese el codigo de barras del producto que busca: ");
	fgets(codigoBuscado, CODIGOBARRAS, stdin);
	eliminarRetornoCadena(codigoBuscado);
	while(actual!=NULL)
	{
		if((strcmp(actual->codigoBarras, codigoBuscado))==0)
			return actual;
		actual=actual->siguiente;
	}
	return NULL;														// Si no encuentra el codigo buscado, devuelve NULL
}

/* FUNCION PARA ACTUALIZAR LAS EXISTENCIAS DE UN PRODUCTO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS ACTIVOS */
void actualizarExistencia(lista pLista)
{
	nodo *modificar;
	int cantidad;
	sfecha fechaActual;

	fflush(stdin);
	modificar=buscarProducto(pLista);
	if(modificar==NULL)
		printf("Producto no encontrado\n");
	else
	{
		printf("Ingrese cantidad a sumar/restar(Para decrementar use valor negativo Ej: -10): ");
		scanf("%d", &cantidad);
		modificar->cantidad += cantidad;
		do
		{
			printf("Ingrese el precio: ");
			scanf("%f", &modificar->precio);
			if(modificar->precio<0.00)
				printf("El precio no puede ser menor a $0");
		}while(modificar->precio<0.00);

		obtenerFechaActual(&fechaActual);
		/*do
		{
			cargaFecha(&l[posicion].fechaActualizacion);
			if((validarFechaGregoriana(&l[posicion].fechaActualizacion))==0)
				printf("\nLa fecha no es gregoriana\n");
			if((verificarFechaConFechaActual(&fechaActual, &(l[posicion]).fechaActualizacion))==0)
				printf("La fecha cargada es mayor a la fecha actual, cargue nuevamente\n");
		}while(((validarFechaGregoriana(&l[posicion].fechaActualizacion))!=1) || 
			(verificarFechaConFechaActual(&fechaActual, &(l[posicion]).fechaActualizacion))==0); */
	}
}

/* FUNCIONA QUE SE UTILIZA PARA VALIDAR SI EL CODIGO DE BARRAS CONTIENE SOLO DIGITOS O CARACTERES */
/* RECIBE COMO PARAMENTRO UN VECTOR DE CHAR Y DEVUELVE 0 SI ES INV�LIDO EL CODIGO DE BARRAS O 1 SI ES V�LIDO */
int validarCodigo(char cod[CODIGOBARRAS])
{
	int i, longitud=strlen(cod)-1, validar=1;

	for(i=0; i<longitud; i++)
	{
		if((isalnum(cod[i]))==0)
			return validar-1;
	}
	return validar;
}

/* FUNCION PARA DAR DE BAJA A UN PRODUCTO DEL VECTOR DE PRODUCTOS */
/* RECIBE COMO PARAMETROS EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS EXISTENTES HASTA EL MOMENTO */
/* DEVUELVE, EN CASO DE DARSE DE BAJA UN PRODUCTO, LA CANTIDAD DECREMENTADA EN UNA UNIDAD */
void bajaProducto(lista pLista)
{	
	nodo *eliminar, *atras, *adelante;

	fflush(stdin);
	eliminar=buscarProducto(pLista);
	if(eliminar==NULL)
		printf("El producto no se encuentra\n");
	else
	{
		if(eliminar->cantidad!=0)
			printf("El producto no se puede eliminar ya que su stock>0");
		else
		{
			atras=eliminar->anterior;
			adelante=eliminar->siguiente;
			atras->siguiente=adelante;
			adelante->anterior=atras;
			free(eliminar);
		}
	}
}

/* FUNCION PARA IMPRIMIR TODO EL STOCK DE PRODUCTOS */
/* RECIBE COMO PARAMETROS EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS DADOS DE ALTA PARA IMPRIMIRLOS EN PANTALLA */
void imprimirDatosEncolumnados(lista pLista)
{
	nodo *actual=pLista.inicio;
	if(actual==NULL)
		printf("\nLa lista esta vacia\n");
	else
	{
		printf("\n%-*s%-*sFecha\t\tPrecio\tCantidad\n", 15, "Codigo", 15, "Nombre");
		while(actual!=NULL)
		{
			printf("%-*s", 15, actual->codigoBarras);
			printf("%-*s", 15, actual->descripcion);
			imprimirFecha(actual->fechaActualizacion);
			printf("\t%.2f", actual->precio);
			printf("\t%d\n", actual->cantidad);
			actual=actual->siguiente;
		}
	}
}

/* FUNCION VALIDA PARA IMPRIMIR UNA CADENA SIN EL RETORNO DE LINEA */
/* RECIBE COMO PARAMETRO UNA CADENA PARA IMPRIMIRLA EN PANTALLA */
void eliminarRetornoCadena(char cad[])
{
	int longitud=strlen(cad)-1;
	cad[longitud]='\0';
}

/* FUNCION PARA BUSCAR EL CODIGO DE BARRAS DE UN PRODUCTO DENTRO DEL VECTOR DE PRODUCTOS */
/* SI ENCUENTRA EL MISMO CODIGO DEVUELVE 1, CASO CONTRARIO, DEVUELVE 0*/
int buscarCodigoBarras(lista pLista, char cod[CODIGOBARRAS])
{
	nodo *buscar=pLista.inicio;

	while(buscar!=NULL)
	{
		if((strcmp(buscar->codigoBarras, cod))==0)
			return 1;
		else
			buscar=buscar->siguiente;
	}
	return 0;
}

/* FUNCION PARA GUARDAR LOS DATOS CARGADOS DE PRODUCTOS EN ARCHIVO BINARIO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS CARGADOS EN MEMORIA PARA SU GUARDADO EN EL ARCHIVO */
void guardarDatosArchivo(lista pNodo)
{
	FILE *pf;
	nodo *actual=pNodo.inicio;

	pf=fopen("Stock.dat", "wb");
	if(pf==NULL)
		printf("Error al abrir el archivo, se cancela la carga\n");
	else
	{
		while(actual!=NULL)
		{
			fwrite(&actual, sizeof(nodo), 1, pf);
			actual->siguiente;
		}
		printf("\nArchivo guardado con exito!\n");
	}
	fclose(pf);
}

/* FUNCION UTILIZADA PARA CARGAR LA INFORMACION DEL STOCK DESDE ARCHIVO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS PARA SU CARGA Y DEVUELVE LA FUNCION LA CANTIDAD DE PRODUCTOS CARGADOS */
/*int cargarDatosArchivo(sproducto l[])
{
	int cant, i;
	FILE *pf;

	pf=fopen("Stock.dat", "rb");
	if(pf==NULL)
	{
		printf("Error al cargar el archivo de stock\n");
		cant=0;
	}
	else
	{
		fread(&cant, sizeof(cant), 1, pf);
		for(i=0; i<cant; i++)
			fread(&l[i], sizeof(sproducto), 1, pf);
		printf("\nArchivo cargado con exito!\n");
	}
	return cant;
}

/* FUNCION PARA VALIDAR SI UN A�O ES BISIESTO */
/* RECIBE COMO PARAMETRO UN ENTERO Y DEVUELVE 1 SI ES BISIESTO o 0 SINO LO ES */
int validad_bisiesto(int a)
{
	int resto=0;										//Si resto = 0 -> NO ES BISIESTO
														//Si resto = 1 -> ES BISIESTO
	resto=a%4;
	if(resto==0)
	{
		resto=a%100;
		if(resto!=0)
			return 1;
	}
	resto=a%400;
	if(resto==0)
		return 1;
	return 0;
}

/* FUNCION PARA VALIDAR SI UNA FECHA ES GREGORIANA */
/* RECIBE COMO PARAMETRO UNA ESTRUCTURA DEL TIPO SFECHA */
/* DEVUELVE 1 SI ES UNA FECHA GREGORIANA VALIDA o 0 SI ES INVALIDA */
int validarFechaGregoriana(sfecha *f)
{
	int resultado=0, bisiesto;									// RESULTADO = 1 -> VALIDO
																// RESULTADO = 0 -> INVALIDO
	bisiesto=validad_bisiesto(f->anio);

	if(bisiesto==1 && (f->dia)<=29)
		resultado=1;
	else{
		if(bisiesto==0 && (f->dia)<=28)
			resultado=1;
	}
	if(((f->mes==1) || (f->mes==3) || (f->mes==5) || (f->mes==7) || (f->mes==8) || (f->mes==10) || (f->mes==12)) && (f->dia<=31))
		resultado=1;
	if(((f->mes==4) || (f->mes==6) || (f->mes==9) || (f->mes==11)) && (f->dia<=30))
		resultado=1;
	return resultado;
}

/* FUNCION UTILIZADA PARA OBTENER LA FECHA ACTUAL DEL SISTEMA */
/* RECIBE COMO PARAMETRO UN PUNTERO DEL TIPO SFECHA PARA CARGAR LOS DATOS DE LA FECHA ACTUAL DEL SISTEMA */
void obtenerFechaActual(sfecha *fActual)
{
	time_t x;
    struct tm* fechaActual;
	
	time(&x);
	fechaActual=localtime(&x);
	fActual->anio = fechaActual->tm_year + 1900;
	fActual->mes = fechaActual->tm_mon + 1;
	fActual->dia = fechaActual->tm_mday;
}

/* FUNCION PARA VERIFICAR SI UNA FECHA ES POSTERIOR A LA FECHA ACTUAL, EN CASO DE QUE SEA AFIRMATIVO SE DEVUELVE UN 0, SINO SE DEVUELVE UN 1 */
/* RECIBE COMO PARAMETRO 2 PUNTEROS DE TIPO SFECHA, UNO DEBE SER LA FECHA ACTUAL Y EL OTRO LA FECHA A COMPARAR */
int verificarFechaConFechaActual(sfecha *fActual, sfecha *fecha)
{
	if ((fActual->anio == fecha->anio) && (fActual->mes == fecha->mes) && (fActual->dia == fecha->dia))
		return 1;
	else
	{
		if(fActual->anio<fecha->anio)
			return 0;
		if((fActual->anio == fecha->anio) && (fActual->mes<fecha->mes))
			return 0;
		if((fActual->anio == fecha->anio) && (fActual->mes == fecha->mes) && (fActual->dia< fecha->dia))
			return 0;
	}
	return 1;
}

/*FUNCION PARA CREAR EL ARCHIVO DE TEXTO CON LOS CODIGOS Y NOMBRES DE LOS PAISES
  NO RECIBE NINGUN PARAMETRO Y GENERA EN EL DIRECTORIO DONDE SE ENCUENTRA EL EJECUTABLE EL ARCHIVO DE TEXTO CON LOS CODIGOS Y LOS NOMBRES DE LOS PAISES*/
void crearArchivoCodigoPaises()
{
	FILE *codigoPaises;
	char codigoPais[CODIGOPAIS];
	
	codigoPaises=fopen("CodigoPaises.txt", "at");
	if(codigoPaises==NULL)
		printf("\nEror al crear el archivo en disco\n");
	else
	{
		printf("\nIngrese codigo de pais y presione ENTER\nSeparado ingrese el nombre del pais\nEjemplo: COD NOMBRE\nPara finalizar ingrese el codigo vacio:\n\n");
		fflush(stdin);
		fgets(codigoPais, CODIGOPAIS, stdin);
		while((strlen(codigoPais))!=1)
		{
			fprintf(codigoPaises, "%s", codigoPais);
			fflush(stdin);
			fgets(codigoPais, CODIGOPAIS, stdin);
		}
	}
	fprintf(codigoPaises, "\n");
	fclose(codigoPaises);
}

void inicializarListaPaises(listaPaises *pLista)
{
	pLista->inicio=NULL;
}

void cargarArchivoCodigoPaises(listaPaises *pList)
{
	FILE *archivoPaises;
	pais *nuevo, *actual;
	char codPais[CODIGOPAIS], finLinea;

	archivoPaises=fopen("CodigoPaises.txt", "rt");
	if(archivoPaises==NULL)
		printf("\nEror al crear el archivo en disco\n");
	else
	{
		nuevo=(pais*)malloc(sizeof(pais));
		if(nuevo==NULL)
			printf("\nNo hay memoria disponible en el sistema\n");
		
		fgets(codPais, CODIGOPAIS, archivoPaises);
		while(!feof(archivoPaises))
		{
			finLinea='0';
			while(finLinea!='\n')
			{
				finLinea=fgetc(archivoPaises);
			}
			strcpy(nuevo->cod, codPais);
			actual=pList->inicio;
			pList->inicio=nuevo;
			nuevo->siguiente=actual;
			nuevo=(pais*)malloc(sizeof(pais));
			if(nuevo==NULL)
				printf("\nNo hay memoria disponible en el sistema\n");
			fgets(codPais, CODIGOPAIS, archivoPaises);
		}
	}
	fclose(archivoPaises);
	strcpy(codPais, "abc");
}

void verListaCodigoPaises(listaPaises pList){
	FILE *pr;
	pais *imprimir=pList.inicio;

	pr=fopen("aux.txt", "wt");
	if(pList.inicio==NULL)
		printf("\nLa lista de codigo de paises esta vacia\n");
	else
	{
		while(imprimir!=NULL)
		{
			printf("%s\n", imprimir->cod);
			imprimir=imprimir->siguiente;
		}
	}
	fclose(pr);
}

int validarCodigoPaisEnCodigoBarras(char codigoBarras[CODIGOBARRAS], listaPaises pList)
{
	pais *actual=pList.inicio;
	char codigoPais[3], codigoNodo[3];

	codigoPais[0]=codigoBarras[0];
	codigoPais[1]=codigoBarras[1];
	codigoPais[2]=codigoBarras[2];
	//codigoPais[3]='\0';
	//eliminarRetornoCadena(codigoPais);
	while(actual!=NULL)
	{
		strcpy(codigoNodo, actual->cod);
		if(strcmp(codigoPais, codigoNodo)==0)
			return 1;
		actual=actual->siguiente;
	}
	strcpy(codigoPais, "123");
	strcpy(codigoNodo, "123");
	return 0;
}