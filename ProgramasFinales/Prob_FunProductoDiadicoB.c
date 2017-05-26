#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****** Solución PRODUCTO DIÁDICO **********/
// Se hace a través de una función.
//los vectores se construyen a través de números aleatorios


void vector_a(FILE *, double*, int);
void FunProdTesorial(FILE *, double *, int, double *, int, double (* )[]);


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
    // ***** Direccionamiento dinámico del vector 1 ********************  
    double Vector1[DIM1];
    
    vector_a(fi, Vector1, DIM1);
    
    
    fprintf(fi, "El vector 1 es: \n");
    for(i = 0; i < DIM1; i++){
        fprintf(fi, "V1[%i] = %.3f; ", i+1, Vector1[i]);
    }
    fprintf(fi, "\n\n"); 
    
     
    do {
        printf("\n\n Introduce la dimensión del segundo vector (Dim > 1) ->  ");
        chk = scanf("%i", &DIM2); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM2 < 2 );  
    printf("\n\n");        
    // ***** Direccionamiento dinámico del vector2 ********************  
    
    double Vector2[DIM2];
    vector_a(fi, Vector2, DIM2);
    
    fprintf(fi, "El vector 2 es: \n");
    for(i = 0; i < DIM2; i++){
        fprintf(fi, "V2[%i] = %.3f; ", i+1, Vector2[i]);
    }
    fprintf(fi, "\n\n");  
    
    // ***** Direccionamiento dinámico de la matriz ********************  
    double MatDiac[DIM1][DIM2];

  
    //Producto diadico
     
    FunProdTesorial(fi, Vector1, DIM1, Vector2, DIM2, MatDiac); 
    
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


void FunProdTesorial(FILE *fo, double *V1, int Dim1, double *V2, int Dim2, double (* Mat)[Dim2])
{
    int i, j;
    
    
    for (i = 0; i < Dim1; i++){
        for(j = 0; j < Dim2; j++){
            Mat[i][j] = V1[i]*V2[j];
        }
    }
    
    return;
}

void vector_a(FILE *fo, double *P, int Dim){
    
    int Semilla;
    int cont, chk;
    float M, N;
    //double numero;
    double Aux;
    
    //printf("Se genera un vector de números aleatorios de tamaño %i \n\n", Dim);
    //fprintf(fo, "Se genera un vector de números aleatorios de tamaño %i \n\n", Dim);
	do{
	    printf("Introduce los extremos del intervalo (Enteros, por favor), en cuaquier orden-> ");
	    chk = scanf("%f %f", &M, &N);
	    while(getchar() != '\n');
    } while(chk != 2 || M == N);
    
    if (N < M) {
        Aux = M;
        M = N;
        N = Aux;
    }
    fprintf(fo, "El intervalo es [%.2f, %.2f]\n", M, N);

        
	do{
	    printf("Introduce la semilla -> ");
	    chk = scanf("%i", &Semilla);
	    while(getchar() != '\n');
    } while(chk != 1);  
        
    fprintf(fo, "La semilla es %i \n", Semilla);
    //srand ( time(NULL) );
    srand ( Semilla );    
    
    for (cont = 0; cont < Dim; cont++){
        
    	Aux = (double)rand()/RAND_MAX;
    	Aux  = Aux * (N-M) +  M;
        P[cont] = Aux; // rand() % (b - a + 1) + a
        
       /*P[cont-1] = rand() % (N-M + 1) + M; // rand() % (b - a + 1) + a*/

       //fprintf(fi, "%i ", numero);
    }
    
 
    return;
    
}
