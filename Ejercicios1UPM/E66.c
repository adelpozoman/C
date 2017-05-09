#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E66

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(void){
	puts("");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

main(){
	double numero, *puntero;
	numero=5;
	puntero=&numero;
	printf("El numero ahora vale %.0f\n",numero);	
	printf("El numero ahora vale %.0f\n",*puntero);
	*puntero=*puntero+5;
	printf("El numero ahora vale %.0f\n",numero);
	*puntero=*puntero-12;
	printf("El numero ahora vale %.0f\n",numero);
	*puntero=*puntero+13;
	printf("El numero ahora vale %.0f\n",numero);
	
return;}
