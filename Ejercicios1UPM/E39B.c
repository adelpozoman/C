#include <stdlib.h>
#include <stdio.h>

int main(){
	puts("Dime el tamaño del triangulo");
	int n,ancho, largo=0;
	scanf("%i",&n);
	FILE* asdf;
	asdf=fopen("E39B.txt","w");
	do{	ancho=n-largo;
		do{	fprintf(asdf,"$");
			ancho--;
		}while(ancho>0);
		fprintf(asdf,"\n");
		largo++;
	}while(largo<n);
return 0;}
