#include <stdio.h>
#include <math.h>

/* Problema de cálculo del PERÍMETRO de un polígono 
mediante una función */

typedef struct {
        double x;
        double y;
    } punto;

double Perimetro(punto *, int );

int main(void)
{ 
    
    double Per; 
    int NumVert, DIM;    
    
    char nom_fic[50];
    int chk, i;
    
    FILE *fi;
    
   
    do{ 
        printf("\n\n Introduzca el nombre del fichero -> ");
        gets(nom_fic);
        printf("\n\n El nombre introducido es: %s\n\n", nom_fic);
        if ((fi = fopen(nom_fic, "w")) == NULL){
            printf("*** ¡¡¡ OJO ERROR EN LA APERTURA DEL FICHERO !!!! ***\n\n");
        }
    } while(fi ==  NULL);
    
      
    // ******* Número de vértices *******
    
    do {
        printf("\n\n Introduce el n\243mero de v\202rtices (> 1)->  ");
        chk = scanf("%i", &NumVert); 
        while(getchar() != '\n');             
    } while(chk != 1 || NumVert < 2 );  
    
    // ***** Dimensionamiento dinámico del vector que contiene los vértices ************
    DIM = NumVert + 1; // Hay que añadir un término más.
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
    Poligono[NumVert].x = Poligono[0].x; //Índices módulo n-1
    Poligono[NumVert].y = Poligono[0].y;      

    fprintf(fi, "Se ha introducido el polígono con vértices:\n");
    for(i = 0; i < NumVert; i++){
	    fprintf(fi, "X[%d] = %.2f  Y[%d] = %.2f \n", i+1, Poligono[i].x, i+1, Poligono[i].y);   
    }
    fprintf(fi, "\n\n");
    
    /***** CÁLCULO DEL PERÍMETRO **********/
    
    Per  = Perimetro(Poligono, NumVert);
      
    

      
    fprintf(fi, "El perímetro es %.5f\n", Per);
      
    fclose(fi);
      
    return 0;
} 

double Perimetro (punto *Vertices, int Dim){
    
    int i;
    double Valor = 0;
    
    for(i = 0; i < Dim ; i++){
        Valor = Valor + 
        sqrt( (Vertices[i+1].x - Vertices[i].x)*(Vertices[i+1].x - Vertices[i].x) 
              + (Vertices[i+1].y - Vertices[i].y)* (Vertices[i+1].y - Vertices[i].y) ); 
    }      
    
    return (Valor);
}
