 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//ejercicio 8


main(){
	int n, p;
	puts("Introduce un número al número al que lo quieres elevar");
	scanf("%d %d", &n, &p);
	printf("%d elevado a %d es ", n, p);
	
	int mult= 0;
	int resultado;
	int nresultado;
	
	do{
		mult++;
		resultado = n * nresultado;
		nresultado = resultado;
		
		
		
	}while(mult<p);
	printf("%d",nresultado);
		
	return EXIT_SUCCESS;
}
