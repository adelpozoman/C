#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ejercicio 44

int main(){
	puts("Vamo a tirar una moneda un millón de veces");
	int caras[2]={0,0},n, argo=0;
	srand(time(NULL));//0 es cara, 1 es cruz		
	do{	argo++;
		n=rand()%2;
		if(n==0)caras[0]++;
		if(n==1)caras[1]++;
	}while(argo<1000000);
	printf("Ha salido %i caras y %i veces cruz", caras[0],caras[1]);

return 0;}
