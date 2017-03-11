#include <stdio.h>
#include <stdlib.h>
#define MULTI(n1, n2, n3) n1 * n2 * n3

//ejercicio 2
int main(void)
{
	int n1;
	int n2;
	int n3;
	printf("Escribe 3 numeros que quieras sumar\n");
	scanf("%d",&n1);
	scanf("%d",&n2);
	scanf("%d",&n3);
	printf("La multiplicacion nos da %d", MULTI(n1 ,n2 , n3));
	
	
	
	
	
	return EXIT_SUCCESS;
	
}

