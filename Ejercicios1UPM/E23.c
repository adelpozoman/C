#include <stdio.h>
#include <stdlib.h>
//ejercicio 23

int main(){
	char c;
	int contador=0;
	while((c=getchar())!='\n'){	putchar(c);
								contador++;}
	printf("\nHas escrito %i car�cteres",contador);
return 0;}
