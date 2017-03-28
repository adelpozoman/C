#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//ejercicio 51

int main(){
	puts("Vas a tener que adivinar un numero entre 0 y 100 incluidos, escribirás un número y yo te diré si el número al que quieres llegar es mayor o menor");
	srand(time(NULL));
	int contador=0, n= rand()%101, intento;
	do{ 	fflush(stdin); scanf("%i",&intento);
			if(intento<n){puts("El número es mayor al que has escrito");}
			else if(intento>n){puts("El número es menor al que has escrito");}
			contador++;		
	}while(intento!=n);
	printf("Enhorabuena, has adivinado el número %i. ",n);
	if(contador<7){printf("Has necesitado muy pocos intentos, %i en concreto",contador);	}
	else if(contador>7&&contador<9){printf("Has necesitado muchos intentos, %i en concreto",contador);}	
	else if(contador>9){puts("Has necesitado demasiados intentos");	}
	return 0;}
