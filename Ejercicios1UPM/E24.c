#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned long long n,c=0, nfinal, nanterior=1;
	puts("Escribe 25");
	scanf("%lli",&n);
	do{ 	c++;
		nfinal=c*nanterior;
		nanterior=nfinal;}while(c<n);
	printf("%lli\n",nanterior);
	FILE* fi;
	fi=fopen("fich.txt","w");
	fprintf(fi,"%lli\n",nanterior);
	fclose(fi);
return 0;}
