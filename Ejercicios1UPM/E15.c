
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
	puts("Introduce un valor C");
	int C;
	scanf("%d", &C);
	if(C!=0){
		printf("Has escrito un valor verdadero");
	}
	else{
		printf("Has escrito un valor falso");
	}
	return EXIT_SUCCESS;
	return 0;
	system("pause");
}

