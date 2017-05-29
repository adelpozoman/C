#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E92

struct punto{
		int x;
		int y;
	};

int main(){
	puts("Vamos a calcular areas de polígonos de n lados.\nDime cuántos lados");
	int lados;
	scanf("%i",&lados);
	puts("Ahora me vas a ir escribiendo los vertices");
	struct punto vertice[lados];
	int contador=0;
	do{
		printf("v%i.x=",contador+1);
		scanf("%i",&vertice[contador].x);
		printf("v%i.y=",contador+1);
		scanf("%i",&vertice[contador].y);
		contador++;
	}while(contador<lados);
	
	printf("El area encerrado por el poligono es %i",area(lados,vertice));
	
return 0;}

int area(int lados, struct punto ptr[lados]){//ptr no es un puntero
	int suma=0;
	int contador=0;
	do{
		suma+=(ptr[contador]).x*(ptr[contador+1]).y-(ptr[contador]).y*(ptr[contador+1]).x;
		contador++;
	}while(contador<lados-1);
	suma+=ptr[lados-1].x*ptr[0].y-ptr[0].y*ptr[lados-1].x;
	suma*=0.5;
	
	return suma;}
