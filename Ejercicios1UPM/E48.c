#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 48

int main(){
	int p,n, potencias[n];//n sera el largo de la tabla, p el numero de potencias o ancho
	puts("Escribe el número de potencias que quieres obtener");
	scanf("%i",&p);
	puts("Escribe hasta que número quieres saber las potencias");
	scanf("%i",&n);
	int argo=1,argo2,argo4=1,largohecho, p2=p,n2=n;
	do{	printf("N^%i\t",argo);
			argo++;		
			}while(argo<=p);
	puts("");
	largohecho=1;
		do{  argo2=1, n=0, potencias[0]=argo4;
				do{ potencias[n]=potencias[0]*argo2;
					argo2= potencias[n];
					printf("%i\t", argo2);
					n++;
				}while(n<p);
				argo4++;
			puts("");	
			}while(argo4<=n2);

	return 0;system("pause");}

