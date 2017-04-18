#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
//tarea clase martes 18/04/2017


int main(){
	int v1[4],v2[4];
	int argo=0;
	do{
		printf("v[%i]=",argo);
		scanf("%i",&v1[argo]);
		argo++;
	}while(argo<4);
	argo=0;
	do{
		printf("v2[%i]=",argo);
		scanf("%i",&v2[argo]);
		argo++;
	}while(argo<4);
	
	puts("\nDime qúe quieres hacer, sin equivocarte al escribir");
	puts("(Modulo)(Producto escalar)(Producto escalar usual)(Suma)(Componentes)");
	char opcion[20];
	fflush(stdin);
	gets(opcion);
	if(strcmp(opcion,"Modulo")==0){
		puts("El modulo del primer vector es :");
		int mod1,mod2,contador=0,suma,suma2=0;
		do{
			suma=(v1[contador]*v1[contador])+suma2;
			suma2=suma;
			contador++;
		}while(contador<4);
		mod1=sqrt(suma2);
		printf("%i unidades\n",mod1);
		
		puts("El modulo del segundo vector es:");
		contador=0;suma2=0;
		do{
			suma=(v2[contador]*v2[contador])+suma2;
			suma2=suma;
			contador++;
		}while(contador<4);
		mod2=sqrt(suma2);
		printf("%i unidades\n",mod2);
	}	
	if(strcmp(opcion,"Producto escalar")==0){
		puts("Dime qué escalar quieres usar");fflush(stdin);
		int escalar;scanf("%i",&escalar);
		int argo=0;
		do{
			printf("v1'[%i]=%i\t",argo,v1[argo]*escalar);
			argo++;
		}while(argo<4);
		argo=0;puts("");
		do{
			printf("v2'[%i]=%i\t",argo,v2[argo]*escalar);
			argo++;
		}while(argo<4);
		
	}
	if(strcmp(opcion,"Producto escalar usual")==0){
		puts("El producto escalar usual de un vector por el otro es:");
		int suma;
		printf("%i", (v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2]+v1[3]*v2[3]));
	}
	if(strcmp(opcion,"Suma")==0){
		puts("La suma de los dos vectores da el vector:");
		int vectorsuma[4];
		int contador=0;
		do{	vectorsuma[contador]=v1[contador]+v2[contador];
			contador++;
		}while(contador<4);
		printf("v1: %i\t v2: %i\t v3: %i\t v4: %i",vectorsuma[0],vectorsuma[1],vectorsuma[2],vectorsuma[3]);
	}
	if(strcmp(opcion,"Componentes")==0){
		/*int min, max;
		do{
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			if(v1[0]>v1[1]){}
			
			
		}
		
		
		
		*/
		
	}
	return 0;}

