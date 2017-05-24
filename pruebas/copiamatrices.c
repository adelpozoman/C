#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E91

struct punto{
		int x;
		int y;
	};

int main(){
	srand(time(NULL));
	int ancho=(rand()%5)+1, largo=(rand()%8)+1;
	int matriz1[largo][ancho];
	
	int clargo=0, cancho;
	do{	cancho=0;
		do{
		matriz1[clargo][cancho]=rand()%25;
			cancho++;
		}while(cancho<ancho);
		puts("");
		clargo++;
	}while(clargo<largo);
	
	clargo=0;
	do{	cancho=0;
		do{
			printf("%i\t",matriz1[clargo][cancho]);
			cancho++;
		}while(cancho<ancho);
		puts("");
		clargo++;
	}while(clargo<largo);
	
	int m2[clargo][cancho];
	memcpy(m2,matriz1,clargo*cancho*sizeof(int));
	
	puts("\n\n");
	clargo=0;
	do{	cancho=0;
		do{
			printf("%i\t",m2[clargo][cancho]);
			cancho++;
		}while(cancho<ancho);
		puts("");
		clargo++;
	}while(clargo<largo);
	
	
	
return 0;}


