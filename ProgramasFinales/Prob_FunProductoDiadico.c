#include <stdio.h>

/****** Solución PRODUCTO DIÁDICO **********/
// Se hace a través de una función.

void FunProdTesorial(double *, int, double *, int, double (* )[]);


int main(void)
{
    char nom_fic[50];
    int chk;
    int DIM1, DIM2;
    unsigned int i, j;
    double Aux;
      
    FILE *fi;
    
    do{ 
        printf("\n\n Introduce el nombre del fichero -> ");
        gets(nom_fic);
        printf("\n\n El nombre introducido es: %s\n\n", nom_fic);
        if ((fi = fopen(nom_fic, "w")) == NULL){
            printf("*** ¡¡¡ OJO ERROR EN LA APERTURA DEL FICHERO !!!! ***\n\n");
        }
    } while(fi ==  NULL);
    
    // **** Entrada de datos ******
    do {
        printf("\n\n Introduce la dimensión del primer vector (Dim > 1) ->  ");
        chk = scanf("%i", &DIM1); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM1 < 2 );  
    printf("\n\n");
     
    do {
        printf("\n\n Introduce la dimensión del segundo vector (Dim > 1) ->  ");
        chk = scanf("%i", &DIM2); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM2 < 2 );  
    printf("\n\n");        
    // ***** Direccionamiento dinámico del vector ********************  
    
    double Vector1[DIM1], Vector2[DIM2], MatDiac[DIM1][DIM2];
    
    //Inicialización
    for(i = 0; i < DIM1; i++){
        Vector1[i] = 0.;
    }
    for(i = 0; i < DIM2; i++){
        Vector2[i] = 0.;
    }    
    
    
    // ******* Lectura de datos del vector *******
    
    printf("\n\n Introduce las componentes del vector 1: \n");
    for(i = 0; i < DIM1; i++){
        printf("V1[%d] = ", i+1);
        scanf("%lf", &Vector1[i]);
        while(getchar() != '\n');
    }
    
    printf("\n\n Introduce las componentes del vector 2: \n");
    for(i = 0; i < DIM2; i++){
        printf("V2[%d] = ", i+1);
        scanf("%lf", &Vector2[i]);
        while(getchar() != '\n');
    }
    fprintf(fi, "El vector 1 es: \n");
    for(i = 0; i < DIM1; i++){
        fprintf(fi, "V1[%i] = %.3f; ", i+1, Vector1[i]);
    }
    fprintf(fi, "\n\n"); 
    
    
    fprintf(fi, "El vector 2 es: \n");
    for(i = 0; i < DIM2; i++){
        fprintf(fi, "V2[%i] = %.3f; ", i+1, Vector2[i]);
    }
    fprintf(fi, "\n\n");  
    
    //Producto diadico
     
    FunProdTesorial(Vector1, DIM1, Vector2, DIM2, MatDiac); 
    
    fprintf(fi, "La matriz del producto diádico es: \n");
    for(i=0; i < DIM1; i++){
        for(j = 0; j < DIM2; j++){
            fprintf(fi, " A[%d][%d] = %.4f; ", i+1, j+1, MatDiac[i][j]);
        }
        fprintf(fi, "\n");
    }
    fprintf(fi, "\n");    
   
    
    printf("\n\n\n El fichero de salida es %s \n", nom_fic);
        
    fclose(fi);
    
    return 0;
}


void FunProdTesorial(double *V1, int Dim1, double *V2, int Dim2, double (* Mat)[Dim2])
{
    int i, j;
    
    
    for (i = 0; i < Dim1; i++){
        for(j = 0; j < Dim2; j++){
            Mat[i][j] = V1[i]*V2[j];
        }
    }
    
    return;
}
