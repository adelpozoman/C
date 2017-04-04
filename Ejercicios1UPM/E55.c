#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ejercicio 55

int main(){
	char letras[100];
	gets(letras);
	int contador=strlen(letras);
	printf("\nHas escrito %i carácteres, y si los inviertes tienes:\n",contador);
	do{	contador--;
		printf("%c",letras[contador]);
	}while(contador>=0);
	
return 0;}
