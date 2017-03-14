#include <stdio.h>
#include <stdlib.h>
#define centiafarenh(m) ((m * (9/5)) + 32)
#define farenhacenti(m) ((0.555555555555555555) * (m - 32))
//ejercicio 16
int main(void){
	
	char u;
	int m; //la medida que tengamos( el númkero de grados)
	printf("¿Quieres pasar de Centigrados a Farenheit o de Farenheit a Centigrados?\n Escribe c para la primera opción y f para la segunda\n");
	scanf("%s", &u);
	//nos pasa de un tipo a otro, dependiendo del inicial
	if(u == 'c'){
		printf("¿Escribe un numero natural de grados centigrados\n");
		scanf("%i", &m);
		printf("Ese valor corresponde a %d grados Farenheit\n", centiafarenh(m));
		}
	
	else if (u == 'f'){
		printf("Escribe un numero natural de grados farenheit\n");
		scanf("%i", &m);
		printf("Ese valor corresponde a %i grados centigrados\n", farenhacenti(m));
		}
			
	return EXIT_SUCCESS;
	}











