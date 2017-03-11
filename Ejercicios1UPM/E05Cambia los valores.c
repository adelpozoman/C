#include <stdio.h>
#include <stdlib.h>


//ejercicio 5
int main(void){
	
	int n1, n2, n3, n4;
	puts("Introduce dos numeros naturales y distintos \n");
	scanf("%d", &n4);
	scanf("%d", &n3);
	printf("El primer valor es %d", & n4);
	printf ("y el segundo %d\n", &n3);
	n1 = n3;
	n4 = n2;
	printf("Ahora el primer valor es %d", &n1);
	printf(" y el segundo %d", &n2);
	
	
	return EXIT_SUCCESS;
	
	/*
	int auxiliar, v1, v2;

    printf( "\n   Introduzca el valor de v1: " );
    scanf( "%d", &v1 );
    printf( "\n   Introduzca el valor de v2: " );
    scanf( "%d", &v2 );

    printf( "\n   Intercambiando los valores..." );

   

    auxiliar = v1;
    v1 = v2;
    v2 = auxiliar;

    printf( "\n\n   Ahora, el valor de v1 es: %d", v1 );
    printf( "\n\n   Ahora, el valor de v2 es: %d", v2 );

    getch();
    return 0;
    */
	
}
