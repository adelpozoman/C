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
case 'á':
printf("\240");
break;
case 'é':
printf("\202");
break;
case 'í':
printf("\241");
break;
case 'ó':
printf("\242");
break;
case 'ú':
printf("\243");
break;
case 'ñ':
printf("%c",-92);
break;
case 'Ñ':
printf("%c",-91);
break;
case 'Á':
printf("%c",-75);
break;
case 'É':
printf("%c",-112);
break;
case 'Í':
printf("%c",-42);
break;
case 'Ó':
printf("%c",-32);
break;
case 'Ú':
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



