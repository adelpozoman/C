 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//ejercicio 8

void Printf(const char *strText)
{
char ch;
short i,iLength;
iLength=strlen(strText);

for(i=0;i<iLength;i++){
ch=strText[i];
switch(ch){
case '�':
printf("\240");
break;
case '�':
printf("\202");
break;
case '�':
printf("\241");
break;
case '�':
printf("\242");
break;
case '�':
printf("\243");
break;
case '�':
printf("%c",-92);
break;
case '�':
printf("%c",-91);
break;
case '�':
printf("%c",-75);
break;
case '�':
printf("%c",-112);
break;
case '�':
printf("%c",-42);
break;
case '�':
printf("%c",-32);
break;
case '�':
printf("%c",-23);
break;
default:
printf("%c",ch);
break;

}
}
}


main(){
	int n, p;
	puts("Introduce un n�mero al n�mero al que lo quieres elevar");
	scanf("%d %d", &n, &p);
	printf("%d elevado a %d es ", n, p);
	
	int mult= 0;
	int resultado;
	int nresultado;
	
	do{
		mult++;
		resultado = n * nresultado;
		nresultado = resultado;
		
		
		
	}while(mult<p);
	printf("%d",nresultado);
		
	return EXIT_SUCCESS;
}
