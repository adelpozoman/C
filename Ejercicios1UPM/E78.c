#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E78

main(){
	puts("Introduce un numero y te hallar� las combinaciones posibles de ese numero en los huecos desde 0 hasta ese numero");
	int n;
	while(scanf("%i",&n)!=1||getchar()!='\n'){puts("Entrada incorrecta");fflush(stdin);}
	int combinaciones[n], contador=0;
	do{
		combinaciones[contador]=combina(n,contador);
		//printf("El valor n�mero %i es %i\n",contador,combinaciones[contador]);
		contador++;
	}while(contador<n);
return;}






int combina(int n, int contador){	
	int numerador, denominador1,denominador2, resultado;
	numerador=factorial(n);
	denominador1=factorial(n-contador);
	denominador2=factorial(contador);
	resultado=(numerador/(denominador1*denominador2));
	
	printf("Las combinaciones de n%i sobre contador %i son %i\n",n,contador,resultado);
return resultado;}

int factorial(n){
	int b, factorial=1;
	for (b = n; b > 1; b--){
    factorial = factorial * b;}	
return factorial;}
