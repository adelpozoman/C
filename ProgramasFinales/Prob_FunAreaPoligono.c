#include <stdio.h>
#include <math.h>

/* Problema de c�lculo del �REA de un pol�gono 
mediante una funci�n*/

typedef struct {
        double x;
        double y;
    } punto;
    
double Area(punto *, int );

int main(void)
{ 

    
    double AreaPol; 
    int NumVert, DIM;    
    
    char nom_fic[50];
    int chk, i;
    
    FILE *fi;
    
   
    do{ 
        printf("\n\n Introduzca el nombre del fichero -> ");
        gets(nom_fic);
        printf("\n\n El nombre introducido es: %s\n\n", nom_fic);
        if ((fi = fopen(nom_fic, "w")) == NULL){
            printf("*** ��� OJO ERROR EN LA APERTURA DEL FICHERO !!!! ***\n\n");
        }
    } while(fi ==  NULL);
    
      
    // ******* N�mero de v�rtices *******
    
    do {
        printf("\n\n Introduce el n\243mero de v\202rtices (> 1)->  ");
        chk = scanf("%i", &NumVert); 
        while(getchar() != '\n');             
    } while(chk != 1 || NumVert < 2 );  
    
    // ***** Dimensionamiento din�mico del vector que contiene los v�rtices ************
    DIM = NumVert + 1; // Hay que a�adir un t�rmino m�s.
    punto Poligono[DIM];
    
    printf("\n\n");    
    printf("\n\n Introduce los v\202rtices del pol\241gono  \n");
    for(i = 0; i < NumVert; i++){
		printf("Introduce X[%d] = ", i+1);
        scanf("%lf", &Poligono[i].x); 
        while(getchar() != '\n');
		printf("Introduce Y[%d] = ", i+1);
        scanf("%lf", &Poligono[i].y); 
        while(getchar() != '\n');
        printf("\n\n");        
    }
    Poligono[NumVert].x = Poligono[0].x; //�ndices m�dulo n-1
    Poligono[NumVert].y = Poligono[0].y;      

    fprintf(fi, "Se ha introducido el pol�gono con v�rtices:\n");
    for(i = 0; i < NumVert; i++){
	    fprintf(fi, "X[%d] = %.2f  Y[%d] = %.2f \n", i+1, Poligono[i].x, i+1, Poligono[i].y);   
    }
    fprintf(fi, "\n\n");
      
    /**** C�lculo del �rea *********/
    
    AreaPol = Area(Poligono, NumVert);
    
    fprintf(fi, "El �rea del pol�gono introducido es: %.2f \n", AreaPol);
        
      
    fclose(fi);
      
    return 0;
} 

/****** Funci�n �rea del pol�gono ***********/

double Area(punto *a, int DIM)
{
       double resultado;
       int i;
       
       for(resultado = 0, i = 0; i < DIM; i++){
            resultado = resultado + ( (a[i].x * a[i+1].y) - (a[i+1].x * a[i].y) ) ;
       }   
       resultado = 0.5 * resultado;
       
       return (resultado);
}    
