#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MODULO(x,y) sqrt((x*x)+(y*y))
//ejercicio18

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
	int x,y;
	puts("Escribe las coordenadas cartesianas de un punto y te doy su distancia al origen");
	scanf("%d %d", &x, &y);
	printf("El punto de coordenadas %d %d tiene una distancia al origen de ", x, y);
	printf("%.2f", MODULO(x,y));
	
	
	return EXIT_SUCCESS;
}



