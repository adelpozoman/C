#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	puts("Introduce los valores de los elementos y los huecos de los que quieras variar con repeticion");
	int e, h, argo=1, contador=0;
	unsigned long n;
	scanf("%i %i",&e,&h);
	do{	n=e*argo;
		argo=n;
		contador++;
	}while(contador<h);
	printf("Tienes %li variaciones\n",n);



return 0;}
