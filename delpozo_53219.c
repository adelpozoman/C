#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


identifica(){
	puts("\t***Nombre:Ángel del Pozo***");
	puts("\t***Grupo: D102***");
	puts("\t***Matrícula: 53219***");}
char c;

int main(){
	identifica();
	puts("Pulsa Ctrl + C para pausar la ejecucion");
	do{
	puts("\n*****Nueva ejecucion*****\n");
	puts("¿Cuál es el lado que quieres que tenga tu figura?");
	int l;
	while(scanf("%i",&l)!=1){puts("Puede ser que no hayas puesto un número");fflush(stdin);}
	fflush(stdin);
	puts("Dime qué carácter quieres que sea el que haga tu figura (1 solo)");
	while(scanf("%c",&c)!=1){printf("La entrada no ha sido correcta");fflush(stdin);}
	puts("Vamos a elegir entre dibujar un tríangulo o un rectángulo");
	puts("Para rectangulo escribe \"Rectangulo\" y para triangulo o pirámide \"Triangulo\"");
	char opcion1[30];fflush(stdin);
	gets(opcion1);
	if(strcmp(opcion1,"Triangulo")==0){puts("Triangulo");
		triangulo(l);}
	if(strcmp(opcion1,"Rectangulo")==0){puts("Rectangulo");
		rectangulo(l);}
	else if((strcmp(opcion1,"Rectangulo"))!=0&&(strcmp(opcion1,"Triangulo"))!=0){
	puts("No has escrito ni \"Triangulo\" ni \"Rectangulo\"");break;}
	}while(1);
	system("pause");}

rectangulo(int l){
	int contador1=0,contador2=0;
	do{	contador1=0;
		do{
			printf("%c",c);
			contador1++;
		}while(contador1<l);
	puts("");
	contador2++;
	}while(contador2<l);
}


triangulo(l){
	puts("Me vas a decir la orientación que quieres que tenga el ángulo recto tu triángulo");
	puts("1:Arriba izquierda\t2:Abajo izquierda\t3:Pirámide");
	int orientacion;
	fflush(stdin);
	orientar:
	while(scanf("%i",&orientacion)!=1){puts("No has escrito un numero");fflush(stdin);}
	if(orientacion<0||orientacion>3){puts("No has elegido ninguna opcion de las que te he dado");goto orientar;}
	switch(orientacion){
		case 1:
			t1(l);
			break;			
		case 2:
			t2(l);
			break;
		case 3:
			t3(l);
			break;
	}
}


t1(int l){  
	int contador1=l,contador2=0;	
	do{ contador1=l-contador2;
		do{
			printf("%c",c);
			contador1--;
		}while(contador1>0);
		puts("");
		contador2++;
	}while(contador2<l);

}

t2(int l){
	int contador1=l,contador2=1;
	do{ contador1=0;
		do{
			printf("%c",c);
			contador1++;
		}while(contador1<contador2);
		puts("");
		contador2++;
	}while(contador2<=l);
}

t3(int l){
	int contador1,contadorimpreso,contadoralto=0;
	do{	contador1=0;
		contadorimpreso=0;
		do{
			printf(" ");
			
			contador1++;
		}while(contador1<l-contadoralto);
		//imprimimos los caracteres ahora
		do{	printf("%c",c);
			contadorimpreso++;
		}while(contadorimpreso<(contadoralto*2)+1);
		puts("");
		contadoralto++;
	}while(contadoralto<l);
}



	
	
	
	
