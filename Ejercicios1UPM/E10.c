#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int num, d=0, dividendo=1, exi, sumi;
	printf("Introduce un número--\n");
	scanf("%i", &num);
	do{	dividendo=dividendo*10;
		exi=num/dividendo;
		d++;}while(exi>0);
	printf("El número tiene  %i cifras\n",d);
	int argo=d, argo2=d, argo3=d,argo4=d, n1[d], n2[d], cero=0;
	do{	d--;
		dividendo=dividendo/10;
		sumi=num/dividendo;//ya tenemos la primera cifra
		n1[d]=sumi;
		num=num -dividendo*sumi;}while(d>0);//guarda num como array
	do{	argo--;
		printf("%i", n1[argo]);}while(argo>0);//imprime el numero
	puts("");
	do{	argo2--;
		n2[argo2]= n1[argo];
		argo++;}while(argo<argo3);
	do{	argo3--;
		printf("%i", n2[argo3]);}while(argo3>0);//imprimesegundonum
	puts("");
//comprobemos si es capicúa
	d=argo=argo2=argo3=argo4;
	int nc=0;//nc es las cifras capicuas
	do{
		d--;
		if(n1[d]==n1[cero]){
				nc=nc+1;
				cero++;}}
	while(d>0);
	if(nc==argo){puts("Es capicua");}else{puts("no es capicua");}
return 0;}
