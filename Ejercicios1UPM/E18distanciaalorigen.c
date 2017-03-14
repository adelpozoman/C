#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MODULO(x,y) sqrt((x*x)+(y*y))
//ejercicio18

main(){
	int x,y;
	puts("Escribe las coordenadas cartesianas de un punto y te doy su distancia al origen");
	scanf("%d %d", &x, &y);
	printf("El punto de coordenadas %d %d tiene una distancia al origen de ", x, y);
	printf("%.2f", MODULO(x,y));
	
	
	return EXIT_SUCCESS;
}



