#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 40

int main(){
	puts("Dime el lado del cateto del triángulo de Floyd");
	int n, lado=0, argo=1, argo2;
	scanf("%i", &n);
	FILE* triangulo;
	triangulo =fopen("triangulo.txt","w");
	do{		lado++; argo2=0;
			do{	fprintf(triangulo,"%i \t",argo);
			argo2++;
			argo++;
			}while(lado>argo2);
		fprintf(triangulo,"\n");
	}while(lado<n);
	
	
	fclose(triangulo);
	
return 0;system("pause");}
