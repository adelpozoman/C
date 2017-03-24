#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ejercicio 49

int main(){
	puts("Dime cuántos números aleatorios quieres obtener");
	int n, contador=0, min, max;
	scanf("%i",&n);
	puts("Dime primero el numero minimo y luego el numero maximo");
	scanf("%i%i",&min,&max);
	if(min>max){		int naux;
						naux=max;
						max=min;
						min=naux;
						puts("Te he ordenado el intervalo");}
	puts("Los numeros aleatorios obtenidos son:");
	long int numeros[n];
	srand(time(NULL));
	do{	numeros[contador]=(rand()%(max-min+1))+min;
		printf("%i\t",numeros[contador]);
		contador++;
	}while(contador<n);
	puts("\n Vamos a obtener la media y la cuasi desviación típica\n***loading***");
	contador=0;
	long double suma=0;
	do{	suma=suma+numeros[contador];
		contador++;
	}while(contador<n);
	float media=(suma/n);
	printf("Media: %.2f", media);

	contador=0,suma=0;
	do{	suma=suma+ (numeros[contador]*numeros[contador]);
		contador++;
	}while(contador<n);
	suma= suma-((n)*media*media);
	float cuasi=sqrt(suma/(n-1));
	printf("\t Cuasi-desviación típica: %.3f", cuasi);
	return 0;}
	
	
	//es importante que el numerador no sea int pa q haya decimales
