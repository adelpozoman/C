#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E74


main(){
	FILE* apuntador;
	apuntador= fopen("Identifica.txt","w");
	presentacion();
	presentacionenarchivo(apuntador);
return;}


presentacion(){
	puts("Matricula: 53219");
	puts("Nombre: �ngel");
	puts("Apellidos: del Pozo");}
	
	
presentacionenarchivo(FILE* apuntador){
	fprintf(apuntador,"53219\n");	
	fprintf(apuntador,"�ngel\n");
	fprintf(apuntador,"del Pozo\n");
	}


