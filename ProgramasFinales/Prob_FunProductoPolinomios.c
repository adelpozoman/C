#include <stdio.h>


/****** Solución producto de polinomios **********/
// En este caso no se necesita la matriz y  se hace a través de una
// función.

void FunProdPol(double *, int, double *, int, double *);


int main(void)
{
    char nom_fic[50];
    int chk;
    int Grad1, Grad2, DIM1, DIM2, DIMp;
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
        printf("\n\n Introduce el grado del primer polinomio (Grad > 0) ->  ");
        chk = scanf("%i", &Grad1); 
        while(getchar() != '\n');             
    } while(chk != 1 || Grad1 < 1 );  
    printf("\n\n");
     
    do {
        printf("\n\n Introduce el grado del segundo polinomio (Grad > 0) ->  ");
        chk = scanf("%i", &Grad2); 
        while(getchar() != '\n');             
    } while(chk != 1 || Grad2 < 1 );  
    printf("\n\n");        
    // ***** Direccionamiento dinámico del vector ********************  
    
    DIM1 = Grad1 + 1;
    DIM2 = Grad2 + 1;
    DIMp = Grad1 + Grad2 + 1;
    double Pol1[DIM1], Pol2[DIM2], PolPro[DIMp];
    
    
    
    //Inicialización
    for(i = 0; i < DIM1; i++){
        Pol1[i] = 0.;
    }
    for(i = 0; i < DIM2; i++){
        Pol1[i] = 0.;
    }    
    
    for(i = 0; i < DIMp; i++){
        PolPro[i] = 0.;
    }            
    
    // ******* Lectura de datos del vector *******
    
    printf("\n\n Introduce los coeficientes del polinomio 1: \n");
    for(i = 0; i < DIM1; i++){
        printf("P1[%d] = ", i);
        scanf("%lf", &Pol1[i]);
        while(getchar() != '\n');
    } 
    
    printf("\n\n Introduce los coeficientes del polinomio 2: \n");
    for(i = 0; i < DIM2; i++){
        printf("P2[%d] = ", i);
        scanf("%lf", &Pol2[i]);
        while(getchar() != '\n');
    }
    
    fprintf(fi, "El Polinomio 1 es: \n");
    for(i = 0; i < DIM1; i++){
        fprintf(fi, "Pol1[%i] = %.3f; ", i, Pol1[i]);
    }
    fprintf(fi, "\n\n"); 
    
    
    fprintf(fi, "El Polinomio 2 es: \n");
    for(i = 0; i < DIM2; i++){
        fprintf(fi, "Pol2[%i] = %.3f; ", i, Pol2[i]);
    }
    fprintf(fi, "\n\n");   
    
    //Producto polinomios
    
    FunProdPol(Pol1, DIM1, Pol2, DIM2, PolPro);
    
        
    fprintf(fi, "El polinomio producto es : \n");
    for(i = 0; i < DIMp; i++){
        fprintf(fi, "PolPro[%i] = %.3f; \n", i, PolPro[i]);
    }
   
    
    printf("\n\n\n El fichero de salida es %s \n", nom_fic);
        
    fclose(fi);
    
    return 0;
}

void FunProdPol(double *P, int Dim1, double *Q, int Dim2, double *R)
{
    int i, j;
      
    

    for (i = 0; i < Dim1; i++){
        for(j = 0; j < Dim2; j++){
            R[i+j] = R[i+j] + P[i] * Q[j];
        }
    }  
   
    return;
}

