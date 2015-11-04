Miercoles 11 de Noviembre de 2015
Temas: Asignación dinámica de memoria. Listas enlazadas simples.

          ->  Estaticas
Variables
          ->  Dinámicas
-----------------------------------------------
Área del montón    |  Variables Dinámicas     #
(Montículo HEAP)   |                          #
-----------------------------------------------
Área de la pila    |  Variables locales,      #
                   |  parámetros,             #
                   |  direcciones de retorno  #
-----------------------------------------------
Área de datos      |  Variables globales      #
globales           |                          #
-----------------------------------------------
Área de código     |  Programa y constantes   #
-----------------------------------------------

malloc = memory allocation
ptr = (int *) sizeof(int); //castear el valor devuelto por  malloc


Memory Leaks (Fugas de memoria)
===============================
ptr = malloc(sizeof(int)); //asigna dirección de memoria a ptr del tamaño de 1 int
ptr = malloc(sizeof(int));//asigna OTRA dirección de memoria a ptr, la zona de
                          //memoria anterior sigue ahí, pero no se puede utilizar

Listas Enlazadas
================
