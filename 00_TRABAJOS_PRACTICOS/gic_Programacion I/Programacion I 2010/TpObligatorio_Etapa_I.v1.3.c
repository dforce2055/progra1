/* PROGRAMA CORRESPONDIENTE A LA PRIMERA ETAPA DEL TP OBLIGATORIO DE PROGRAMACION I LOS DIAS LUNES DE 7.45 A 11.45 EN EL AULA 212

EL MISMO SE ENCARGA DE UN SISTEMA DE GESTION DE STOCK DE PRODUCTOS, CON SU CORRESPONDIENTE ABM, COMO ASI TAMBIEN LISTADO DE PRODUCTOS ACTIVOS, GUARDADO Y LECTURA DE DATOS EN ARCHIVO

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
#define MAX 100
#pragma warning (disable:4996)

/********* DECLARACION DE ESTRUCTURAS *********/
typedef struct{
	int dia, mes, anio;
}sfecha;

typedef struct{
	char codigoBarras[CODIGOBARRAS];
	char descripcion[DESCRIPCIONPRODUCTO];
	sfecha fechaActualizacion;
	float precio;
	int cantidad;
	char nombreArchivo[NOMBREARCHIVO];
}sproducto;

/********* DECLARACION DE ENCABEZADOS DE FUNCIONES *********/
void actualizarExistencia(sproducto l[], int cant);
int altaProducto(sproducto l[], int cant);
int bajaProducto(sproducto l[], int cant);
int buscarCodigoBarras(sproducto l[], char cod[CODIGOBARRAS], int cant);
int buscarProducto(sproducto l[], int cant);
int cargarDatosArchivo(sproducto l[]);
void cargaFecha(sfecha *fecha);
void copiarFechas(sfecha *destino, sfecha *origen);
void guardarDatosArchivo(sproducto l[], int cant);
void imprimirCadenaSinRetorno(char cad[NOMBREARCHIVO]);
void imprimirDatosEncolumnados(sproducto l[], int cant);
void imprimirFecha(sfecha *fecha);
void imprimirLista(sproducto l[], int cant);
void imprimirProducto(sproducto l[], int cant);
void menu(int *opc);
void modificarProducto(sproducto l[], int posicion);
void obtenerFeechaActual(sfecha *fActual);
void ordenarLista(sproducto l[], int cant);
void salir(int *s);
int validad_bisiesto(int a);
int validadCodigo(char cod[CODIGOBARRAS]);
int validarFechaGregoriana(sfecha *f);
int verificarFechaConFechaActual(sfecha *fActual, sfecha *fecha);

/******** FUNCION PRINCIPAL *********/
int main(void){
	sproducto stock[MAX];
	int opcion=0, cantidad=0;

	do
	{
		menu(&opcion);
		if(opcion!=0){
			cantidad=cargarDatosArchivo(stock);
			switch(opcion)
			{
			case 1:
				cantidad=altaProducto(stock, cantidad);
				break;
			case 2:
				modificarProducto(stock, buscarProducto(stock, cantidad));
				break;
			case 3:
				cantidad=bajaProducto(stock, cantidad);
				break;
			case 4:
				actualizarExistencia(stock, cantidad);
				break;
			case 5:
				if(cantidad!=0){
					ordenarLista(stock, cantidad);
					imprimirDatosEncolumnados(stock, cantidad);
				}
				else
					printf("\nNo hay datos cargados!\n");
				break;
			}
		}
	}while(opcion!=0);
	guardarDatosArchivo(stock, cantidad);
	return 0;
}

