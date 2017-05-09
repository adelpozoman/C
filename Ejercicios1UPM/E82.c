#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//E82

int main(){
	puts("Escribe un numero para saber su factorizacoin en numeros primos");
	int ninicial, d, divisores[d], intento=2, primo;
	scanf("%i",&ninicial);
	d=0;
	int naux=ninicial;
	
	do{			
		do{
			if(naux%intento==0){divisores[d]=intento;d++; naux=naux/intento;}
			if(naux%intento!=0){break;			}
		}while(1);												
		intento++;
	}while(intento<ninicial);
	
	int contadorimprimir=0;
	puts("La factorización es:");
	do{	printf("%i * ",divisores[contadorimprimir]);	
		contadorimprimir++;
	}while(contadorimprimir<d-1);
	printf("%i",divisores[d-1]);
return 0;}
