#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//ejercicio 38

identifica(){
	puts("***Matrícula:53219***");
	puts("***Ángel del Pozo***");
	puts("***Grupo: Diseño***");
	return;}
int main(){
	identifica();
	int salir;
	char opcion1;
	do{
		puts("\n**************************************\nEscribe el numero que corresponda 'Variaciones(1)', 'Variaciones con repeticiones(2)' o 'Combinaciones(3)");
		puts("Escribe @ para salir");
		int salir;
		fflush(stdin);
		scanf("%c", &opcion1);
		switch(opcion1){
			case '1':
				variaciones();
				break;
			case '2':
				variacionesrepeticion();break;
			case '3':
				combinaciones();break;
			default:puts("No has elegido ninguna opcion o has elegido cerrar el programa");
		}
	}while(opcion1!='@');
return EXIT_SUCCESS;}


factorial(numero){
	int argo=0, factorial=1;
	do{	argo++;
		factorial=argo*factorial;}
	while(argo<numero);
	return factorial;}
	
variaciones(){
	puts("Para calcular variaciones de X elementos en Y huecos, introduce ambos números");
	int e, h, argo;
	unsigned long numerador, denominador;
//podria hacer las multiplicaciones m*(m-1)***(m-n+1) o numerador/denominador
	scanf("%i %i", &e, &h);
	if(e<h){argo=e;e=h;h=argo;puts("Te he ordenado los valores");}
	numerador=factorial(e);
//ya tengo hecho el numerador, ahora el denominador
	denominador=factorial(e-h);
//	printf("%li %li\n", numerador, denominador); podriamos comprobar numerador y denominador asi
	printf("Tus variaciones posibles son %li\n", numerador/denominador);
	FILE* resultados;
		resultados=fopen("resultados.txt","a");
	fprintf(resultados,"Has elegido variaciones con datos %i y %i y el resultado %i\n",e,h,numerador/denominador);	
	fclose(resultados);
}
	
variacionesrepeticion(){
	puts("Introduce los valores de los elementos y los huecos de los que quieras variar con repeticion");
	int e, h;
	unsigned long n;
	scanf("%i %i",&e,&h);
	n=potencia(e,h);
	printf("Tienes %li variaciones\n",n);
	FILE* resultados;
		resultados=fopen("resultados.txt","a");
	fprintf(resultados,"Has elegido variaciones con repeticion con datos %i y %i y el resultado %i\n",e,h,n);	
	fclose(resultados);	}
	
potencia(e,h){
	int argo=1, contador=0, n;
	do{	n=e*argo;
		argo=n;
		contador++;
	}while(contador<h);
	return argo;
}	
		
combinaciones(){
	puts("Para calcular combinaciones de X elementos en Y huecos, introduce ambos números");
	int e, h, argo;
	unsigned long numerador, denominador;
	scanf("%i %i", &e, &h);
	if(e<h){argo=e;e=h;h=argo;puts("Te he ordenado los valores");}
	numerador=factorial(e);
//ya tengo hecho el numerador, ahora el denominador
	denominador=factorial(e-h)*factorial(h);
	printf("Tus combinaciones posibles son %li\n", numerador/denominador);
	FILE* resultados;
	resultados=fopen("resultados.txt","a");
	fprintf(resultados,"Has elegido combinaciones con datos %i y %i y el resultado %i\n",e,h,numerador/denominador);	
	fclose(resultados);}



	
	
	
	
	
	


