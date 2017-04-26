#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/*ejercicio21 */
main(){
	int n;
	puts("Introduce un número\n");
	do{	while(scanf("%i",&n)!=1||getchar()!='\n'){puts("Puede ser que no hayas puesto un número");fflush(stdin);}
		printf("Has elegido %i\n", n);
	}while(1);
	return EXIT_SUCCESS;}
