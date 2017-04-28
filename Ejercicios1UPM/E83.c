#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(void){
	puts("");
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("Pulsa 0 para salir");
	puts("*****************");
	puts("");
}


void main(){
	identifica();
	while(1){
		inicia();
		puts("Te voy a hallar los números de armstrong menores al número que me digas");
		int n, suma;
		while(scanf("%i",&n)!=1||getchar()!='\n'){puts("No has escrito un número bien");fflush(stdin);}
		//suma=sumadigitoscuadrado(n);
		if(n==0)break;	
		int contador=1;
		do{
			suma=sumadigitoscuadrado(contador);
			if(suma==contador){printf("El número %i es de Armstrong\n",suma);}
			contador++;
		}while(contador<n);
	}return 0;}
			
int sumadigitoscuadrado(int n){
	int num=n, d=0, dividendo=1, exi, sumi;
	do{	dividendo=dividendo*10;
		exi=num/dividendo;
		d++;}while(exi>0);
	//printf("El número tiene  %i cifras\n",d);
	int argo=d, argo2=d, argo3=d,argo4=d, argo5=d, n1[d], n2[d], cero=0;
	do{	d--;
		dividendo=dividendo/10;
		sumi=num/dividendo;//ya tenemos la primera cifra
		n1[d]=sumi;
		num=num -dividendo*sumi;}while(d>0);//guarda num como array
	int sumacuadrada=0;
	int contador=0;
	do{
		sumacuadrada=sumacuadrada+pow((n1[contador]),argo5);
		contador++;
	}while(contador<argo5);
//	printf("La suma cuadrada da %i\n", sumacuadrada);
return sumacuadrada;}
