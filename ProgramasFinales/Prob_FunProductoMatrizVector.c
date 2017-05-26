#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/****** Solución Problema producto matriz vector **********/


void Presentacion(FILE *); 
void VecMatInt(FILE *, int, double*, double (* )[]);
void Prod(int, double *, double (* )[], double *);

int main(void)
{
    char nom_fic[50];
    int chk;
    int DIM;
    unsigned int i, j;
      
    FILE *fi;
    
    do{ 
        printf("\n\n Introduce el nombre del fichero -> ");
        gets(nom_fic);
        printf("\n\n El nombre introducido es: %s\n\n", nom_fic);
        if ((fi = fopen(nom_fic, "w")) == NULL){
            printf("*** ¡¡¡ OJO ERROR EN LA APERTURA DEL FICHERO !!!! ***\n\n");
        }
    } while(fi ==  NULL);
    
    Presentacion(fi);
    
    // **** Entrada de datos ******
    do {
        printf("\n\n Introduce la dimension del vector y de la matriz ( > 0) ->  ");
        chk = scanf("%i", &DIM); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM < 1 );  
    printf("\n\n");
    
    double Vector[DIM], Matriz[DIM][DIM], VectorS[DIM];
    
    VecMatInt(fi, DIM, Vector, Matriz);
    
    fprintf(fi, "El vector aleatorio es de tamaño %i, con valores: \n", DIM);
    for(i = 0; i < DIM; i++){
        fprintf(fi, "%5.2f; ", Vector[i]);
    }
    fprintf(fi,"\n");    
    
    fprintf(fi, "\n");
    fprintf(fi, "La matriz aleatoria es: \n");
    for(i=0; i < DIM; i++){
        for(j = 0; j < DIM; j++){
            fprintf(fi, " %5.2f ", Matriz[i][j]);
        }
        fprintf(fi, "\n");
    }
    fprintf(fi, "\n\n");    
    
    Prod(DIM, Vector, Matriz, VectorS);
    
    fprintf(fi, "El vector producto es: \n", DIM);
    for(i = 0; i < DIM; i++){
        fprintf(fi, "%5.2f; ", VectorS[i]);
    }
    fprintf(fi,"\n");        

    return 0;
    
}
    
void Presentacion (FILE *fo)
{
    fprintf(fo, "***** Salida de resultados *******\n\n");
    fprintf(fo, "**** Nombre: Jalslsl\n");
    fprintf(fo, "**** Apellidos: Kskdiekdkm Rosldoe\n");
    fprintf(fo, "**** Número de matrícula: 111111\n");
    fprintf(fo, "*********************************\n\n");
    fprintf(fo, "\n\n");
    
    
    return;
}
    
    
    
    
void VecMatInt(FILE *fo, int Dim, double *P, double (* Mat)[Dim]){
    
    int M, N, Semilla;
    int cont, aux, chk, i, j;
    double numero;
    
    //Se genera un vector y una matriz de números aletorios
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
        P[cont] = rand() % (N - M + 1) + M;
    }
    
    for (i = 0; i < Dim; i++){
        for(j = 0; j < Dim; j++){
           Mat[i][j] = rand() % (N - M + 1) + M;    
        }
    }    
    
    return;
}

void Prod(int Dim, double *Vect, double (* Mat)[Dim], double *VectS)
{
    
    int i, j;
    double Sum;
    
    for(i = 0; i < Dim; i++){
        for(j = 0, VectS[i] = 0.; j < Dim; j++){
            VectS[i] = VectS[i] + Mat[i][j]*Vect[j];
        }
        
    }
    
    return;
    
}
    
