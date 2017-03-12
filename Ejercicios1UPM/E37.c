#include <stdio.h>
#include <math.h>

int main(){
	puts("Introduce un número para saber si es primo");
	int n,argo=2;
	scanf("%i",&n);
	do{	if(n%argo!=0){argo++;}
		else if((n%argo)==0){puts("Tu número no es primo");break;}
	}while(n>argo);
	if(n==argo){puts("Tu número es primo");}
return 0;}
