#include <stdio.h>
#include <stdlib.h>

int main(){
	puts("Introduce un número para saber si es par o impar");
	int n, n1,n2;
	scanf("%i",&n);
	n1=n%2;
	if(n1==0){
		puts("Tu número es par");}
	else{puts("Tu número probablemente es impar");}return 0;}
