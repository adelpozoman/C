#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#define min(a,b) a<b? a: b
#define max(a,b) a>b? a:b

//prototipos de las funciones
void identifica(void);
void ejecuta(int ejecucion);
void deriva(int grado, int * ptrv);
void primitiva(int grado, int * ptrv);
int valorderivadaenpunto(int punto2,int grado,int * ptrv);
float valorprimitivaenpunto(int punto, int grado, int * ptrv);

void main(void){
	setlocale(LC_ALL,"spanish");
	identifica();
	int ejecucion=1;
	int flag;
	puts("Este programa sirve para realizar diferentes operaciones con polinomios de coeficientes reales, como son derivar, integrar o calcular el valor del polinomio en un punto");
	puts("Sal del programa en cualquier momento escribiendo -1");
while(1){
//el bucle while se ejecutara hasta que el usuario escriba -1 en CUALQUIER momento, lo que terminará el programa y mostrará el mensaje despedida
//logicamente si escribe 32-1 el programa no lo detecta.
	ejecuta(ejecucion);
	puts("Siendo el polinomio a + bx + cx^2 + dx^3... ¿cuál quieres que sea el grado maximo?");
	int grado; 
	while(scanf("%i",&grado)!=1||getchar()!='\n'||grado<-1){
		puts("Has escrito un grado maximo invalido, por favor vuelve a intentarlo");fflush(stdin);}
//voy a guardar los coeficientes en un vector, v[0] sera el coeficiente de a en a, v[1] el coeficiente de b en bx, y asi sucesivamente
	if(grado==-1)break;
	int * ptrv;
	ptrv= malloc(sizeof(int)*(grado+1));//si tiene 2 grados, guarda 3 valores, el constante, el bx^1 y cx^2
	puts("Ahora vamos a ver los coeficientes");
//vamos a guardar los coeficientes del polinomio
	int contador=0;
	do{
		printf("Coeficiente de x^%i=",contador);
		while(scanf("%i",ptrv+contador)!=1||getchar()!='\n'){
			puts("Has escrito un coeficiente invalido, por favor vuelve a intentarlo");fflush(stdin);}
		if((*(ptrv+contador))==-1){flag=-1;break;}
		contador++;
	}while(contador<=grado);
	if(flag==-1)break;
//vamos a enseñar el polinomio al usuario
	printf("f(x)= ");
	contador=0;
	do{	
		if(contador==grado){
			printf("%ix^%i\n\n",*(ptrv+contador),contador);
			break;}
		//el if me sirve para prevenir que en la ultima iteracion escriba el resultado con un + al final(probar borrando if{}
		printf("%ix^%i + ",*(ptrv+contador),contador);
		contador++;
	}while(contador<=grado);
	puts("A continuacion te voy a dar diferentes opciones que hacer con el polinomio que has escogido");
	elige: fflush(stdin);
	puts("\"Derivada\" \"Primitiva\" \"Valor en punto\" \"Valor derivada primera\" \"Integral intervalo\"");
	char opcion[25];
	scanf("%25[^\n]",opcion);
//voy a hacer strcmp en diferentes casos por si el usuario se equivoca
	int caso=0;
			if(strcmp(opcion,"Derivada")==0)caso=1;
			if(strcmp(opcion,"derivada")==0)caso=1;
			if(strcmp(opcion,"deriva")==0)caso=1;
			if(strcmp(opcion,"Primitiva")==0)caso=2;
			if(strcmp(opcion,"primitiva")==0)caso=2;
			if(strcmp(opcion,"Valor en punto")==0)caso=3;
			if(strcmp(opcion,"valor en punto")==0)caso=3;
			if(strcmp(opcion,"valor en un punto")==0)caso=3;
			if(strcmp(opcion,"valorpunto")==0)caso=3;
			if(strcmp(opcion,"Valor derivada primera")==0)caso=4;
			if(strcmp(opcion,"valor derivada primera")==0)caso=4;
			if(strcmp(opcion,"Valor primera derivada")==0)caso=4;
			if(strcmp(opcion,"valor derivada primera")==0)caso=4;
			if(strcmp(opcion,"valorderivada")==0)caso=4;
			if(strcmp(opcion,"Integral intervalo")==0)caso=5;
			if(strcmp(opcion,"integral intervalo")==0)caso=5;
			if(strcmp(opcion,"integral en intervalo")==0)caso=5;
			if(strcmp(opcion,"integralenintervalo")==0)caso=5;
			if(strcmp(opcion,"integralintervalo")==0)caso=5;
			if(strcmp(opcion,"-1")==0)break;
//segun el valor de caso es una opcion u otra en el menu
	switch(caso){
		case 1:
			puts("La derivada de tu polinomio es:");
			deriva(grado, ptrv);
			break;
		case 2:
			puts("La primitiva de tu polinomio es:");
			primitiva(grado,ptrv);
			break;
		case 3:
			puts("Dime en qué punto quieres saber el valor del polinomio");
			int punto;
			while(scanf("%i",&punto)!=1||getchar()!='\n'){
					puts("No contemplo tu punto, elige bien por favor");fflush(stdin);}
			if(punto==-1){flag=-1;break;}
			int contador=0;
			int valor=0;
			do{
				valor+=(*(ptrv+contador))*pow(punto,contador);
				contador++;
			}while(contador<=grado);
			printf("El valor del polinomio en el punto es %i",valor);
			break;
		case 4:
			puts("Dime en qué punto quieres saber el valor de la derivada");
			int punto2;
			while(scanf("%i",&punto2)!=1||getchar()!='\n'){
					puts("No contemplo tu punto, elige bien por favor");fflush(stdin);}
			if(punto==-1){flag=-1;break;}
			printf("El valor de la derivada en el punto es %i",valorderivadaenpunto(punto2,grado,ptrv));
			break;
		case 5:
			puts("Dime el intervalo para el calculo de la integral");
			int a,b,min,max;
			while(scanf("%i",&a)!=1||getchar()!='\n'){
					puts("No contemplo tu punto para mi intervalo, elige bien por favor");fflush(stdin);}
			if(a==-1){flag=-1;break;}
			while(scanf("%i",&b)!=1||getchar()!='\n'){
					puts("No contemplo tu punto para mi intervalo, elige bien por favor");fflush(stdin);}
			if(b==-1){flag=-1;break;}
			min=min(a,b);
			max=max(a,b);
			float valor3=valorprimitivaenpunto(max,grado,ptrv)-valorprimitivaenpunto(min,grado,ptrv);
			printf("El valor de la integral es %.1f",valor3);
			break;
		default:
			puts("\nNo has escogido ningun caso bien, asegurate de escribir bien\n");
			goto elige;
	}
//switch finalizado, el programa ya esta entero con sus opciones
		if(flag==-1)break;
//si en algun momento escribieron -1, entonces flag=-1 y justo arriba rompe el while(1)
	ejecucion++;
//el usuario quiere otro polinomio, repetir con este o salir?
	puts("\n\n\nAhora puedes \"Repetir\" para realizar otro calculo con el mismo polinomio, \"-1\" para salir y cualquier otra cosa para otro polinomio");
	char opcionfinal[15];
	opfinal: fflush(stdin);
	scanf("%10[^\n]",opcion);
			if(strcmp(opcion,"Repetir")==0){ejecuta(ejecucion);goto elige;}
			if(strcmp(opcion,"repetir")==0){ejecuta(ejecucion);goto elige;}
			if(strcmp(opcion,"repite")==0){ejecuta(ejecucion);goto elige;}
			if(strcmp(opcion,"-1")==0)break;
	free(ptrv);}//aqui termina el while(1), la forma de salir es con un break
puts("Gracias por usar nuestros programas");}

