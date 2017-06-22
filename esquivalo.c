#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
//el total es 24x80
#define LIM 2000
#define abs(a) a>0? a:-a
//juego esquivar bloques que vienen desde la izquierda

printr(int,int);
juego(int*,int,char*);

struct punto{
	int x;
	int y;
}J1,obstaculo[LIM];

int c;
char fecha[64];//donde se guarda la hora

main(){
	srand(time(NULL));
	int eleccion, dificultad, puntuacion, flag=1;
	char dificult[10];
	while(flag){
		printprincipal(&eleccion);
		switch(eleccion){
			case 1:
				elidificultad(&dificultad,dificult);
				juego(&puntuacion,dificultad, dificult);
				guardapuntuacion(puntuacion);
				break;
			case 2:
				puntuaciones();
				break;
			case 3:
				creditos();
				break;
			case 4:
				puts("Reiniciando ESQUIVALO");
				//fclose(fopen("scores.txt","w")); //solo borra el contenido, no el fichero
				int ret;
				ret = remove("scores.txt");
				if(ret == 0){
					printf("Reinicio con éxito");}
				else{
					printf("Reinicio sin exito, prueba vovler a ejecutar y luego reinicia");}
				sleep(2);fflush(stdout);
				break;
				case 0:
				flag=0;
		}
	}puts("Gracias por jugar");
return 0;}

//ahorra puts("")para saltar x lineas;
p(int veces){
	do{	puts("");
		veces--;
	}while(veces>0);}

//limpia la pantalla y busca la fecha
limpia(){
	system("cls");//win
	//system("clear");//linux
	//clrscr();	//conio.h
	time_t t = time(NULL);
  	struct tm *tm = localtime(&t);
    	strftime(fecha, sizeof(fecha), "%c", tm);
}

//genera una letra aleatoria
letraaleatoria(){return ((rand()%(128))+33);}

//imprime renglon horizontal
printr(int caracter,int veces){
	for(c=0;c<veces;c++)printf("%c",caracter);}

//funcion escanear numero
scann(int* n){
	while(scanf("%i",n)!=1||getchar()!='\n'){
		puts("Se ha pedido un numero");
		while(getchar()!='\n');}
}

//funcion imprimir pantalla inicio
printprincipal(int* eleccion){
	limpia();
	char letra=letraaleatoria();
	printr(letra,80);
	printr(letra,80);
	for(c=0;c<55;c++)printf(" ");
	printf("%s",fecha);
	p(2);
	printr(32,29);
	puts("BIENVENIDO A ESQUIVALO");
	printr(32,5);
	puts("En este juego tienes que mover el bloque para esquivar las piedras");
	p(2);
	printr(32,29);
	puts("Selecciona una opcion");
	p(1);printr(32,36);printf("1: Jugar");
	p(2);printr(32,35);printf("2: Scores");
	p(2);printr(32,34);printf("3: Creditos");
	p(2);printr(32,34);printf("4: Reiniciar");
	p(2);printr(32,34);printf("0: Salir");p(3);
	printr(letra,80);
	printr(letra,80);
	int flageleccion=1;
	while(flageleccion){
		scann(eleccion);
		if((*eleccion)>=0&&(*eleccion)<=4){
			flageleccion=0;
		}
	}
}

//elie la dificultad. copia la dificultad en un array para despues escribirla en la pantalla
elidificultad(int* dificultad,char dificult[10]){
	int flagdificultad=1;
	puts("Selecciona dificultad:");
	puts("1:Retrasado\t2:Normal\t3:Dificil\t4:Hardcore");
	while(flagdificultad){
		scann(dificultad);
		if((*dificultad)>=1&&(*dificultad)<=4){
			flagdificultad=0;}
		else puts("Dificultad incorrecta");
	}
	switch(*dificultad){
		case 1:
			strcpy(dificult,"Retrasado");
			break;
		case 2:
			strcpy(dificult,"Normal");
			break;
		case 3:
			strcpy(dificult,"Dificil");
			break;
		case 4:
			strcpy(dificult,"Hardcore");
			break;
	}
}	

