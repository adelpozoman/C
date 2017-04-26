#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void identifica(void){
	puts("*****Ángel del Pozo*****");
	puts("**********53219*********");
	puts("*********Diseño*********");
}
void inicia(void){
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}

int main(void){
	identifica();
while(1){
	inicia();
	puts("Decide el maximo y el minimo");
	int max, min;
	printf("Máximo:");scanf("%i",&max);
	printf("Minimo:");scanf("%i",&min);
		if(min>max){int aux;aux=max;max=min;min=aux;puts("Te los he ordenado");}
	puts("Elige qué tipo de números quieres buscar en tu intervalo");
	puts("\"Primos\"   \"Primos gemelos\"   \"Perfectos\"   \"Amigos\"   \"Malvados\"");
	char opcion[15];
	int numero=0;
	escoge: fflush(stdin);gets(opcion);
		if(strcmp(opcion,"Primos")==0)numero=1;
		if(strcmp(opcion,"primos")==0)numero=1;
		if(strcmp(opcion,"p")==0)numero=1;
		if(strcmp(opcion,"Primos Gemelos")==0)numero=2;
		if(strcmp(opcion,"Primos gemelos")==0)numero=2;
		if(strcmp(opcion,"primos gemelos")==0)numero=2;
		if(strcmp(opcion,"primosgemelos")==0)numero=2;
		if(strcmp(opcion,"gemelos")==0)numero=2;
		if(strcmp(opcion,"pg")==0)numero=2;
		if(strcmp(opcion,"Perfectos")==0)numero=3;
		if(strcmp(opcion,"perfectos")==0)numero=3;
		if(strcmp(opcion,"perfecto")==0)numero=3;
		if(strcmp(opcion,"Amigos")==0)numero=4;
		if(strcmp(opcion,"Amigo")==0)numero=4;
		if(strcmp(opcion,"amigos")==0)numero=4;
		if(strcmp(opcion,"amigo")==0)numero=4;
		if(strcmp(opcion,"a")==0)numero=4;
		if(strcmp(opcion,"Malvados")==0)numero=5;
		if(strcmp(opcion,"malvados")==0)numero=5;
		if(strcmp(opcion,"m")==0)numero=5;
	
	switch(numero){
		case 1:
			puts("Vamos a hacer los numeros primos");
			primos(max,min);
			break;
		case 2:
			puts("Vamos a hacer los primos gemelos");
			primosgemelos(max,min);
			break;
		case 3:
			puts("Vamos a hacer los perfectos");
			perfectos(max,min);
			break;
		case 4:
			puts("Vamos a hacer los amigos");
			amigos(max,min);
			break;
		case 5:
			puts("Vamos a hacer los malvados");
			malvados(max,min);
			break;
		case 0:
			puts("No has escogido ninguna opción correctamente");goto escoge;break;}
}return 0;}

primos(int max, int min){
	int primos[max-min];
	int argo,p=0;
	do{
		argo=1;
		do{
			argo++;
			if(max==argo){primos[p]=max;p++;}
		}while(max%argo!=0);
		max--;
	}while(max>min);
	puts("Los siguientes números primos en tu intervalo:");
	int contadorimprimir=0;
	do{
		printf("%i\t\t",primos[contadorimprimir]);
		contadorimprimir++;
		if(contadorimprimir%4==0){puts("");}//para que la tabla quede bonita
	}while(contadorimprimir<p);
	printf("\nEn total son %i números primos\n",p); 
return 0;}

primosgemelos(int max, int min){
		int primos[max-min];
	int argo,p=0;
	do{
		argo=1;
		do{
			argo++;
			if(max==argo){primos[p]=max;p++;}
		}while(max%argo!=0);
		max--;
	}while(max>min);
	puts("Los siguientes son primos gemelos:");
	int contadorimprimir=0;
	do{
		if(primos[contadorimprimir]-primos[contadorimprimir+1]==2){
			printf("Gemelos: %i y %i\n", primos[contadorimprimir+1],primos[contadorimprimir]);}
		contadorimprimir++;	
	}while(contadorimprimir<p);
	printf("\nEn total son %i números primos\n",p); 
	
	
return 0;}

perfectos(int max, int min){
	puts("Los numeros perfectos en el intervalo son:");
	int argo, sumd, perfectos[max-min], contador=0;
	do{	argo=1;
		sumd=0;
		do{
			if(max%argo==0){sumd=sumd+argo;}
			argo++;
		}while(argo<max);
		if(sumd==max){perfectos[contador]=sumd;contador++;}
		
		max--;
	}while(max>min);
	contador--;
	do{
		printf("%i   ",perfectos[contador]);
		contador--;
	}while(contador>=0);
	
	
	puts("");
return 0;}

amigos(int max, int min){
	int cuenta=0, cuentainterna, sumd[max], argo=0;
	while(cuenta<max){sumd[cuenta]=0;cuenta++;}
	cuenta=max;
	
	do{
		cuentainterna=cuenta;
		do{
			cuentainterna--;
			if(cuenta%cuentainterna==0){sumd[cuenta]=sumd[cuenta]+cuentainterna;}
		}while(cuentainterna>1);
		cuenta--;
	}while(cuenta>1);
//ya tenemos lo que da la suma de los divisores desde 0 hasta max en la matriz sumd, ahora la comparamos y si hay 2 iguales ya sabes
//	int comprueba, c1,c2;scanf("%i",&comprueba);printf("para sumd[%i]=%i\n",comprueba,sumd[comprueba]);
// con lo de arriba comprobamos si funciona la suma de divisores
	int compara=max, comparador;
	
	do{	comparador=compara-1;
		do{
			if(sumd[comparador]==compara&&sumd[compara]==comparador)printf("El %i y el %i son amigos!\n",comparador,compara);
			comparador--;
		}while(comparador>0);
		compara--;
	}while(compara>min);
return 0;}

malvados(int max, int min){
	puts("Vamos a ver qué números malvados hay en el intervalo");
	int contador=max, diasexto, sumb;
	
	
	do{	diasexto=contador;
		sumb=0;
		do{
			if(diasexto%2==1){sumb=sumb+1;}
			
			diasexto=diasexto/2;
		}while(diasexto>0);
		if(sumb%2==0)printf("%i es un número malvado\n",contador);
		
		
		contador--;
	}while(contador>min);
return 0;}
