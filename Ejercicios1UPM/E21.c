#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*ejercicio21 */
//12,15,26,...27,29,30

main(){

	int n,s;
	puts("Introduce un número\n");
	do{
		if(scanf("%i",&n)!=1){	printf("No has ingresado un número\n");
								while(getchar()!='\n');}
		else if(n<0){			puts("Has puesto un numero negativo\n");}
		else{					printf("Tu número es %i\n",n);		}//aqui podria cerrar el cilo haciendo argo=1 y en while argo!=1
	}while(1);
	return EXIT_SUCCESS;}
