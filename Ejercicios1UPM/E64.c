#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E64

void identifica(void){
	puts("*****�ngel del Pozo*****");
	puts("**********53219*********");
	puts("*********Dise�o*********");
}
void inicia(void){
	puts("");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

main(){
	identifica();
	while(1){
		inicia();	
		puts("Te voy a calcular el per�metro de un pol�gono\n�Cu�ntos lados o v�rtices quieres que tenga?");
		int lados;
		scanf("%i",&lados);
		puts("Ahora me vas a ir diciendo las coordenadas de cada v�rtice, primero su X y luego su Y\nHas de ser consciente de meter los v�rtices en un orden correcto");
		int contador=0, contador2;
		int vertices[lados][2];
		//voy a guardar los vertices en un array de 2 dimensiones
		//cada fila es un punto diferente, la primera columna la x y la segunda la y
		do{	contador2=0;
			do{
				printf("P%i",contador);
				if(contador2==0){printf("x=");}
				if(contador2==1){printf("y=");}
				scanf("%i",&vertices[contador][contador2]);
				contador2++;
			}while(contador2<2);
			contador++;
		}while(contador<lados);
	//ahora tenemos los v�rtices, hay que hacer los c�lculos
		double suma=0;
		contador=1;
		do{
			suma=suma+sqrt(pow((vertices[contador][0]-vertices[contador-1][0]),2)+pow((vertices[contador][1]-vertices[contador-1][1]),2));
			contador++;
		}while(contador<lados);
		if(lados>2){suma=suma+sqrt(pow((vertices[lados-1][0]-vertices[0][0]),2)+pow((vertices[lados-1][1]-vertices[0][1]),2));}
		
		printf("El per�metro de tu figura de %i lados es %.3f",lados, suma);	
}return;}
