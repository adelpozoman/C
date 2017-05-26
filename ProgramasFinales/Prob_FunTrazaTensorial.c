#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****** Solución Prueba 2 A (M106) **********/



void VectorAleatorio(FILE *, double*, int);
void ProdTensorial(FILE *, double *, int, double *, int, double (* )[]);
double Traza(int, int, double (* )[]);


int main(void)
{
    char nom_fic[50];
    int chk;
    int DIM;
    unsigned int i, j;
    double Valor;
      
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
        printf("\n\n Introduce la cantidad de n\243meros a generar ( > 0) ->  ");
        chk = scanf("%i", &DIM); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM < 1 );  
    printf("\n\n");
    
    // ***** Direccionamiento dinámico del vector aleatorio ********************  
    double Vector[DIM];
    
    // *** Obtención de los valores aleatorios ****
    VectorAleatorio(fi, Vector, DIM);
    
    fprintf(fi, "El vector aletorio es de tamaño %i con valores: \n", DIM);
    printf("El vector aletorio es de tamaño %i con valores: \n", DIM);
    for(i = 0; i < DIM; i++){
        fprintf(fi, "%8.5f; ", Vector[i]);
    }
    fprintf(fi,"\n");

    
    // ***** Direccionamiento dinámico de la matriz ********************  
    double MatDiac[DIM][DIM];

    
    //Producto diadico
     
    ProdTensorial(fi, Vector, DIM, Vector, DIM, MatDiac); 
    
    fprintf(fi, "La matriz del producto diádico es: \n");
    for(i=0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            fprintf(fi, " %8.5f; ", MatDiac[i][j]);
        }
        fprintf(fi, "\n");
    }
    fprintf(fi, "\n\n");  
    
    //Traza
    
    Valor = Traza(DIM, DIM, MatDiac);
    
    fprintf(fi, "El valor de la traza es %.5f", Valor);
    
    printf("\n\n\n El fichero de salida es %s \n", nom_fic);
        
    fclose(fi);
    
    return 0;
}


void ProdTensorial(FILE *fo, double *V1, int Dim1, double *V2, int Dim2, double (* Mat)[Dim2])
{
    int i, j;
    
    
    for (i = 0; i < Dim1; i++){
        for(j = 0; j < Dim2; j++){
            Mat[i][j] = V1[i]*V2[j];
        }
        fprintf(fo,"\n");
    }
    fprintf(fo,"\n\n");
    
    return;
}

void VectorAleatorio(FILE *fo, double *P, int Dim){
    
    int M, N, Semilla;
    int cont, aux, chk;
    double numero;
    
    //printf("Se genera un vector de números aleatorios de tamaño %i \n\n", Dim);
    //fprintf(fo, "Se genera un vector de números aleatorios de tamaño %i \n\n", Dim);
	do{
	    printf("Introduce los extremos del intervalo (Enteros, por favor), en cuaquier orden-> ");
	    chk = scanf("%i %i", &M, &N);
	    while(getchar() != '\n');
    } while(chk != 2 || M == N);
    
    if (N < M) {
        aux = M;
        M = N;
        N = aux;
    }
    fprintf(fo, "El intervalo es [%i, %i]\n", M, N);

        
	do{
	    printf("Introduce la semilla -> ");
	    chk = scanf("%i", &Semilla);
	    while(getchar() != '\n');
    } while(chk != 1);  
        
    fprintf(fo, "La semilla es %i \n", Semilla);
    //srand ( time(NULL) );
    srand ( Semilla );    
    
    for (cont = 0; cont < Dim; cont++){
        
    	numero = (double)rand()/RAND_MAX;
        P[cont] = numero * (N-M) +  M;// rand() % (b - a + 1) + a
        //P[cont] = rand() % (N-M + 1) + M;
        
       //P[cont-1] = rand() % (N-M + 1) + M; // rand() % (b - a + 1) + a

    }
    
    return;
    
}

double Traza(int F, int C,  double (* Mat)[C])
{
    int i;
    int K;
    double tr;
    
    
    K = (F > C) ? C : F;
    /*K = F;
    if (C < F){
        K = C;
    }*/
    
    for (i = 0, tr = 0; i < K; i++){
        tr = tr + Mat[i][i];
    }
    
    return (tr);
}


