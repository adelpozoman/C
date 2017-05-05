#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E76

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}


int main(){identifica();
while(1){
	puts("Introduce tus elementos y los huecos en los que los quieres variar con repeticion");
	int base, exponente;
	scanf("%i",&base);
	scanf("%i",&exponente);
	long potencia=pot(base, exponente);
	printf("Tienes %li variaciones posibles\n", potencia);
}return 0;}

pot(int base, int exponente){
	int contador=0,potencia=base;
	do{	potencia=potencia*base;
		contador++;		
	}while(contador<exponente-1);
	return potencia;
}
