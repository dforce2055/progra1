// Librería fechas.c modificada para el pryecto Tecnisa
/* Para funcionar, esta librería necesita la siguiente estructura:

struct _fecha {
       char dia:5;
       char mes:4;
       int any;
       };
       
*/

int bisiesto(int any)
{
    // Finalidad: Calcula si un año es bisiesto
    // Argumentos: Se le pasará un año (int). No será necesario enviarle una fecha entera
    // Devuelve: 1 si es bisiesto, 0 si no lo es
    
    if (any%400 == 0 || (any%4==0 && any%100!=0))
       return 1;
    else
       return 0;
}
    
int dias_mes(struct _fecha fecha)
{
    // Finalidad: Calcula los días de un mes
    // Argumentos: Se le pasará una fecha (struct _fecha).
    // Devuelve: Los días del mes de la fecha pasada (int).
    
    switch (fecha.mes)
    {
           case 1: case 3: case 5:
           case 7: case 8: case 10:
           case 12:
                return 31;
                break;
           
           case 4: case 6:
           case 9: case 11:
                return 30;
                break;
                
           case 2:
                if (bisiesto(fecha.any))
                   return 29;
                else
                   return 28;
    }
}

int validarFecha(struct _fecha fecha)
{
    // Finalidad: Determina si la fecha pasada existe
    // Argumentos: Se le pasará una fecha (struct _fecha).
    // Devuelve: 1 si la fecha es válida, 0 si no lo es.

    if (fecha.mes>0 && fecha.mes<=12)
    {
              if (fecha.dia>0 && fecha.dia<=dias_mes(fecha))
                 return 1;
              else
                 return 0;
    }
    else
        return 0;
}

int cuenta_dias(struct _fecha fecha1, struct _fecha fecha2)
{
    // Finalidad: Calcular los días que hay entre dos fechas.
    // Argumentos: Se le pasará dos fechas (struct _fecha).
    // Devuelve: La distancia en días entre las dos fechas (int)
    // Nota: fecha1 deberá ser anterior a fecha2
    
    int acum=0, sw=0;
    
    while (1)
    {
          if (fecha1.any == fecha2.any && fecha1.mes == fecha2.mes)
             break;
             
          acum=acum+(dias_mes(fecha1)-fecha1.dia);
          
          if(fecha1.mes==12)
          {
              fecha1.mes=1;
              fecha1.any++;
          }
          else
              fecha1.mes++;
          
          fecha1.dia=0;     
    }
    acum=acum+(fecha2.dia-fecha1.dia);
    return acum;
}

struct _fecha sumarDias(struct _fecha fecha, int x)
{
     // Finalidad: Suma a una fecha inicial una cantidad de días.
     // Argumentos: Una fecha (struct _fecha) y una cantidad de días (int).
     // Devuelve: La fecha final con los días sumados (struct _fecha).
     
     for(;x>0;x--)
     { 
          if(fecha.dia<dias_mes(fecha) )
              fecha.dia++;
          else
          {
              if (fecha.mes==12)
              {
                  fecha.mes=1;
                  fecha.any++;
              }
              else fecha.mes++;
              fecha.dia=1;
          }
     }
     return fecha;
}                             

struct _fecha restarDias(struct _fecha fecha, int x)
{
     // Finalidad: Resta a una fecha inicial una cantidad de días.
     // Argumentos: Una fecha (struct _fecha) y una cantidad de días (int).
     // Devuelve: La fecha final con los días restados (struct _fecha).
     for(;x>0;x--)
     { 
          if(fecha.dia>1)
              fecha.dia--;
          else
          {
              if (fecha.mes==1)
              {
                  fecha.mes=12;
                  fecha.any--;
              }
              else fecha.mes--;
              fecha.dia = dias_mes(fecha);
          }
     }
     return fecha;
} 

int dia_semana(struct _fecha fecha2)
{
     // Finalidad: Halla el día de la semana de una fecha (lunes, martes...)
     // Argumentos: Una fecha (struct _fecha).
     // Devuelve: 1 para lunes, 2 para martes...
     
     struct _fecha fecha1 = {14, 9, 1752};
          switch(cuenta_dias(fecha1, fecha2)%7)
          {
               case 3: return 7; // Domingo
               case 4: return 1; // Lunes
               case 5: return 2; // Martes    
               case 6: return 3; // Miércoles
               case 0: return 4; // Jueves
               case 1: return 5; // Viernes
               case 2: return 6; // Sábado
          }
}

int compararFechas(struct _fecha fecha1, struct _fecha fecha2)
{
    // Finalidad: Compara dos fechas y comprueba cuál es anterior a la otra
    // Argumentos: Dos fechas (struct _fecha).
    // Devuelve: 0 si ambas son iguales, 1 si fecha1 es anterior a fecha2, -1 si fecha1 es posterior a fecha2
     if (fecha1.any == fecha2.any)
     {
         if (fecha1.mes == fecha2.mes)
         {
             if (fecha1.dia == fecha2.dia) return 0;
             else
             {
                 if (fecha1.dia > fecha2.dia) return -1;
                 else       return  1;
             }
         }
         else
         {
             if(fecha1.mes > fecha2.mes) return -1;
             else      return 1;
         }
     }
     else
     {
         if (fecha1.any > fecha2.any) return -1;
         else       return  1;
     }
}

    
struct _fecha domingo_pascua(int any)
{
     // Finalidad: Calcula el Domingo de Pascua de un determinado año
     // Argumentos: Se le pasa un año (int). No es necesario pasarle una fecha entera
     // Devuelve: la fecha entera del Domingo de Pascua
     
      struct _fecha fecha;
      int a, b, c, d, e, n;

      a = any % 19;
      b = any % 4;
      c = any % 7;
      d = (19 * a + 24) % 30;
      e = (2*b + 4*c + 6*d + 5) % 7;
      n = 22 + d + e;
      
      if (n <= 31)
      {
         fecha.dia = n;
         fecha.mes = 3;
      }
      else
      {
         fecha.dia = n - 31;
         fecha.mes = 4;
      }
      return fecha;     
}