#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 48

int main(){
	int p,n;//n sera el largo de la tabla, p el numero de potencias o ancho
	puts("Escribe el número de potencias que quieres obtener");
	scanf("%i",&p);
	puts("Escribe hasta que número quieres saber las potencias");
	scanf("%i",&n);
	int argo=1;
	do{	printf("N^%i\t",argo);
		argo++;		
	}while(argo<=p);
	puts("");
	int potencias[n][p], c1=0,c2=0, anterior;
	do{	potencias[c2][0]=c2+1, anterior=1, c1=0;
		do{	potencias[c2][c1]=potencias[c2][0]*anterior;
			anterior=potencias[c2][c1];
			printf("%i\t",potencias[c2][c1]);
			c1++;
		}while(c1<p);
	puts("");
	c2++;
	}while(c2<n);
return 0;system("pause");}
