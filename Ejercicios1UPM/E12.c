#include <stdlib.h>
#include <stdio.h>
#include  <math.h>
int main(){
	puts("Introduce dos numeros para saber su MCD y su mcm");
	int n, n2,naux, d, d2, argo;
	scanf("%i %i",&n,&n2);	
//vamos a ordenar los numeros
	if(n<n2){
		naux=n;
		n=n2;
		n2=naux;
	}

naux=n%n2;
d=n;
d2=n2;
//ahora el mcd
do{	fflush(stdin);
	n=n2;
	n2=naux;
	naux=n%n2;
	}while(naux>0);
printf("El maximo comun divisor es %i\n",n2);

//ahora el mcm
naux=d*d2/n2;
printf("El minimo comun multiplo es %i\n",naux);

//divisores del primero por los del segundo entre mcd da el mcm
//osea el primero por el segundo entre mcd
return 0;system("pause");}
