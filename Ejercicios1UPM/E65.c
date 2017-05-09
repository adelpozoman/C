#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E65

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");}

int main(){
	identifica();
	puts("Vamos a escribir una matriz cuadrada, dime el lado");
	int lado;
	scanf("%i",&lado);
	puts("Ahora dime las columnas");
	int m1[lado][lado], f, c;
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
			}while(c<lado);
			f++;
		}while(f<lado);}
	if(strcmp(opcion,"Aleatorio")==0){
		srand(time(NULL));
		f=0;
		do{	c=0;
			do{	
				m1[f][c]=rand()%30;
				c++;
			}while(c<lado);
			f++;
		}while(f<lado);}
	if(strcmp(opcion,"Manual")!=0&&strcmp(opcion,"Aleatorio")!=0){puts("No has cogido ninguna opcion");goto elige;}
	puts("Tu matriz es:");
	f=0;
	do{	c=0;
		do{
			printf("%i\t",m1[f][c]);
			c++;
		}while(c<lado);
		puts("");
		f++;
	}while(f<lado);
//ya tenemos nuestra matriz y se la hemos enseñado al usuario, ahora vamos a calcular la traspuesta
	int traspuesta[lado][lado];
	float simetrica[lado][lado], antisimetrica[lado][lado];
	f=0;
	do{
		c=0;
		do{
			traspuesta[c][f]=m1[f][c];
			c++;
		}while(c<lado);
		f++;
	}while(f<lado);
//ya tenemos la traspuesta, ahora a por la simetrica
	f=0;
	do{
		c=0;
		do{
			simetrica[f][c]=0.5*(m1[f][c]+traspuesta[f][c]);
			c++;
		}while(c<lado);
		f++;
	}while(f<lado);
//ahora a por la antisimetrica
	f=0;
	do{
		c=0;
		do{
			antisimetrica[f][c]=0.5*(m1[f][c]-traspuesta[f][c]);
			c++;
		}while(c<lado);
		f++;
	}while(f<lado);
//ya esta, se las enseñamos al usuario
	puts("Tu matriz simetrica es:");
	f=0;
	do{	c=0;
		do{
			printf("%.0f\t",simetrica[f][c]);
			c++;
		}while(c<lado);
		puts("");
		f++;
	}while(f<lado);
	puts("Tu matriz anti simetrica es:");
	f=0;
	do{	c=0;
		do{
			printf("%.0f\t",antisimetrica[f][c]);
			c++;
		}while(c<lado);
		puts("");
		f++;
	}while(f<lado);
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;}