//codigo de la pantalla del juego
juego(int* puntuacion,int dificultad, char dificult[10]){
	J1.x=1;
	J1.y=1;
	*puntuacion=1;
	int i,j,k, nobs=0, flagbloque;//nobs es el numero de obstaculos spawneados
	char letra=letraaleatoria();
	char letra2=letraaleatoria();
	while(choque(nobs)!=1){//codigo del juego, se ejecuta hasta que el usuario se choca
		limpia();
		printf("Dificultad: %s",dificult);printr(32,16);printf("Puntuación:%i",*puntuacion);printr(32,12);printf("%s",fecha);
		p(1);printr(32,36);printf("ESQUIVALO");
		printf("\nMueve la X usando la W, A, S, D, minusculas o mayusculas\n");
		printr(letra,80);
		printr(letra,80);
		creabloques(dificultad,&nobs);
		i=0,j=0;
//imprime el tablero, los espacios, el jugador en su posicion y los bloques donde haya
		do{
			printr(32,1);
			j=0;
			do{
				flagbloque=0;
				k=0;			
				do{
					if((obstaculo[k].x==j)&&(obstaculo[k].y==i)){
						printf("$");
						flagbloque=1;
						break;}
					k++;
				}while(k<nobs);
				if(J1.x==j&&J1.y==i)printf("%c",letra2);
				else if(flagbloque!=1)printr(32,1);
				j++;
			}while(j<77);
			p(1);
			i++;
		}while(i<16);
		fflush(stdin);
		printr(letra,80);
		printr(letra,80);
		*puntuacion=*puntuacion+(dificultad*3);
		j1movement();
		muevebloques(nobs);
	}
	puts("GAME OVER");
	puts("Wait for score screen");
	sleep(4);fflush(stdin);fflush(stdout);
	
}

//funcion comprobar si se ha chocado el usuario con algun obstaculo
choque(int nobs){
	int i=0,j,k;
	do{
		j=0;
		do{
			k=0;
			do{	//puts("estoy comprobando");

				if((J1.x==obstaculo[k].x)&&(J1.y==obstaculo[k].y)){
					return 1;}
				k++;
			}while(k<nobs);
			j++;
		}while(j<77);//anchotablero
		i++;
	}while(i<15);//largotablero
return 0;}

//crea nuevos bloques a la izquierda del tablero, el numero sera dos veces la dificultad
creabloques(int dificultad, int* nobs){
	int cuenta=0;
	do{
		obstaculo[(*nobs)+cuenta].x=77;
		obstaculo[(*nobs)+cuenta].y=(rand()%16);
//si hay dos obstaculos en la misma posicion que le den
		cuenta++;
	}while(cuenta<(dificultad*2));
	(*nobs)+=(dificultad*2);
}

//vamos a escanear a donde se va a mover J1 con wasd
j1movement(){
	int flagmovimientoinvalido=1;
	char movimiento;
	int ax=0, ay=0;
	while(flagmovimientoinvalido){
		movimiento=getch();
		switch(movimiento){
			case 'a':
				flagmovimientoinvalido=0;
				ax=-1;
				break;
			case 'A':
				flagmovimientoinvalido=0;
				ax=-1;
				break;
			case 'w':
				flagmovimientoinvalido=0;
				ay=-1;
				break;
			case 'W':
				flagmovimientoinvalido=0;
				ay=-1;
				break;
			case 's':
				flagmovimientoinvalido=0;
				ay=1;
				break;
			case 'S':
				flagmovimientoinvalido=0;
				ay=1;
				break;
			case 'd':
				flagmovimientoinvalido=0;
				ax=1;
				break;
			case 'D':
				flagmovimientoinvalido=0;
				ax=1;
				break;
			default:
				flagmovimientoinvalido=1;
				break;
		}//fin del switch
		J1.x+=ax;
		J1.y+=ay;
		limitemovimiento();

	}//fin del while
	puts("movimiento valido registrado con exito");
}

