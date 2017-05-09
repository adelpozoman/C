#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E84

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");}

void inicia(void){
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");}

int main(){
	identifica();
	while(1){
		inicia();
		puts("Vamos a escribir una matriz, dime las filas");
		int filas,columnas;
		scanf("%i",&filas);
		puts("Ahora dime las columnas");
		scanf("%i",&columnas);
		int m1[filas][columnas], f, c;
		puts("Quieres llenar la matriz o que lo haga aleatoriamente?\nEscribe \"Manual\" o \"Aleatorio\"");
		char opcion[20];
		elige: fflush(stdin);
		gets(opcion);
//ahora se va a dar valores a la matriz, de forma manual o aleatoria, según lo elegido
		if(strcmp(opcion,"Manual")==0){
			puts("Ahora me vas a ir diciendo los valores de la matriz separados, y fila a fila.");
			f=0;
			do{	c=0;
				
				do{	
					printf("M[%i][%i]=",f,c);
					scanf("%i",&m1[f][c]);
					c++;
				}while(c<columnas);
				
				f++;
			}while(f<filas);}
		if(strcmp(opcion,"Aleatorio")==0){
			srand(time(NULL));
			f=0;
			do{	c=0;
				do{	
					m1[f][c]=rand()%30;
					c++;
				}while(c<columnas);
				f++;
			}while(f<filas);}
		if(strcmp(opcion,"Manual")!=0&&strcmp(opcion,"Aleatorio")!=0){puts("No has cogido ninguna opcion");goto elige;}
		repetir:fflush(stdin);
//le enseñamos la matriz al usuario
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
		puts("¿Vas a permutar filas o columnas?\nEscribe \"Filas\" o \"Columnas\"");
		filasocolumnas: fflush(stdin);
		gets(opcion);
//ahora vamos a permutar, o filas o columnas, depende de lo elegido
		if(strcmp(opcion,"Filas")==0){
			int auxiliar[filas];
			puts("Escribe la posicion (n-1) que ocupa tu fila, luego la de la fila por la que la quieres permutar.");
			puts("Si escribes 1 y luego 2, te voy a cambiar la fila 2 por la fila 3");
			int pos1, pos2;
			scanf("%i",&pos1);
			scanf("%i",&pos2);
			c=0;
			do{	
				auxiliar[c]=m1[pos1][c];
				c++;
			}while(c<columnas);
			c=0;
			do{	
				m1[pos1][c]=m1[pos2][c];
				c++;
			}while(c<columnas);
			c=0;
			do{	
				m1[pos2][c]=auxiliar[c];
				c++;
			}while(c<columnas);}
		if(strcmp(opcion,"Columnas")==0){
			int auxiliar[columnas];
			puts("Escribe la posicion (n-1) que ocupa tu columna, luego la de la columna por la que la quieres permutar.");
			puts("Si escribes 1 y luego 2, te voy a cambiar la columna 2 por la columna 3");
			int pos1, pos2;
			scanf("%i",&pos1);
			scanf("%i",&pos2);
			f=0;
			do{
				auxiliar[f]=m1[f][pos1];
				f++;
			}while(f<filas);
			f=0;
			do{
				m1[f][pos1]=m1[f][pos2];
				f++;
			}while(f<filas);
			f=0;
			do{
				m1[f][pos2]=auxiliar[f];
				f++;
			}while(f<filas);}
		if(strcmp(opcion,"Filas")!=0&&strcmp(opcion,"Columnas")!=0){puts("No has elegido ninguna opcion");goto filasocolumnas;}
//ya esta hecho, lo vamos a imprimir para que se vea el cambio
		puts("Tu resultado es:");
		f=0;
		do{	c=0;
			do{
				printf("%i\t",m1[f][c]);
				c++;
			}while(c<columnas);	
			puts("");
			f++;
		}while(f<filas);
		puts("Si deseas volver a permutar usando la misma matriz escribe \"Repetir\", si quieres salir \"Salir\" y si no cualquier cosa");
		fflush(stdin);gets(opcion);
		if(strcmp(opcion,"Repetir")==0)goto repetir;
		if(strcmp(opcion,"Salir")==0)return 0;
}}
