#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****** Solución Problema traza con componente desviatoria **********/


void MatSimAl(FILE *, int, double (* )[]);
double Traza(int, int, double (* )[]);
void MatDesv(FILE *, int , double (* )[]);


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
    
    // **** Entrada de datos ************   
    do {
        printf("\n\n Introduce el tamaño de la matriz ( > 1) ->  ");
        chk = scanf("%i", &DIM); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM < 2 );  
    printf("\n\n");
    

  // ***** Dimensionamiento de la matriz ********************  
    
    double MatS[DIM][DIM];

    // *** Obtención de las compontes aleatorios ****
    
    MatSimAl(fi, DIM, MatS);
    
    fprintf(fi, "\n");
    fprintf(fi, "La matriz aleatoria simétrica es: \n");
    for(i=0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            fprintf(fi, " %5.2f; ", MatS[i][j]);
        }
        fprintf(fi, "\n");
    }
    fprintf(fi, "\n\n");
    
    // **** Componente desviatoria
    
    MatDesv(fi, DIM, MatS);
    
    fprintf(fi, "La componente desviatoria  es: \n");
    for(i=0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            fprintf(fi, " %5.2f; ", MatS[i][j]);
        }
        fprintf(fi, "\n");
    }
    fprintf(fi, "\n\n");
    


    
    printf("\n\n\n El fichero de salida es %s \n", nom_fic);
        
    fclose(fi);
    
    return 0;
}

void MatSimAl(FILE *fo, int Dim,  double (* Mat)[Dim]){
    
    int M, N, Semilla;
    int i, j, aux, chk;
    double numero;
    
    printf("Se genera una matriz simétrica de números aleatorios de tamaño %i x %i\n\n", Dim, Dim);
    fprintf(fo, "Se genera una matriz  de números aleatorios de tamaño %i x %i \n\n", Dim, Dim);
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
    
    for (i = 0; i < Dim; i++){
        for(j = i+1; j < Dim; j++){
            //numero = ( (double)rand() )/RAND_MAX;
            //numero = numero * (N-M) + M;
            //Mat[i][j] = numero;         
           Mat[i][j] = rand() % (N-M + 1) + M;  
           Mat[j][i] = Mat[i][j];
        }
    }
    for (i = 0; i < Dim; i++){
        //numero = (double) rand()/RAND_MAX;
        //numero = numero * (N-M) + M;
        //Mat[i][i] = numero;              
        Mat[i][i] =  rand() % (N-M + 1) + M;
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
    
    for (i = 0, tr = 0.; i < K; i++){
        tr = tr + Mat[i][i];
    }
    
    return (tr);
}

void MatDesv(FILE * fo, int Dim, double (* Mat)[Dim])
{
    int i; 
    double Valor;
    
    Valor = ( 1./Dim ) * Traza(Dim, Dim, Mat);

    
    for(i = 0; i < Dim; i++){
        Mat[i][i] = Mat[i][i] - Valor;
    }
    
    return;
    
}
