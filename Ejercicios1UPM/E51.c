#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 51

int main(){
	puts("Vas a tener que adivinar un numero entre 0 y 100 incluidos, escribir�s un n�mero y yo te dir� si el n�mero al que quieres llegar es mayor o menor");
	srand(time(NULL));
	int contador=0, n= rand()%101, intento;
	do{ 	fflush(stdin); scanf("%i",&intento);
			if(intento<n){puts("El n�mero es mayor al que has escrito");}
			else if(intento>n){puts("El n�mero es menor al que has escrito");}
			contador++;		
	}while(intento!=n);
	printf("Enhorabuena, has adivinado el n�mero %i. ",n);
	if(contador<7){printf("Has necesitado muy pocos intentos, %i en concreto",contador);	}
	else if(contador>7&&contador<9){printf("Has necesitado muchos intentos, %i en concreto",contador);}	
	else if(contador>9){puts("Has necesitado demasiados intentos");	}
	return 0;}
