#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned long nfactorial=1, factorial;
	int n, argo;
	puts("Escribe un número menor que 21 del que quieras hallar el factorial");
	scanf("%i",&n);
	for(argo=1;argo<=n;argo++){
		factorial=argo*nfactorial;
		nfactorial=factorial;
		printf("%i * ",argo);}
printf("1 = %i! = %li\n",n,nfactorial);
return EXIT_SUCCESS;}
//el enunciado no dice que si la entrada es incorrecta meta otra