//comprueba si J1 se ha salido del tablero de 78x16(va de 0,0 a 77,15
limitemovimiento(){
	if(J1.x<0)J1.x=0;
	if(J1.x>77)J1.x=77;
	if(J1.y<0)J1.y=0;
	if(J1.y>15)J1.y=15;}

//mira si en una posicion hay un bloque, si lo hay lo mueve a la izquierda
muevebloques(int nobs){
	int i=0,j=0,k=0;
	do{
		j=0;
		do{
			k=0;
			do{
				if((obstaculo[k].x==j)&&(obstaculo[k].y==i)){
					obstaculo[k].x-=1;}			
				k++;
			}while(k<nobs);
			j++;
		}while(j<78);
		i++;
	}while(i<16);
puts("bloques movidos con exito");
}

//guarda la puntuacion que has conseguido
guardapuntuacion(int score){
	limpia();
	char letra=letraaleatoria();
	printr(letra,80);
	printr(letra,80);
	for(c=0;c<55;c++)printf(" ");
	printf("%s",fecha);
	p(2);
	printr(32,36);
	puts("ESQUIVALO");
	printr(32,18);
	puts("Escribe tu nombre para guardar tu puntuacion");
	char usuario[35];
	scanf("%[^\n]",usuario);
	
	FILE* ptr;
	if(fopen("scores.txt","r")==NULL){
		ptr=fopen("scores.txt","w");
		fprintf(ptr,"SCORE\tDATE\tUSER\n");
		fclose(ptr);}
	ptr=fopen("scores.txt","a");
	fprintf(ptr,"%i\t%s\t",score,fecha);fputs(usuario,ptr);
	fputs("\n",ptr);
	fclose(ptr);
}

//imprimir las puntuaciones guardadas
puntuaciones(){
	limpia();
	char letra=letraaleatoria();
	printr(letra,80);
	printr(letra,80);
	for(c=0;c<55;c++)printf(" ");
	printf("%s",fecha);
	p(2);
	printr(32,29);
	puts("BIENVENIDO A ESQUIVALO");
	printr(32,27);
	puts("Puntuaciones  encontradas:");
	if(fopen("scores.txt","r")==NULL){
		p(3);
		printr(32,15);	
		puts("Todavía no hay ninguna puntuacion, pruebe a jugar");
		p(10);
	}
	else{
		FILE* ptr;
		ptr=fopen("scores.txt","r");
		int contenido;
		while((contenido = fgetc(ptr)) != EOF)printf("%c",contenido);
		fclose(ptr);
		p(5);
	}
	puts("Para volver al menu principal pulse cualquier tecla");
	printr(letra,80);
	printr(letra,80);
	char tecla;
	tecla=getch();
}

//imprime la pantalla de creditos
creditos(){
	limpia();
	char letra=letraaleatoria();
	printr(letra,80);
	printr(letra,80);
	for(c=0;c<55;c++)printf(" ");
	printf("%s",fecha);
	p(2);
	printr(32,36);
	puts("ESQUIVALO");
	printr(32,29);
	puts("Créditos de producción");
	p(2);printr(32,31);puts("Autor: adelpozoman");
	p(1);printr(32,29);puts("Contacto: adelpozoman@gmail.com");
	p(1);printr(32,33);puts("Entorno usado:");
	printr(32,15);puts("Texto: nano (Linux), gedit (Linux), DEV-C++(Windows)");
	printr(32,24);puts("Compiladores: gcc 4.4.3 - Mingw");
	p(6);
	printr(letra,80);
	printr(letra,80);
	char tecla;
	tecla=getch();
}
