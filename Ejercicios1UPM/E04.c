#include <stdlib.h>
#include <stdio.h>

int main(){
	puts("Introduce dos n�meros enteros y puede que el primero sea divisor del segundo");
	int a,b,c,d;
	scanf("%i%i",&a,&b);
	if(a<b){
		c=b;
		b=a;
		a=b;
		}
	d=a%b;
	if(d!=0){printf("El resto de la divisi�n es %i",d);}
	else if(d==0){puts("Tu segundo n�mero divide al primero");}
	
	
	
	
	
	return EXIT_SUCCESS;system("pause");}
