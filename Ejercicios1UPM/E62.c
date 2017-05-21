#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

struct complex{
	float re;
	float i;};
	
void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(void){
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

int main(void){
	identifica();
while(1){
	inicia();
	puts("Te voy a solucionar una ecuacion de 2º grado, con coeficientes \nAx^2 + Bx + C");
	int a, b, c;
	printf("A=");scanf("%i",&a);
	printf("B=");scanf("%i",&b);
	printf("C=");scanf("%i",&c);
//alla vamos
	struct complex sol;
	int existe=b*b -4*a*c;
	int i=0;
	do{
		if(a==0){printf("Tenemos una ecuación sencilla con raíz %.1f\n",-c/b);break;}
		if(a==0&&b==0&&c==0)puts("Error en la entrada");
		if(existe>0){
			sol.re=(-b+(float)(sqrt(existe)))/(2*a);
			sol.i=(-b-(float)(sqrt(existe)))/(2*a);
			printf("Las soluciones son %.1f y %.1f\n",sol.re,sol.i);}
		if(existe==0){
			sol.re=-b/(2*a);
			printf("Tenemos una raíz doble que es %.1f\n",sol.re);;}
		if(existe<0){
			sol.re=(-b)/(2*a);
			sol.i=(float)sqrt(-existe)/(2*a);
			printf("Tenemos dos soluciones complejas conjugadas: %.1f +- i*%.1f \n", sol.re,sol.i);}
			
	}while(i<0);
//listo?
	puts("");
}return 0;}
