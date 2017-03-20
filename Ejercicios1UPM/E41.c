#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ALEATORIO(m,n,n0, MOD) ((m*n0)+n)*MOD
//ejercicio 41

int main(){
	puts("Mediante el metodo de regresion lineal se van a generar 20 numeros aleatorios\nLos parámetros usados son:\tM: pendiente o multiplicador.\n\t\t\t\tN: ordenada en el origen o incremento.\n\t\t\t\tMOD:modulo");
	int m, n, n0, MOD, argo=0;
	printf("Ahora vas a decir qué valores van a tomar:\nM:\t");
	scanf("%i",&m);printf("N:\t");
	scanf("%i",&n);printf("MOD:\t");
	scanf("%i",&MOD);printf("n0:\t");
	scanf("%i",&n0);
	FILE* E41;
	E41= fopen("E41.txt", "a");
	fprintf(E41,"Nueva ejecución\n");
	do{	argo++;
		fprintf(E41,"%i\n",ALEATORIO(m,n,n0,MOD));
		n0++;
	}while(argo<20);
	
	fclose(E41);return 0;}
