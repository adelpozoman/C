#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	puts("Dime el tamaño del cuadrado");
	int n,ancho, largo=0;
	scanf("%i",&n);
	FILE* asdf;
	asdf=fopen("E39.txt","w");
	do{	ancho=0;
		do{	fprintf(asdf,"*");
			ancho++;
		}while(ancho<n);
		fprintf(asdf,"\n");
		largo++;
	}while(largo<n);
fclose(asdf);return 0;}
