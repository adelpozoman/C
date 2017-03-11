#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("Introduce un número y se sumarán sus dígitos\n");
	int n, d,dividendo, exi, sumi, sum2=0;
	scanf("%i",&n);
	printf("Tu número %i tiene ", n);
	d=0;
	dividendo= 1;
//Calcula el numero de digitos(valor d)
	do{	dividendo=dividendo*10;
		exi= n/dividendo;
		d++;}while(exi>0);
	printf("%d dígitos\n", d);
//operacion q saca los digitos y los suma en sum2---LINEA17
	do{	d=d-1;
		dividendo=dividendo/10;
		sumi= n/dividendo;
		printf("dividendo %i:\t", dividendo);
		printf("%i + \n ", sumi);
		sum2= sumi+sum2;
		n= n -dividendo*sumi; //si es 55, hace 55 -10*5, menos cifras
		}while(n>0);
	printf("\nLa suma de los dígitos da %i\n", sum2);return 0;system("pause");}
