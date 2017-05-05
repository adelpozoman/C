#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E77

main(){
	puts("Introduce un numero y te hallaré las combinaciones sin repeticion posibles");
	int n, contador;
	while(scanf("%i",&n)!=1||getchar()!='\n'){puts("Entrada incorrecta");fflush(stdin);}
		while(scanf("%i",&contador)!=1||getchar()!='\n'){puts("Entrada incorrecta");fflush(stdin);}
	int combinaciones;
	
		combinaciones=combina(n,contador);
		printf("Tus combinaciones posibles son %i", combinaciones);
return;}






int combina(int n, int contador){	
	int numerador, denominador1,denominador2, resultado;
	numerador=factorial(n);
	denominador1=factorial(n-contador);
	denominador2=factorial(contador);
	resultado=(numerador/(denominador1*denominador2));
	
	//printf("Las combinaciones de n%i sobre contador %i son %i\n",n,contador,resultado);
return resultado;}

int factorial(n){
	int b, factorial=1;
	for (b = n; b > 1; b--){
    factorial = factorial * b;}	
return factorial;}
