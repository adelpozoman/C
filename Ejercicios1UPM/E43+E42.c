#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ejercicio 41

int main(){
	puts("Vamos a generar numeros aleatorios según la hora de tu procesador");
	int n, a, b, argo=0;
	printf("¿Cuántos?\t");scanf("%i",&n);
	printf("\nNúmero límite inferior\t");scanf("%i",&a);
	printf("\nNúmero límite superior\t");scanf("%i",&b);
	srand(time(NULL));
	do{	argo++;
		printf("\n%i\t",(rand()%(b-a+1))+a);
	}while(argo<n);

return 0;}