/* FUNCION ALTA DE PRODUCTO, VALIDANDO SUS CAMPOS DE FORMA CORRECTA */
/* COMO DATO DE ENTRADA RECIBE EL VECTOR DE ESTRUCTURA CON LA CANTIDAD DE REGISTROS QUE POSEE EL MISMO */
/* COMO SALIDA, EN CASO DE DARSE DE ALTA PRODUCTOS, SE DEVUELVE LA CANTIDAD INCREMENTADA POR DICHO PRODUCTOS NUEVOS */
int altaProducto(sproducto l[], int cant)
{
	int i=cant, salida=1;
	sfecha fechaActual;

	obtenerFeechaActual(&fechaActual);

	while((i<MAX) && (salida==1))
	{
		do
		{
			fflush(stdin);
			printf("\nIngrese codigo de barras (Vacio=Salir): ");
			fgets(l[i].codigoBarras, CODIGOBARRAS, stdin);

			if((validadCodigo(l[i].codigoBarras))!=1)
				printf("El codigo de barras no es alfanumerico\n");
			if((buscarCodigoBarras(l, l[i].codigoBarras, cant))==1)
				printf("El codigo del producto esta repetido\n");
		}while(((validadCodigo(l[i].codigoBarras))!=1) || (buscarCodigoBarras(l, l[i].codigoBarras, cant))==1);

		if(strlen(l[i].codigoBarras)-1==0)
		{
			printf("Se cancela la carga del producto\n");
			return cant;
		}

		else
		{
			printf("Ingrese descripcion del producto %s (Vacio=Salir): ", l[i].codigoBarras);
			fgets(l[i].descripcion, DESCRIPCIONPRODUCTO, stdin);
			if(strlen(l[i].descripcion)-1==0)
			{
				printf("Se cancela la carga del producto\n");
				return cant;
			}
			else
			{
				do
				{
					printf("Ingrese cantidad: ");
					scanf("%d", &l[i].cantidad);
					if(l[i].cantidad<0)
						printf("La cantidad no puede ser menor a 0\n");
				}while(l[i].cantidad<0);
				
				do
				{
					cargaFecha(&l[i].fechaActualizacion);
					if((validarFechaGregoriana(&l[i].fechaActualizacion))==0)
						printf("\nLa fecha no es gregoriana\n");
					if((verificarFechaConFechaActual(&fechaActual, &(l[i]).fechaActualizacion))==0)
						printf("La fecha cargada es mayor a la fecha actual, cargue nuevamente\n");
				}while(((validarFechaGregoriana(&l[i].fechaActualizacion))!=1) || 
					(verificarFechaConFechaActual(&fechaActual, &(l[i]).fechaActualizacion))==0); 

				do
				{
					printf("Ingrese el precio: ");
					scanf("%f", &l[i].precio);
					if(l[i].precio<0.00)
						printf("El precio no puede ser menor a $0");
				}while(l[i].precio<0.00);

				printf("Ingrese el nombre de la foto: ");
				fflush(stdin);
				fgets(l[i].nombreArchivo, NOMBREARCHIVO, stdin);
				cant++;
				i++;
				printf("\nDesea seguir cargando datos: ");
				salir(&salida);
			}
		}
	}
	return cant;
}

/* FUNCION IMPRIMIR UN REGISTRO DE UN PRODUCTO */
/* RECIBE EL REGISTRO DEL PRODUCTO Y LA POSICION DONDE SE ENCUENTRA DICHO REGISTRO EN EL VECTOR PRODUCTO PARA IMPRIMIRLO EN PANTALLA*/
void imprimirProducto(sproducto l[], int posicion)
{
	printf("\n%2d.\tProducto: ", posicion);
	fputs(l[posicion].descripcion, stdout);
	printf("\tCodigo de barras: ");
	fputs(l[posicion].codigoBarras, stdout);
	printf("\tStock actual: %d\n", l[posicion].cantidad);
	printf("\tPrecio: $%.2f\n", l[posicion].precio);
	printf("\tFecha de actualizacion: ");
	imprimirFecha(&(l[posicion]).fechaActualizacion);
	printf("\tNombre de archivo de foto: ");
	fputs(l[posicion].nombreArchivo, stdout);
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
		printf("6. Guardar informacion en archivo\n");
		printf("7. Cargar informacion de archivo\n");
		printf("Ingrese la opcion a realizar: ");
		scanf("%d", opc);
	}while(*opc<0 || *opc>7);
}

