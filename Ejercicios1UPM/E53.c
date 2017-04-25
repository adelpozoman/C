#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
//E53


int main(){
while(1){
	int dim;
	puts("");
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
//----------------VAMOS A SUMAR EL VALOR ABSOLUTO DE LAS COMPONENTES
	contador=0;
	int suma=0;
	do{
		suma=suma+abs(vector[contador]);
		contador++;	
	}while(contador<dim);
	printf("La norma 1 (suma de los módulos) es: %i\n",suma);
//-----------AHORA HAY QUE VER EL COMPONENTE EN ABSOLUTO MÁS GRANDE
	contador=0;
	int max=abs(vector[contador]);
	do{
		if(max<abs(vector[contador])){
			max=abs(vector[contador]);}
		contador++;
	}while(contador<dim);
	printf("La norma máxima es %i\n",max);
//-----------AHORA HAY QUE INVERTIR EL VECTOR
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
//-------------ahora hay que ordenar el vector
//-------------------------------------
	int ordenado[dim];
	contador=0;
	do{
		ordenado[contador]=vector[contador];
		contador++;
	}while(contador<dim);
	int min, argo, pos,aux;
	contador=0;
	do{	argo=contador;
		min=ordenado[contador];
		do{	if(ordenado[argo]<=min){min=ordenado[argo];pos=argo;}
			argo++;
		}while(argo<dim);
		aux=ordenado[contador];
		ordenado[contador]=min;
		ordenado[pos]=aux;
		contador++;
	}while(contador<dim);
	
	
//--------------------
	puts("El vector ordenado es:");
	contador=0;
	do{
		printf("Ordenada[%i]=%i\n",contador,ordenado[contador]);
		contador++;	
}while(contador<dim);
}return 0;}
