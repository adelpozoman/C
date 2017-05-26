#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E79

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(void){
	puts("\n");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

int main(void){
	identifica();
	setlocale(LC_ALL, "spanish");
while(1){
	inicia();
	puts("Escribe un número a y b para (a+b)^D");
	int a, b;
	printf("a=");scanf("%i",&a);
	printf("b=");scanf("%i",&b);
	puts("Cuál quieres que sea el exponente");
	int e;scanf("%i",&e);
	printf("Veamos (%i+%i)^%i\n",a,b,e);
	int suma=0, contador=0;
	do{	
		suma+=(combina(e,contador))*pow(a,contador)*pow(b,e-contador);
		printf("La suma actual es %i\n",suma);
		contador++;
	}while(contador<=e);
	
	printf("La suma da %i",suma);
	
}return 0;}

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

