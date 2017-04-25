#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
//E53


int main(){
	int dim;
	puts("Introduce la dimensión del vector");
	scanf("%i",&dim);
	int vector[dim];
	puts("Vas a elegir los valores del vector");
	int contador=0;
	do{
		printf("vector[%i]=",contador);
		scanf("%i",&vector[contador]);
		contador++;
	}while(contador<dim);
	float norma=0;
	contador=0;
	do{
		norma=norma+ vector[contador]*vector[contador];
		contador++;	
	}while(contador<dim);
	norma=sqrt(norma);
	printf("La norma 2 (modulo) es %f\n",norma);
//-----------------------
	contador=0;
	int suma=0;
	do{
		suma=suma+abs(vector[contador]);
		contador++;	
	}while(contador<dim);
	printf("La norma 1 (suma de los módulos) es: %i\n",suma);
//---------------------------------------
	contador=0;
	int max=abs(vector[contador]);
	do{
		if(max>abs(vector[contador])){
			max=abs(vector[contador]);}
		contador++;
	}while(contador<0);
	printf("La norma máxima es %i\n",max);
//-------------------
	int invertida[dim];
	contador=0;
	do{
		invertida[dim-1-contador]=vector[contador];
		contador++;				
	}while(contador<=dim);
	contador=0;
	puts("La invertida es:");
	do{
		printf("Vector invertido[%i]=%i\n",contador, invertida[contador]);
		contador++;
	}while(contador<dim);
//--------------
	int ordenada[dim], intento, posordenada=0;
	int min, aux;
	//codigo ordenar vector aqui
	do{
		
		
		
		
	
	
		
		
		posordenada++;
	}while(posordenada<dim);
//-----------
	puts("El vector ordenado es:");
	contador=0;
	do{
		printf("Ordenada[%i]=%i\n",contador,ordenada[contador]);
		contador++;	
	}while(contador<dim);
	return 0;}
