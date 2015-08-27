typedef struct
{
	int dia, mes, anio;
}sfecha;

typedef struct
{
	int segundo, minuto, hora;
}shora;

typedef struct
{
	char codBarras[21];
	char nombre[30];
	float precio;
	int stock;
	sfecha fechaActualizacion;
}sproducto;