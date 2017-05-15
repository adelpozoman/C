
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E90

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(){
	puts("");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

int main(void){
identifica();
while(1){
	inicia();
	puts("Vamos a ver la traza de la matriz que sale al multiplicar un vector por su traspuesta");
	puts("El primero sera un array columna y el segundo fila.\nDime las filas del primero o columnas del segundo");
	int lado;
	while(scanf("%i",&lado)!=1||getchar()!='\n'){puts("Lo has hecho mal");fflush(stdin);}
	int array[lado], *ptrarray=array;
	valeatorio(lado, ptrarray);
	int matriz[lado][lado], *ptrmatriz=matriz;
	prodtensorial(lado, ptrarray, ptrmatriz);
	puts("Nuestra matriz:");
	imprimematriz(lado, ptrmatriz);
	int traza=0,*ptrtraza=&traza;
	calctraza(lado, ptrmatriz, ptrtraza);
	printf("Tiene como traza %i o %i\n",traza, *ptrtraza);
}}

void valeatorio(int lado, int *ptrarray){
	srand(time(NULL));
	int contador=0;
	do{
		*(ptrarray+contador)=rand()%30;
		contador++;
	}while(contador<lado);
return;}

void prodtensorial(int lado, int *ptrarray, int (*ptrmatriz)[lado]){
	int contadorfila=0, contadorcolumna;
	do{
		contadorcolumna=0;
		do{
			*(ptrmatriz[contadorcolumna]+contadorfila)=(*(ptrarray+contadorfila)*(*(ptrarray+contadorcolumna)));
			contadorcolumna++;
		}while(contadorcolumna<lado);
		contadorfila++;
	}while(contadorfila<lado);
return;}

void imprimematriz(int lado,int (*ptrmatriz)[lado]){
	int contadorfila=0, contadorcolumna;
	do{
		contadorcolumna=0;
		do{
			printf("%i\t",*(ptrmatriz[contadorcolumna]+contadorfila));
			contadorcolumna++;
		}while(contadorcolumna<lado);
		puts("");
		contadorfila++;
	}while(contadorfila<lado);
	
return;}

void calctraza(int lado, int (*ptrmatriz)[lado], int *ptrtraza){
	int contador=0;
	do{
		*(ptrtraza)=*ptrtraza+*(ptrmatriz[contador]+contador);
		contador++;
	}while(contador<lado);
return;}
