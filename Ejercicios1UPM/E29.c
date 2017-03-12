#include <stdlib.h>
#include <stdio.h>

int main(){
	puts("Introduce un número natural positivo");
	int n, argo=1,intento=0,x=0, divisores[x];//x sera el numero de divisores
	scanf("%i",&n);
	do{	intento++;
		if(n%intento==0){
			divisores[x]=intento;
			x++;}
	}while(intento<n);
	argo=x, x=0;
	do{	printf("Divisor %i: %i\n",x,divisores[x]);
		x++;}
	while(x<argo);
	puts(" ");
//el ultimo do-while se puede borrar, es para comprobar si funciona
//ahora a imprimirlo al archivo
	x=0;
	FILE* gazpacho;
	gazpacho=fopen("salmorejo.txt","w");
	do{	fprintf(gazpacho,"Divisor %i: %i\n",x,divisores[x]);
		x++;}
	while(x<argo);
	fclose(gazpacho);
	return 0;}
