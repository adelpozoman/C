#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//ejercicio 58

int main(){
	puts("Vamos a escribir una matriz, dime las filas");
	int m,n;
	scanf("%i",&m);
	puts("Ahora dime las columnas");
	scanf("%i",&n);
	puts("Ahora me vas a ir diciendo los valores de la matriz separados, y fila a fila. Luego te diré la traspuesta");
	int matriz1[m][n], matriz2[n][m];
	int m2=0, n2=0;
	do{	n2=0;
		do{
			scanf("%i",&matriz1[n2][m2]);
			n2++;
		}while(n2<n);
		m2++;
	}while(m2<m);
	
	puts("La matriz A:");
	m2=0;
	do{	n2=0;
		do{
			printf("%i\t",matriz1[n2][m2]);
			n2++;
		}while(n2<n);
		puts("");
		m2++;
	}while(m2<m);
	puts("\ntiene como traspuesta");
	n2=0;
	do{	m2=0;
		do{
			printf("%i\t",matriz1[n2][m2]);
			m2++;
		}while(m2<m);
		puts("");
		n2++;
	}while(n2<n);
return 0;}
//al final no he usado matriz2, pero bueno
