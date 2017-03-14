#include <stdio.h>
#include <stdlib.h>
#define centiafarenh(m) ((m*(1.8)) + 32)
#define farenhacenti(m) (m-32)*0.5555555556
//ejercicio 16
int main(void){
	
	char u;
	float m; //la medida que tengamos( el númkero de grados)
	printf("¿Quieres pasar de Centigrados a Farenheit o de Farenheit a Centigrados?\n Escribe c para la primera opción y f para la segunda\n");
	scanf("%s", &u);
	//nos pasa de un tipo a otro, dependiendo del inicial
	if(u == 'c'){
		printf("¿Escribe un numero natural de grados centigrados\n");
		scanf("%f", &m);
		printf("Ese valor corresponde a %.2f grados Farenheit\n", centiafarenh(m));
		}
	
	else if (u == 'f'){
		printf("Escribe un numero natural de grados farenheit\n");
		scanf("%f", &m);
		printf("Ese valor corresponde a %.2f grados centigrados\n", farenhacenti(m));
		}
			
	return EXIT_SUCCESS;
	}


