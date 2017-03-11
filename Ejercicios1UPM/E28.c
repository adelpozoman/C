#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	printf("Introduce el n√∫mero de veces que quieres que se calcule la ");
	puts("proporcion a√∫rea");
	float n, c=0, cuenta=1, cfinal;
	scanf("%f",&n);
		do{	c++;
		cfinal=1+(1/cuenta);
		cuenta=cfinal;
		}while(c<n);
	printf("El resultado es %.5f\n",cuenta);
	
//segunda parte
	puts("Escribe una potencia negativa de 10 para saber el n˙mero de tÈrminos necesarios para que la aproximaciÛn sea menor que tu n˙mero introducido");
	int elv,argo=0, argo2;
	double diferencia, dielv=1;
	scanf("%i",&elv);
	do{	dielv= 0.1*dielv;
		argo++;
	}while(argo<elv);	
//	printf("%.10f",dielv);	
	argo=0, cuenta=1, argo=0, cfinal=0;
	do{ argo++;
		cfinal=1+(1/cuenta);
		cuenta=cfinal;
		diferencia= ((1+sqrt(5))/2) - cfinal;
		if(diferencia<0){diferencia=-diferencia;}
		
	}while(diferencia>dielv);

	printf("se ha hecho la operaciÛn %i veces", argo);



return 0;}