void identifica(void){
	puts("**Ángel del Pozo**");
	puts("*******53219******");
	puts("*Informatica,D102*");
}

void ejecuta(int ejecucion){
	puts("");
	  puts("***************");
	printf("*Ejecucion nª%i*\n",ejecucion);
	  puts("***************\n");}
	  
void deriva(int grado, int * ptrv){
	int contador=grado;
	do{
		if(contador==1){
			printf("%i*%ix^%i",contador,*(ptrv+contador),contador-1);
			break;}
		//el if me sirve para prevenir que en la ultima iteracion escriba el resultado con un + al final(probar borrando if{}
		printf("%i*%ix^%i + ",contador,*(ptrv+contador),contador-1);
		contador--;
	}while(contador>0);
}

void primitiva(int grado, int * ptrv){
	int contador=0;
	printf("c + ");
	do{
		if(contador==grado){
			printf("(1/%i)*%ix^%i",contador+1,*(ptrv+contador),contador+1);
			break;}
		//el if me sirve para prevenir que en la ultima iteracion escriba el resultado con un + al final(probar borrando if{}		
		printf("(1/%i)*%ix^%i + ",contador+1,*(ptrv+contador),contador+1);
		contador++;
	}while(contador<=grado);
}

int valorderivadaenpunto(int punto2,int grado,int * ptrv){
	int contador2=grado;
	int valor2=0;
	do{	
		valor2+=contador2*(*(ptrv+contador2))*pow(punto2,contador2-1);
		contador2--;
	}while(contador2>0);
	return valor2;}
	
float valorprimitivaenpunto(int punto, int grado, int * ptrv){
	int contador=0;
	float valor=0;
	do{
		valor+=((pow(contador+1,-1))*(*(ptrv+contador))*pow(punto,contador+1));
		contador++;
	}while(contador<=grado);
return valor;}
