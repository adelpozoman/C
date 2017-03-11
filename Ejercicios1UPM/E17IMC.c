
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//ejercicio17  


main(){
	float peso, altura;
	puts("Introduce tu peso en kilogramos y luego tu altura en metros");
	scanf("%f %f", &peso, &altura);
	printf("Para tu peso %0.1f y tu altura %0.2f te corresponde un IMC de:\n \t", peso, altura);
	float IMC;
	IMC= ((peso)/(altura*altura));
	printf("%.2f",IMC);
	
	return EXIT_SUCCESS;
	return 0;
	system("pause");
}

