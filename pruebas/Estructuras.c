
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

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

struct complejo{
	double real;
	double imagin;
};

struct punto{
	int x;
	int y;
};

typedef struct punto creapunto;
typedef struct complejo creacomplejo;


int main(){
	identifica();
	creapunto primero;
	creacomplejo complejo1;
	primero.x=3;
	primero.y=3;
	convertir(primero, &complejo1);
	printf("El numero x=%i e y=%i corresponde a a=%.3f bi=%.3fi",primero.x,primero.y,complejo1.real,complejo1.imagin);
	
	
	
	
return 0;}



void convertir(struct punto primero, struct complejo *apntadorcomplejo){
	
	
	(*apntadorcomplejo).real=primero.x;
	(*apntadorcomplejo).imagin=primero.y;
	
	
		
	
}


