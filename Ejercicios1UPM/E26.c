#include <stdio.h>
#include <stdlib.h>

int main(){
	puts("Introduce el año que quieres saber si es bisiesto");
	int n;
	scanf("%i",&n);
	if(n%4!=0){puts("Es un año común");}
	else if(n%100!=0){puts("Es un año bisiesto");}
	else if(n%400!=0){puts("Es un año común");}
	else{puts("Es un año bisiesto");}
return EXIT_SUCCESS;}
