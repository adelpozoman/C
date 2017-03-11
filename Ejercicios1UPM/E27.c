#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	puts("Introduce el número de numeros naturales a los que quieras sacar sus tres primeras potencias");
	int n, n2, n3,salir,argo=0;
	scanf("%i",&n);
	do{	if(n>=100||n<0){
		puts("Has introducido un número demasiado grande o negativo");
		scanf("%i",&n);}
//podria haber hecho if(n>0) demasiado grando y else if(n<0) el numero es negativo
		else{salir=1;}}
	while(salir!=1);
	printf("\nN¹\tN²\tN³\n");
	do{	argo++;
		n2= argo*argo;
		n3=argo*n2;
		printf("%i\t%i\t%i\n",argo,n2,n3);}while(argo<n);
	argo=0;
	FILE* fi;
	fi=fopen("fich.txt","w");
	do{	argo++;
		n2=argo*argo;
		n3=n2*argo;
		fprintf(fi,"%i\t%i\t%i\n",argo,n2,n3);}while(argo<n);
	fclose(fi);

return EXIT_SUCCESS;}
