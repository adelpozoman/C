#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
//E59

main(){
	puts("Te voy a multiplicar una matriz por otra.\nEl número de columnas de la primera ha de ser el mismo que el de filas de la segunda");
	int f1, c1f2, c2;
	//f1 numero filas de la primera
	//c2 numero de columnas de la segunda
	//c1f2 número de columnas de la primera o de filas de la segunda ( tienen que ser las mismas, carajote)
	printf("Numero de filas primera=");scanf("%i",&f1);
	printf("Número columnas primera o filas segunda=");scanf("%i",&c1f2);
	printf("Número de columnas segunda=");scanf("%i",&c2);
	int m1[f1][c1f2], m2[c1f2][c2], mresultado[f1][c2];
	puts("Ahora vas a rellenar las matrices, de izquierda a derecha fila por fila");
	int contadorancho, contadorlargo;
	contadorlargo=0;
	do{	contadorancho=0;
		do{	printf("m1[%i][%i]=",contadorlargo+1,contadorancho+1);
			scanf("%i",&m1[contadorlargo][contadorancho]);
			contadorancho++;
		}while(contadorancho<c1f2);
		contadorlargo++;
	}while(contadorlargo<f1);
	contadorlargo=0;
	do{	contadorancho=0;
		do{	printf("m2[%i][%i]=",contadorlargo+1,contadorancho+1);
			scanf("%i",&m2[contadorlargo][contadorancho]);
			contadorancho++;
		}while(contadorancho<c2);
		contadorlargo++;
	}while(contadorlargo<c1f2);
//PODRÍA HABER HECHO UN SOLO CICLO EN VEZ DE 2 Y HACER LAS DOS MATRICES, METIENDO EN SCANF UN PUNTERO QUE INDIQUE A UNA MARTRIZ EN EL PRIMER RECORRIEDO Y A LA OTRA EN EL SEGUNDO
//ahora las cuentas
	puts("El producto tiene como resultado:");
	int sum, contadormult;
	contadorlargo=0;
	do{
		contadorancho=0;
		do{
			contadormult=0;
			sum=0;
			do{
				sum=sum+((m1[contadorlargo][contadormult])*(m2[contadormult][contadorancho]));
				contadormult++;
			}while(contadormult<c1f2);
			mresultado[contadorlargo][contadorancho]=sum;
			contadorancho++;
		}while(contadorancho<c2);
		contadorlargo++;
	}while(contadorlargo<f1);
//hehco, solo queda imprimirla
	contadorlargo=0;
	do{	
		contadorancho=0;
		do{
			printf("%i\t",mresultado[contadorlargo][contadorancho]);
			contadorancho++;
		}while(contadorancho<c2);
		puts("");
		contadorlargo++;
	}while(contadorlargo<f1);
return 0;}