/* FUNCION UTILIZADA PARA LA CARGA DE FECHA DESDE TECLADO */
/* RECIBE COMO PARAMETRO UN PUNTERO DE ESTRUCTURA DE TIPO SFECHA PARA SU CARGA */
void cargaFecha(sfecha *fecha)
{
	do
	{
		printf("Ingrese fecha");
		printf("Dia: ");
		scanf("%d", &(fecha)->dia);
		printf("Mes: ");
		scanf("%d", &(fecha)->mes);
		printf("Anio: ");
		scanf("%d", &(fecha)->anio);
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
void imprimirFecha(sfecha *fecha)
{
	printf("%.2d/%.2d/%.4d", fecha->dia, fecha->mes, fecha->anio);
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
void ordenarLista(sproducto l[], int cant)
{
	int total=cant, i, k;
	sproducto aux;

	for(k=0; k<total-1; k++)
	{
		for(i=0; i<total-1; i++){
			if((strcmp(l[i].codigoBarras, l[i+1].codigoBarras))>0){
				aux=l[i];
				l[i]=l[i+1];
				l[i+1]=aux;
			}
		}
	}
}

/* IMPRIME LISTA DE PRODUCTOS */
/* RECIBE EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE REGISTROS ACTIVOS */
void imprimirLista(sproducto l[], int cant)
{
	int i;
	if(cant==0)
		printf("\nNo hay productos en la lista\n");
	else
	{
		for(i=0; i<cant; i++)
			imprimirProducto(l, i);
	}
}

/* FUNCION PARA MODIFICAR UN PRODUCTO ACTIVO VERIFICANDO PREVIAMENTE SI EL PRODUCTO EXISTE A TRAVES DE SU CODIGO DE BARRAS */
/* RECIBE COMO PARAMETROS EL VECTOR DE ESTRUCTURAS DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS ACTIVOS EN DICHO VECTOR */
void modificarProducto(sproducto l[], int posicion)
{
	printf("Ingrese descripcion del producto %s para modificar(Vacio=Salir): ", l[posicion].codigoBarras);
			fgets(l[posicion].descripcion, DESCRIPCIONPRODUCTO, stdin);
			if(strlen(l[posicion].descripcion)-1==0)
				printf("Se cancela la modificacion del producto\n");
			else
			{
				fflush(stdin);
				printf("Ingrese el nombre de la foto: ");
				fgets(l[posicion].nombreArchivo, NOMBREARCHIVO, stdin);
			}
}

/* FUNCION UTILIZADA PARA BUSCAR UN PRODUCTO EN EL VECTOR DE ESTRUCTURAS DE PRODUCTOS */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y EL TOTAL DE PRODUCTOS CARGADOS Y DEVUELVE LA POSICION DEL PRODUCTO EN EL VECTOR 
EN CASO DE NO ENCONTRARLO, DEVUELVE -1 */
int buscarProducto(sproducto l[], int cant)
{
	char codigoBuscado[CODIGOBARRAS];
	int i;

	fflush(stdin);
	printf("Ingrese el codigo de barras del producto que busca: ");
	fgets(codigoBuscado, CODIGOBARRAS, stdin);
	for(i=0; i<cant; i++)
	{
		if((strcmp(l[i].codigoBarras, codigoBuscado))==0)
			return i;
	}
	return -1;														// Si no encuentra el codigo buscado, devuelve -1
}

/* FUNCION PARA ACTUALIZAR LAS EXISTENCIAS DE UN PRODUCTO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS ACTIVOS */
void actualizarExistencia(sproducto l[], int cant)
{
	int posicion;
	sfecha fechaActual;

	fflush(stdin);
	posicion=buscarProducto(l, cant);
	if(posicion==-1)
		printf("Producto no encontrado\n");
	else
	{
		do
		{
		printf("Ingrese cantidad: ");
		scanf("%d", &l[posicion].cantidad);
		if(l[posicion].cantidad<0)
			printf("La cantidad no puede ser menor a 0\n");
		}while(l[posicion].cantidad<0);
		do
		{
			printf("Ingrese el precio: ");
			scanf("%f", &l[posicion].precio);
			if(l[posicion].precio<0.00)
				printf("El precio no puede ser menor a $0");
		}while(l[posicion].precio<0.00);

		obtenerFeechaActual(&fechaActual);
		cargaFecha(&l[posicion].fechaActualizacion);
		do
		{
			cargaFecha(&l[posicion].fechaActualizacion);
			if((validarFechaGregoriana(&l[posicion].fechaActualizacion))==0)
				printf("\nLa fecha no es gregoriana\n");
			if((verificarFechaConFechaActual(&fechaActual, &(l[posicion]).fechaActualizacion))==0)
				printf("La fecha cargada es mayor a la fecha actual, cargue nuevamente\n");
		}while(((validarFechaGregoriana(&l[posicion].fechaActualizacion))!=1) || 
			(verificarFechaConFechaActual(&fechaActual, &(l[posicion]).fechaActualizacion))==0); 
	}
}

/* FUNCIONA QUE SE UTILIZA PARA VALIDAR SI EL CODIGO DE BARRAS CONTIENE SOLO DIGITOS O CARACTERES */
/* RECIBE COMO PARAMENTRO UN VECTOR DE CHAR Y DEVUELVE 0 SI ES INVÀLIDO EL CODIGO DE BARRAS O 1 SI ES VÀLIDO */
int validadCodigo(char cod[CODIGOBARRAS])
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
int bajaProducto(sproducto l[], int cant){
	int posicion;
	
	fflush(stdin);
	posicion=buscarProducto(l, cant);
	if(posicion==-1)
		printf("El producto no se encuentra\n");
	else
	{
		if(l[posicion].cantidad!=0)
			printf("El producto no se puede eliminar ya que su stock>0");
		else
		{
			for(posicion; posicion<cant-1; posicion++)
				l[posicion]=l[posicion+1];
			cant--;
		}
	}
	return cant;
}

/* FUNCION PARA IMPRIMIR TODO EL STOCK DE PRODUCTOS */
/* RECIBE COMO PARAMETROS EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS DADOS DE ALTA PARA IMPRIMIRLOS EN PANTALLA */
void imprimirDatosEncolumnados(sproducto l[], int cant)
{
	int i;

	printf("\nCodigo\tNombre\tFecha\t\tPrecio\tCantidad\tNombre Archivo\n");
	for(i=0; i<cant; i++)
	{
		imprimirCadenaSinRetorno(l[i].codigoBarras);
		printf("%\ts\t", l[i].descripcion);
		imprimirFecha(&l[i].fechaActualizacion);
		printf("\t%.2f", l[i].precio);
		printf("\t%d", l[i].cantidad);
		printf("\t\t%s", l[i].nombreArchivo);
	}
}

/* FUNCION VALIDA PARA IMPRIMIR UNA CADENA SIN EL RETORNO DE LINEA */
/* RECIBE COMO PARAMETRO UNA CADENA PARA IMPRIMIRLA EN PANTALLA */
void imprimirCadenaSinRetorno(char cad[NOMBREARCHIVO])
{
	int i, longitud=strlen(cad)-1;

	for(i=0; i<longitud; i++)
		putc(cad[i], stdout);
}

/* FUNCION PARA BUSCAR EL CODIGO DE BARRAS DE UN PRODUCTO DENTRO DEL VECTOR DE PRODUCTOS */
/* SI ENCUENTRA EL MISMO CODIGO DEVUELVE 1, SINO DEVUELVE 0 */
int buscarCodigoBarras(sproducto l[], char cod[CODIGOBARRAS], int cant)
{
	int i;

	for(i=0; i<cant; i++)
	{
		if((strcmp(l[i].codigoBarras, cod))==0)
			return 1;
	}
	return 0;
}

/* FUNCION PARA GUARDAR LOS DATOS CARGADOS DE PRODUCTOS EN ARCHIVO BINARIO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS Y LA CANTIDAD DE PRODUCTOS CARGADOS EN MEMORIA PARA SU GUARDADO EN EL ARCHIVO */
void guardarDatosArchivo(sproducto l[], int cant)
{
	FILE *pf;
	int i;

	pf=fopen("Stock.dat", "wb");
	if(pf==NULL)
		printf("Error al abrir el archivo, se cancela la carga\n");
	else
	{
		fwrite(&cant, sizeof(cant), 1, pf);
		for(i=0; i<cant; i++)
			fwrite(&l[i], sizeof(sproducto), 1, pf);
		printf("\nArchivo guardado con exito!\n");
	}
	fclose(pf);
}

/* FUNCION UTILIZADA PARA CARGAR LA INFORMACION DEL STOCK DESDE ARCHIVO */
/* RECIBE COMO PARAMETRO EL VECTOR DE PRODUCTOS PARA SU CARGA Y DEVUELVE LA FUNCION LA CANTIDAD DE PRODUCTOS CARGADOS */
int cargarDatosArchivo(sproducto l[])
{
	int cant, i;
	FILE *pf;

	pf=fopen("Stock.dat", "rb");
	if(pf==NULL)
		printf("Error al cargar el archivo de stock\n");
	else
	{
		fread(&cant, sizeof(cant), 1, pf);
		for(i=0; i<cant; i++)
			fread(&l[i], sizeof(sproducto), 1, pf);
		printf("\nArchivo cargado con exito!\n");
	}
	return cant;
}

/* FUNCION PARA VALIDAR SI UN AÑO ES BISIESTO */
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
void obtenerFeechaActual(sfecha *fActual)
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