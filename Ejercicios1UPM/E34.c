#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	puts("Para calcular combinaciones de X elementos en Y huecos, introduce ambos números");
	int e, h, argo, factorial=1, hfactorial=1;
	unsigned long numerador, denominador;
//podria hacer las multiplicaciones m*(m-1)***(m-n+1) o numerador/denominador
	scanf("%i %i", &e, &h);
	if(e<h){argo=e;e=h;h=argo;puts("Te he ordenado los valores");}
	argo=0;
	do{	argo++;
		factorial=argo*factorial;}
	while(argo<e);
	numerador=factorial;
//ya tengo hecho el numerador, ahora el denominador
	argo=e-h, factorial=1;
	do{	factorial=argo*factorial;
		argo--;}
	while(argo>0);
	do{	argo++;
		hfactorial=argo*hfactorial;}
	while(argo<h);
	denominador=factorial*hfactorial;
//	printf("%li %li\n", numerador, denominador); podriamos comprobar numerador y denominador asi
	printf("Tus combinaciones posibles son %li\n", numerador/denominador);
return 0;}
