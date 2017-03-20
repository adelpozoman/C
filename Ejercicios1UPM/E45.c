#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//ejercicio 45

int main(){
	puts("Vamo a tirar un dado 6 millone de veces");
	int caras[6]={0,0,0,0,0,0},n, argo=0;
	srand(time(NULL));//0 es cara, 1 es cruz		
	do{	argo++;
		n=rand()%6;
		if(n==0)caras[0]++;//cara 1
		if(n==1)caras[1]++;
		if(n==2)caras[2]++;
		if(n==3)caras[3]++;//cara 4
		if(n==4)caras[4]++;
		if(n==5)caras[5]++;//cara 6
	}while(argo<6000000);
	double f1=(caras[0]/6)*0.000001,f2=(caras[1]/6)*0.000001,f3=(caras[2]/6)*0.000001,f4=(caras[3]/6)*0.000001,f5=(caras[4]/6)*0.000001,f6=(caras[5]/6)*0.000001;
	puts("Las frecuencias absolutas y sus respectivas probabilidades de cada cara son:");
	printf("Cara 1:\t%i, %.4f\nCara 2:\t%i, %.4f\nCara 3:\t%i, %.4f\nCara 4:\t%i, %.4f\nCara 5:\t%i, %.4f\nCara 6:\t%i, %.4f\n",caras[0],f1,caras[1],f2,caras[2],f3,caras[3],f4,caras[4],f5,caras[5],f6);
return 0;}
