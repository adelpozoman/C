#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ejercicio 41

int main(){
	puts("Vamos a generar numeros aleatorios seg�n la hora de tu procesador");
	int n, a, b, argo=0;
	printf("�Cu�ntos?\t");scanf("%i",&n);
	printf("\nN�mero l�mite inferior\t");scanf("%i",&a);
	printf("\nN�mero l�mite superior\t");scanf("%i",&b);
	srand(time(NULL));
	do{	argo++;
		printf("\n%i\t",(rand()%(b-a+1))+a);
	}while(argo<n);

return 0;}
