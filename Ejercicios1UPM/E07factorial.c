#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*ejercicio 7 */


main(){
	int numero;
	puts("Vamos a hallar el factorial de un número\n Introduce el número");
	scanf("%d",&numero);
	printf("Has escogido %i, así que el factorial es: \t 1 ", numero);
	
	int multiplicacion;
	multiplicacion = 0;
	int resultado;
	int fanterior;
	
	
do{

multiplicacion++;
resultado = multiplicacion * fanterior;
fanterior = resultado;
printf("* %d", multiplicacion);



}while(multiplicacion<numero);
	
printf("\n %d", fanterior);

/*		do{
	fanterior = numero-1;
	printf("* %d", fanterior);
	numero=fanterior;	
		
		
	}while(fanterior<1);
	
	*/

	
	
	
	
	return EXIT_SUCCESS;
}
