
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void identifica(void){
	puts("*****�ngel del Pozo*****");
	puts("**********53219*********");
	puts("*********Dise�o*********");
}
void inicia(void){
	puts("*****************");
	puts("*Nueva ejecucion*");
	puts("*****************");
}



int main(){
	identifica();
while(1){
	inicia();
	puts("Escribe la palabra que ser� el nombre del archivo");
	char palabra[50];
	scanf("%s",palabra);
	char nombre[strlen(palabra)+4];
	strcpy(nombre,palabra);
	strcat(nombre,".txt");
	FILE* apuntador;
	apuntador= fopen(nombre,"w");
	fputs("lacasa es verde y deflaksjdf�laskdjf�laskdjf",apuntador);
	fclose(apuntador);	
}return 0;}
