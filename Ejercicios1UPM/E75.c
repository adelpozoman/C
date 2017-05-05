#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E75

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}


int main(){identifica();
while(1){
	puts("Introduce tu base y tu exponente");
	int base, exponente;
	scanf("%i",&base);
	scanf("%i",&exponente);
	long potencia=pot(base, exponente);
	printf("El resultado es %li\n", potencia);
}return 0;}

pot(int base, int exponente){
	int contador=0,potencia=base;
	do{	potencia=potencia*base;
		contador++;		
	}while(contador<exponente-1);
	return potencia;
}
