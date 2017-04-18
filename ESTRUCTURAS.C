#include <stdio.h>
#include <stdlib.h>





int main(){


puts("elige estudiante 1 o 2");
int opcion;
scanf("%i",&opcion);

struct perro{
	int edad;
	char nombre[5];
	int peso;
}perro1={15,"Rufo", 59},perro2={13,"Shaila",43},dejose[5];
dejose[0].edad=15;

printf("el estudiante %i tiene %i de edad, %s de nombre y %i de peso",opcion,perro1.edad,perro1.nombre,perro1.peso);
return 0;
}
