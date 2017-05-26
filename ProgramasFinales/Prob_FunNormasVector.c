#include <stdio.h>

#include <math.h>

/****** Problema Norma de vectores **********/


void presentacion(void);
double Norma_2(double *, int);
double Norma_1(double *, int);
double Norma_inf(double *, int);
void Invierte(double *, int);
void Ordena(double *, int);

int main(void)
{
    char nom_fic[50];
    int DIM, chk;
    unsigned int i, j;
    double Norma, Aux;
      
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
        printf("\n\n Introduce la dimensi\242n del vector (Dim > 1) ->  ");
        chk = scanf("%i", &DIM); 
        while(getchar() != '\n');             
    } while(chk != 1 || DIM < 1 );  
    printf("\n\n");    

    
    // ***** Dimensionamiento dinámico del vector ********************  
    
    double Vector[DIM];
    
    //Inicialización
    for(i = 0; i < DIM; i++){
        Vector[i] = 0.;
    }
    
    
    // ******* Lectura de datos del vector *******
    
    printf("\n\n Introduce las componentes del vector: \n");
    for(i = 0; i < DIM; i++){
        printf("V[%d] = ", i+1);
        scanf("%lf", &Vector[i]);
        while(getchar() != '\n');
    }
    
    fprintf(fi, "El vector introducido  es: \n");
    for(i = 0; i < DIM; i++){
        fprintf(fi, "V[%i] = %.2f; ", i+1, Vector[i]);
    }
    fprintf(fi, "\n"); 
    
    Norma = Norma_2(Vector, DIM);
    fprintf(fi, "\n La norma 2 es: %.5f\n\n", Norma);
    
    Norma = Norma_1(Vector, DIM);
    fprintf(fi, "\n La norma 1 es: %.5f\n\n", Norma); 
    
    Norma = Norma_inf(Vector, DIM);
    fprintf(fi, "\n La norma infinito es: %.5f\n\n", Norma);   
    
    Invierte(Vector, DIM);
	fprintf(fi, "\n\n El vector invertido es: \n\n");     
    for(i=0; i < DIM; i++){
          fprintf(fi, " V[%d] = %.2f; ", i+1, Vector[i]);
    }
    
    Ordena(Vector, DIM);
	fprintf(fi, "\n\n El vector ordenado es: \n\n");     
    for(i=0; i < DIM; i++){
          fprintf(fi, " V[%d] = %.2f; ", i+1, Vector[i]);
    }    
    
    printf("\n\n\n El fichero de salida es %s \n", nom_fic);

         
    fclose(fi);
    
    return 0;
}
    
/********************************************/
void presentacion(void)
{
     printf("\n **** Apellidos: AAAAAAA \n");
     printf("\n **** Nombre: AAAAA\n");
     printf("\n **** Numero Mat: 111111\n");
     printf("\n ***************************\n\n");
}    

/******************************************************/
double Norma_2(double *a, int D)
{
    int i, j;
    double suma;
       
    for(i=0, suma = 0; i < D; i++){
            suma = suma + a[i]*a[i];
    }
    suma = sqrt(suma);

       
    return (suma);

}
/******************************************************/
double Norma_1(double *a, int D)
{
    int i;
    double suma;
       
    for(i=0, suma = 0; i < D; i++){
        suma = suma + fabs(a[i]);
    }
   
    return (suma);

}
/******************************************************/
double Norma_inf(double *a, int D)
{
    int i, j;
    double Max;
       
    for(i=0, Max = 0; i < D; i++){
        if ( Max < fabs(a[i]) ){
            Max = fabs(a[i]);
        }
    }
    
    return (Max);
}   
/******************************************************/    
void Invierte(double *a, int dim)
{
    double aux;
    int cont;
    int cota = dim-1;
            
    for(cont = 0; cont < cota; cont++, cota--){  
        aux = a[cont]; 
        a[cont] = a[cota];
        a[cota] = aux;
            
    } 
    
    return;
       
}
/******************************************************/    
void Ordena(double *a, int dim)
{
    double aux;
    int i, j;
            
    for(i = 0; i < dim; i++){  
        for(j = i + 1; j < dim; j++){
            if(a[j] < a[i]){
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            } //fin if
        } //fin for
   } //fin for 
   
   return;
               
}
