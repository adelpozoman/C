#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){
	puts("Escribe el numero que corresponda 'Variaciones(1)', 'Variaciones con repeticiones(2)' o 'Combinaciones(3)");
	int opcion;
	fflush(stdin);
	scanf("%d", &opcion);
	switch(opcion){
		case 1:
			puts("Para calcular variaciones de X elementos en Y huecos, introduce ambos números");
				int e, h, argo, factorial=1;
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
				denominador=factorial;
			//	printf("%li %li\n", numerador, denominador); podriamos comprobar numerador y denominador
				printf("Tus variaciones posibles son %li\n", numerador/denominador);break;
		case 2:
			puts("Introduce los valores de los elementos y los huecos de los que quieras variar con repeticion");
				int e2, h2, argo2=1, contador2=0;
				unsigned long n2;
				scanf("%i %i",&e2,&h2);
				do{	n2=e2*argo2;
					argo2=n2;
					contador2++;
				}while(contador2<h2);
				printf("Tienes %li variaciones\n",n2);break;
		case 3:
			puts("Para calcular combinaciones de X elementos en Y huecos, introduce ambos números");
				int e3, h3, argo3, factorial3=1, hfactorial3=1;
				unsigned long numerador3, denominador3;
			//podria hacer las multiplicaciones m*(m-1)***(m-n+1) o numerador/denominador
				scanf("%i %i", &e3, &h3);
				if(e<h){argo3=e3;e3=h3;h3=argo3;puts("Te he ordenado los valores");}
				argo3=0;
				do{	argo3++;
					factorial3=argo3*factorial3;}
				while(argo3<e3);
				numerador3=factorial3;
			//ya tengo hecho el numerador, ahora el denominador
				argo3=e3-h3, factorial3=1;
				do{	factorial3=argo3*factorial3;
					argo3--;}
				while(argo3>0);
				do{	argo3++;
					hfactorial3=argo3*hfactorial3;}
				while(argo3<h3);
				denominador3=factorial3*hfactorial3;
			//	printf("%li %li\n", numerador, denominador); podriamos comprobar numerador y denominador
				printf("Tus combinaciones posibles son %li\n", numerador3/denominador3);break;
		default:puts("asdf"); break;
}return EXIT_SUCCESS;}
