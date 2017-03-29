#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 57

int main(){
	puts("Vas a escribir un número y te voy a decir los números inferiores a él que sean primos");
	int n,p=0, primos[500],argo;
	scanf("%i",&n);
	
	do{
		argo=1;
		do{
			argo++;
			if(n==argo){primos[p]=n;p++;}
		}while(n%argo!=0);
		n--;
	}while(n>1);
	
	
	puts("Los siguientes números primos son inferiores a tu número:");
	int contadorimprimir=0;
	do{
		printf("%i\t\t",primos[contadorimprimir]);
		contadorimprimir++;
		if(contadorimprimir%3==0){puts("");}//para que la tabla quede bonita
	}while(contadorimprimir<p);
	printf("\nEn total son %i números primos\n",p);	
system("pause");}
