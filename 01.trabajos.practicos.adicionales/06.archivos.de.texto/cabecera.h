#ifndef _01EJERCICIO_
typedef struct Alumno{
  char nombre[50];
  int nota1, nota2;
  float promedio;
}Alumno;

int grabarNotas(Alumno alumno);
int grabarPromedios(void);
float promedio(int nota1, int nota2);
int mostrarMejores(void);

#endif //_01EJERCICIO_
