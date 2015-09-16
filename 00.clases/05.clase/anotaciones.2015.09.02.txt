Miercoles 02 de Septiembre de 2015
Temas: Funciones de biblioteca para el manejo de caracteres y cadenas.
3 bibliotecas utilizadas generalmente

Biblioteca ctype.h:
==================
isalpha(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es alfabético (ingles)
isdigit(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es un digito númerico
isalnum(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es alfabético o numerico
isspace(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es un espacio o \t \n
isupper(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es un carácter alfabético en Mayúscula
islower(<char>)?1:0; //verdadero | falso | devuelve verdadero cuando el carácter es un carácter alfabético en Minúscula
toupper(<char>); -> char //devuelve el mismo carácter recibido convertido a mayúscula
tolower(<char>); -> char //devuelve el mismo carácter recibido convertido a minúscula


Biblioteca stdio.h:
==================
gets(<cadena>); //reemplaza a scanf(), getstring obtener cadena desde teclado
  char cad[100];
  printf("Ingrese una cadena");
  gets(cad);

puts(<cadena>); //putstring, pone la cadena en pantalla, solo admite cadenas y agrega un \n al final
puts(cadena) <=> printf("%s\n", cad);

sprintf(<cadena>, <cadena de control formato, <datos>);//guarda en variable cadena, lo especificado en los 2 siguientes terminos
sscanf(<cadena>,  <cadena de control formato, <dir. variables>);//Lo que este almacenado en la cadena, se guarda en la variable con el formato especificado (float, int, double)

Biblioteca string.h:
==================
strlen(<cadena>); -> entero(size_t) //devuelve la cantidad de caracteres en un entero sin signos
  int n;
  n = (int)strlen(cad);

strcpy(<destino>, <origen>); //copia en destino lo que hay en origen
strcat(<destino>, <origen>); //concatena origen al final de destino
strchr(<cadena>, <char>); //devuelve un puntero al lugar de la cadena donde se encontro el caracter char *
strstr(<cadena1>, <cadena2>); //buscada cadena2 dentro de cadena1, y devuelve un puntero donde comienza el contenido de cadena2
strcmp(<cadena1>, <cadena2>); //compara el contenido de ambas cadenas, devuel un entero: 0 sin son iguales | <0 si cadena1 < cadena2 | >0 si cadena1 > cadena2
  if(strcmp(cad1, cad2) == 0)
    puts("son iguales");
  else puts("son distintos");


De Caracter a Número:
====================
char c = 3;
int n = c - 48; //valor ASCII para que sea el correcto numero.

Tabla ASCII:
====================
http://www.elcodigoascii.com.ar/
48	>	0								65	>	A								97	>	a
49	>	1				        66	>	B				        98	>	b
50	>	2				        67	>	C				        99	>	c
51	>	3				        68	>	D				        100	>	d
52	>	4				        69	>	E				        101	>	e
53	>	5				        70	>	F				        102	>	f
54	>	6				        71	>	G				        103	>	g
55	>	7				        72	>	H				        104	>	h
56	>	8				        73	>	I				        105	>	i
57	>	9				        74	>	J				        106	>	j
      								75	>	K				        107	>	k
      								76	>	L				        108	>	l
      								77	>	M				        109	>	m
      								78	>	N				        110	>	n
      								79	>	O				        111	>	o
      								80	>	P				        112	>	p
      								81	>	Q				        113	>	q
      								82	>	R				        114	>	r
      								83	>	S				        115	>	s
      								84	>	T				        116	>	t
      								85	>	U				        117	>	u
      								86	>	V				        118	>	v
      								87	>	W				        119	>	w
      								88	>	X				        120	>	x
      								89	>	Y				        121	>	y
      								90	>	Z				        122	>	z


fflus(stdin) -> fget(stdin) (siempre después del scanf)