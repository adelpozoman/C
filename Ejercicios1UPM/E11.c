#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//va sacando divisores, los suma y si es perfecto la suma es igual al número
int main(){
	puts("Introduce un número para saber si es perfecto");
	int n,divisor=0,sumd=0,argo=1;
	scanf("%i",&n);
	do{	sumd=n%argo;
		if(sumd==0){divisor=divisor+argo;}
		argo++;
	}
	while(argo<n );
	if(divisor==n){puts("Es perfecto");}
	else{puts("No es perfecto");}

return EXIT_SUCCESS;system("pause");}


*/
