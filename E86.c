#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E86

void identifica(void){
	puts("*****�ngel del Pozo*****");
	puts("**********53219*********");
	puts("*********Dise�o*********");
}

int main(void){
identifica();
	puts("Vamos a escribir una matriz, dime las filas");
	int filas,columnas;
	scanf("%i",&filas);
	puts("Ahora dime las columnas");
	scanf("%i",&columnas);
	int m1[filas][columnas], f, c;
//ahora llenamo la matriz
	srand(time(NULL));
	f=0;
	do{	c=0;
		do{	
			m1[f][c]=rand()%30;
			c++;
		}while(c<columnas);
		f++;
	}while(f<filas);
//le ense�amos la matriz al usuario
	puts("Tu matriz es:");
	f=0;
	do{	c=0;
		do{
			printf("%i\t",m1[f][c]);
			c++;
		}while(c<columnas);	
		puts("");
		f++;
	}while(f<filas);
//ahora hay que hacer las cuentas
//voy a gaurdar los encontrados en el array doble silla, la primera columna es la fila en la que esta y las segunda columna la columna en la q esta nuestro punto (en la matriz inicial)
//si es maximo en la columna es maximo en su fila de la traspuesta, ahorra un monton de cuentas y funciones
	int m2[c][f];
	llenam2(filas, columnas, m1, m2);//m2=&m2[0][0]
	/*puts("\n\n\n");
	f=0;
	do{	c=0;
		do{
			printf("%i\t",m2[f][c]);
			c++;
		}while(c<filas);	
		puts("");
		f++;
	}while(f<columnas);*/ 
	
//encontrados es el numero encontrado
	int encontrados;
	int silla[encontrados]; //es un poco chungo hacerlo variable
	encontrados=0;
	f=0;
	do{	c=0;
		do{
			if(1==puntosilla(filas, columnas,f,c,m1,m2)){
				printf("seguro que he encontrado 1, en fila %i columna %i\n",f,c);
				silla[encontrados]=m1[f][c];
				encontrados++;}
			c++;
		}while(c<columnas);
		f++;
	}while(f<filas);
	
	printf("He encontrado %i puntos de silla, los cuales son (en fila y columna):\n",encontrados);
	int gazpacho=0;
	while(gazpacho<encontrados){
		printf("Pto.%i--x:%i\n",gazpacho+1,silla[gazpacho]);
		gazpacho++;}
return EXIT_SUCCESS;}

void llenam2(int filas, int columnas, int (*m1)[columnas], int (*m2)[filas]){
	int cuenta1, cuenta2=0;
	do{	cuenta1=0;
		do{
			
			*(m2[cuenta2]+cuenta1)=*(m1[cuenta1]+cuenta2);
			cuenta1++;
		}while(cuenta1<filas);
		
		cuenta2++;
	}while(cuenta2<columnas);
}

int puntosilla(int filas, int columnas, int f, int c, int (*m1)[columnas], int (*m2[filas])){
	puts("Compruebo (mal)");
	if(1==min(filas, columnas,f,c,m1)&&1==max(columnas,filas,f,c,m2))return 1;//lo q se mete en max es lo q hay q arreglar
//en la segunda funcion hay q meter la traspuesta y ver si es maximo en su fila de la traspuesta
	if(1==max(filas, columnas,f,c,m1)&&1==min(columnas,filas,f,c,m2))return 1;
//aqui en min se mete la traspuesta
	return 0;}
//punto de silla comprueba si nuestro numero es maximo o minimo en su fila y si es minimo o maximo en su fila de la traspuesta


int min(int filas, int columnas, int f, int c, int (*m1)[columnas]){
	int minimo=*(m1[0]);
	int contador;
	do{
		if((*(m1[contador]+f))<minimo){
			minimo=(*(m1[contador]+f));
			}
		contador++;
	}while(contador<columnas);
	
	if(minimo==(*(m1[c]+f)))return 1;
		//es minimo, vamos adecirselo, q compruebe si es maximo en la columna
	
	return 0;}


int max(int filas, int columnas, int f, int c, int (*m1)[columnas]){
	int maximo=*(m1[0]);
	int contador;
	do{
		if((*(m1[contador]+f))>maximo){
			maximo=(*(m1[contador]+f));
			}
		contador++;
	}while(contador<columnas);
	if(maximo==(*(m1[c]+f))){
		//es maximo, vamos adecirselo, q compruebe si es minimo en la columna
		return 1;}
	
	return 0;}


