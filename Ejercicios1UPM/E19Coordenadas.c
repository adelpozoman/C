#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MODULO(x,y) sqrt((x*x)+(y*y))

//ejercicio 19

int main(){
	int x;
	int y;
	puts("Escribe las dos coordenadas cartesianas de un punto");
	scanf("%d %d", &x, &y);
	printf("El punto de coordenadas %d %d tiene una distancia al origen de %.2f", x, y, MODULO(x,y));
	float ang;
	ang = atan(y/x);
	printf(" y %.3f grados radianes", ang);

	
	
	return EXIT_SUCCESS;
}






