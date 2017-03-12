#include <stdlib.h>
#include <stdio.h>

int main(){
	puts("Dime el tamaño del triangulo");
	int n,ancho, largo=1;
	scanf("%i",&n);
	FILE* asdf;
	asdf=fopen("E39D.txt","w");
	do{	ancho=0;
		do{	fprintf(asdf,"@");
			ancho++;
		}while(ancho<largo);
		fprintf(asdf,"\n");
		largo++;
	}while(largo<=n);
return 0;}
