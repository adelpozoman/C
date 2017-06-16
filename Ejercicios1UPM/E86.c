#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#define min(a,b) a<b? a: b
#define max(a,b) a>b? a:b
//E86

int main(void){
identifica();
while(1){
	ejecuta();
	puts("Dime el número de filas");
	int filas; scanf("%i",&filas);
	puts("Ahora el número de columnas");
	int columnas; scanf("%i",&columnas);
	int m1[filas][columnas];
	scanfm(filas, columnas, m1);//crea matriz aleatorio
	printm(filas, columnas, m1);//enseñasela al usuario
//ahora hay dos formas, primera ir posicion por posicion a ver si es maximo en fila y minimo en columna O minimo en fila y maximo en columna, y asi con todas las posiciones
//y la otra forma es, en una fila, busca el maximo, es minimo en la columna?
//en la misma fila busca el minimo, es maximo en la columna? asi con cada fila

//el primer metodo tendria las 3 funciones del enunciado, pero es mucho menos eficiente, hay que hacer columnasxfilasx2x2 iteraciones en total
//en el segundo metodo solo filasx2x2 iteraciones
//voy a usar el primer metodo
//el maximo numero de puntos de silla sera dos veces el numero de filas o el de columnas, el que sea menor
	int nreal=0, nmax=min(filas, columnas)+min(filas,columnas);
//nreal es el numero de puntos encontrados
	int puntos[nmax][3];
//esta matriz guarda los puntos, en cada fila uno. primera columna el numero que es, segunda en que fila esta y 3ª en que columna esta
	puntossilla(filas, columnas, m1, &nreal, nmax, puntos);
//ya sabemos los puntos de silla, ahora hay que escribirlos
	printf("Te he encontrado %i puntos de silla, los cuales, con su posicion son:\n",nreal);
	int contfila=0;
while(contfila<nreal){
	printf("Punto %i en posicion [%i][%i]\n",puntos[contfila][0],puntos[contfila][1]+1,puntos[contfila][2]+1);
	contfila++;}
/*	puts("\n\nEscribe numeros para volver a empezar o letras para salir");
	if(scanf("%i",&columnas)!=1)break;*/
}return 0;}

identifica(){
	puts("******************");
	puts("**Ángel del Pozo**");
	puts("******************");
	puts("Voy a generar una matriz aleatoria y te voy a decir si tiene puntos de silla o no");}

ejecuta(){
	puts("");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");}

scanfm(int filas, int columnas, int(*m1)[columnas]){
	int contfila=0, contcolumna;
	srand(time(NULL));
	do{
		contcolumna=0;
		do{
			*(m1[contfila]+contcolumna)=(rand()%39);
			contcolumna++;
		}while(contcolumna<columnas);
		contfila++;
	}while(contfila<filas);
}

printm(int filas, int columnas, int (*m1)[columnas]){
	puts("Esta es tu matriz");
	int i=0,j;//contador de filas y columans
	do{
		j=0;
		do{
			printf("%i\t",*(m1[i]+j));
			j++;
		}while(j<columnas);
		puts("");
		i++;
	}while(i<filas);
}

puntossilla(int filas, int columnas, int m1[filas][columnas], int* ptrnreal, int nmax, int (*puntos)[3]){
int contfila=0, contcolumna;
do{
	contcolumna=0;
	do{//ahora aqui ya tenemos cada posicion, hay que ver si es puntosillaono


		if((cmin(filas, columnas,m1,contfila,contcolumna)&&ccmax(filas, columnas,m1,contfila,contcolumna))||
		   (cmax(filas, columnas,m1,contfila,contcolumna)&&ccmin(filas, columnas,m1,contfila,contcolumna))){
			//he encontrado un punto en la posicion filas, columnas, lo guardo
			*(puntos[*ptrnreal]+0)=m1[contfila][contcolumna];
			*(puntos[*ptrnreal]+1)=contfila;
			*(puntos[*ptrnreal]+2)=contcolumna;
			*ptrnreal=*ptrnreal+1;}

		contcolumna++;
	}while(contcolumna<columnas);
	contfila++;
}while(contfila<filas);
}

//cmax y cmin comprueba si el numero que le hemos dado es maximo(cmax) o minimo(cmin) y devuelve un 1 en caso favorable
//ccmin comprueba en la columna y ccmax en la columna tambien
cmin(int filas, int columnas, int m1[filas][columnas], int contfila, int contcolumna){
	int min=m1[contfila][0];
	int i=0;
	do{
		if(m1[contfila][i]<min)min=m1[contfila][i];
		i++;
	}while(i<columnas);
	if(min==m1[contfila][contcolumna])return 1;
	return 0;}

cmax(int filas, int columnas, int m1[filas][columnas], int contfila, int contcolumna){
	int max=m1[contfila][0];
	int i=0;
	do{
		if(m1[contfila][i]>max)max=m1[contfila][i];
		i++;
	}while(i<columnas);
	if(max==m1[contfila][contcolumna])return 1;
	return 0;}


ccmin(int filas, int columnas, int m1[filas][columnas], int contfila, int contcolumna){
	int min=m1[0][contcolumna];
	int i=0;
	do{
		if(m1[i][contcolumna]<min)min=m1[i][contcolumna];
		i++;
	}while(i<filas);
	if(min==m1[contfila][contcolumna])return 1;
	return 0;}


ccmax(int filas, int columnas, int m1[filas][columnas], int contfila, int contcolumna){
	int max=m1[0][contcolumna];
	int i=0;
	do{
		if(m1[i][contcolumna]>max)max=m1[i][contcolumna];
		i++;
	}while(i<filas);
	if(max==m1[contfila][contcolumna])return 1;
	return 0;}




